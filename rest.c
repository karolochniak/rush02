/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrackow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:02:44 by mfrackow          #+#    #+#             */
/*   Updated: 2025/07/13 21:02:48 by mfrackow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "number_to_words.h"

void	build_power_key(char *key, int index)
{
	int	j;
	int	len;

	key[0] = '1';
	key[1] = '\0';
	j = 0;
	while (j < index)
	{
		len = ft_strlen(key);
		key[len] = '0';
		key[len + 1] = '\0';
		j++;
	}
}

int	correct_nmb(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (n[i] > '9' || n[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

char	*find_in_dict(char *key)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_dict_size)
	{
		if (ft_strlen(g_dict[i].key) == ft_strlen(key))
		{
			j = 0;
			while (g_dict[i].key[j] && g_dict[i].key[j] == key[j])
				j++;
			if (g_dict[i].key[j] == '\0')
				return (g_dict[i].value);
		}
		i++;
	}
	return (NULL);
}

void	free_dict(t_dict_entry *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
}
