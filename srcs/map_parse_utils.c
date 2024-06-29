/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:16:23 by jfita             #+#    #+#             */
/*   Updated: 2024/02/16 14:21:41 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if there is any forbidden char inside the big string
// Used by map_check_elems();
int	char_check(char const *str)
{
	while (*str)
	{
		if (*str != 'E' && *str != 'P' && *str != 'C' && *str != '1'
			&& *str != '0' && *str != '\n')
			return (0);
		str++;
	}
	return (1);
}

// Classic count char, used by map_check_elems();
int	count_char(char const *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	if (*str == c)
		i++;
	return (i);
}
