/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:23:37 by kochniak          #+#    #+#             */
/*   Updated: 2025/07/13 15:06:41 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "number_to_words.h"

t_dict_entry	*g_dict;
int				g_dict_size;

int	main(void)
{
	char	*nmb;

	g_dict = malloc(sizeof(t_dict_entry) * MAX_DICT_SIZE);
	if (!g_dict)
		return (1);
	g_dict_size = load_dict(g_dict, "numbers.dict");
	if (g_dict_size == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	nmb = "1234";
	convert_number_to_words(nmb, g_dict, g_dict_size);
	free_dict(g_dict, g_dict_size);
	free(g_dict);
	return (0);
}
