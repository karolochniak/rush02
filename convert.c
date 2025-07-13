/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:30:00 by kochniak          #+#    #+#             */
/*   Updated: 2025/07/13 15:05:22 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "number_to_words.h"

int	full_present(char *nmb, t_dict_entry *dict, int dict_size)
{
	int	i;

	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].key, nmb) == 0)
		{
			if (ft_strcmp(nmb, "100") == 0)
				ft_putstr("one ");
			ft_putstr(dict[i].value);
			ft_putstr("\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static void	process_offset_1(char *nmb, int size, t_dict_entry *dict,
		int dict_size)
{
	int	remaining;

	if (nmb[0] != '0')
	{
		process1(nmb[0], dict, dict_size);
		remaining = size - 1;
		if (remaining > 0)
			present('1', remaining, dict, dict_size);
	}
}

static void	process_offset_2(char *nmb, int size, t_dict_entry *dict,
		int dict_size)
{
	int	remaining;

	if (nmb[0] != '0' || nmb[1] != '0')
	{
		process2(nmb[0], nmb[1], dict, dict_size);
		remaining = size - 2;
		if (remaining > 0)
			present('1', remaining, dict, dict_size);
	}
}

static void	process_groups(t_process_data *data)
{
	int		i;
	int		remaining;
	char	chars[4];

	i = data->start;
	while (i < data->size)
	{
		if (data->nmb[i] != '0' || data->nmb[i + 1] != '0'
			|| data->nmb[i + 2] != '0')
		{
			chars[0] = data->nmb[i];
			chars[1] = data->nmb[i + 1];
			chars[2] = data->nmb[i + 2];
			chars[3] = '\0';
			process3(chars, data->dict, data->dict_size);
			remaining = data->size - i - 3;
			if (remaining > 0)
				present('1', remaining, data->dict, data->dict_size);
		}
		i += 3;
	}
}

void	convert_number_to_words(char *nmb, t_dict_entry *dict, int dict_size)
{
	t_process_data	data;

	data.size = 0;
	while (nmb[data.size])
		data.size++;
	if (full_present(nmb, dict, dict_size))
		return ;
	data.start = data.size % 3;
	if (data.start == 1)
		process_offset_1(nmb, data.size, dict, dict_size);
	else if (data.start == 2)
		process_offset_2(nmb, data.size, dict, dict_size);
	data.nmb = nmb;
	data.dict = dict;
	data.dict_size = dict_size;
	process_groups(&data);
	ft_putstr("\n");
}
