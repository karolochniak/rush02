/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:30:00 by kochniak          #+#    #+#             */
/*   Updated: 2025/07/13 14:53:07 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "number_to_words.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	find_start(char *str)
{
	int	start;

	start = 0;
	while (str[start] && (str[start] == ' ' || str[start] == '\t'
			|| str[start] == '\n'))
		start++;
	return (start);
}

static int	find_end(char *str, int start)
{
	int	end;

	end = ft_strlen(str) - 1;
	while (end >= start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n'))
		end--;
	return (end);
}

char	*ft_strtrim(char *str)
{
	int		start;
	int		end;
	int		len;
	char	*trimmed;
	int		i;

	start = find_start(str);
	end = find_end(str, start);
	len = end - start + 1;
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i < len)
	{
		trimmed[i] = str[start + i];
		i++;
	}
	trimmed[len] = '\0';
	return (trimmed);
}

char	*ft_split_once(char *str, char sep)
{
	int		i;
	char	*new_str;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	if (str[i] == '\0')
		return (ft_strdup(str));
	new_str = malloc(i + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_str[j] = str[j];
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
