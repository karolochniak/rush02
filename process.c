/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:30:00 by kochniak          #+#    #+#             */
/*   Updated: 2025/07/13 14:55:59 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "number_to_words.h"

void	process1(char fi, t_dict_entry *dict, int dict_size)
{
	present(fi, 0, dict, dict_size);
}

void	process2(char se, char fi, t_dict_entry *dict, int dict_size)
{
	if (se == '0')
	{
		if (fi != '0')
			process1(fi, dict, dict_size);
		return ;
	}
	if (partial_present(se, fi, dict, dict_size))
		return ;
	present(se, 1, dict, dict_size);
	if (fi != '0')
		process1(fi, dict, dict_size);
}

void	process3(char *chars, t_dict_entry *dict, int dict_size)
{
	if (chars[0] != '0')
	{
		present(chars[0], 0, dict, dict_size);
		present('1', 2, dict, dict_size);
	}
	if (chars[1] != '0' || chars[2] != '0')
		process2(chars[1], chars[2], dict, dict_size);
}

int	partial_present(char se, char fi, t_dict_entry *dict, int dict_size)
{
	char	key[3];
	int		i;

	key[0] = se;
	key[1] = fi;
	key[2] = '\0';
	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
		{
			ft_putstr(dict[i].value);
			ft_putstr(" ");
			return (1);
		}
		i++;
	}
	return (0);
}
