/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:30:00 by kochniak          #+#    #+#             */
/*   Updated: 2025/07/13 15:01:40 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "number_to_words.h"

static void	present_digit(char fi, t_dict_entry *dict, int dict_size)
{
	char	key[2];
	int		i;

	if (fi != '0')
	{
		key[0] = fi;
		key[1] = '\0';
		i = 0;
		while (i < dict_size)
		{
			if (ft_strcmp(dict[i].key, key) == 0)
			{
				ft_putstr(dict[i].value);
				ft_putstr(" ");
				return ;
			}
			i++;
		}
	}
}

static void	present_tens(char fi, t_dict_entry *dict, int dict_size)
{
	char	key[3];
	int		i;

	if (fi != '0')
	{
		key[0] = fi;
		key[1] = '0';
		key[2] = '\0';
		i = 0;
		while (i < dict_size)
		{
			if (ft_strcmp(dict[i].key, key) == 0)
			{
				ft_putstr(dict[i].value);
				ft_putstr(" ");
				return ;
			}
			i++;
		}
	}
}

static void	present_power(int index, t_dict_entry *dict, int dict_size)
{
	char	key[50];
	int		i;

	build_power_key(key, index);
	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
		{
			ft_putstr(dict[i].value);
			ft_putstr(" ");
			return ;
		}
		i++;
	}
}

static void	present_hundred(t_dict_entry *dict, int dict_size)
{
	int	i;

	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].key, "100") == 0)
		{
			ft_putstr(dict[i].value);
			ft_putstr(" ");
			return ;
		}
		i++;
	}
}

void	present(char fi, int index, t_dict_entry *dict, int dict_size)
{
	if (index == 0)
		present_digit(fi, dict, dict_size);
	else if (index == 1)
		present_tens(fi, dict, dict_size);
	else if (index == 2)
		present_hundred(dict, dict_size);
	else
		present_power(index, dict, dict_size);
}
