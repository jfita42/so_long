/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:16:45 by jfita             #+#    #+#             */
/*   Updated: 2024/04/02 15:30:03 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if map contains only the exepected elements, in the expected amount
void	map_check_elems(char const *str)
{
	if (count_char(str, 'E') != 1)
		check_report(ERR_E);
	else
		check_report(CHECK);
	if (count_char(str, 'P') != 1)
		check_report(ERR_S);
	else
		check_report(CHECK);
	if (count_char(str, 'C') <= 0)
		check_report(ERR_C);
	else
		check_report(CHECK);
	if (char_check(str) == 0)
		check_report(ERR_I);
	else
		check_report(CHECK);
	map_check_line(str);
}

// Checks if map contains empty lines
void	map_check_line(const char *str)
{
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
		{
			check_report(ERR_L);
			return ;
		}
		str++;
	}
	check_report(CHECK);
}

// Checks if map is surrounded by walls
void	map_check_walls(const t_map *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < map->height)
	{
		j = 0;
		if (!i || i == map->height - 1)
		{
			while (j < map->width && map->tab_map[i][j])
			{
				if (map->tab_map[i][j] != '1')
					return (check_report(ERR_W));
				j++;
			}
		}
		else if (map->tab_map[i][0] != '1' || map->tab_map[i][map->width
			- 1] != '1')
			return (check_report(ERR_W));
	}
	check_report(CHECK);
}

// Checks if map is rectangle
void	map_check_dims(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->tab_map[i]) != map->width)
		{
			check_report(ERR_R);
			return ;
		}
		i++;
	}
	check_report(CHECK);
}

// Checks if extension is of expected type
void	map_check_filetype(const t_map *map)
{
	size_t	len;

	len = ft_strlen(map->filename);
	if (len < 4 || map->filename[len - 4] != '.' || map->filename[len
			- 3] != 'b' || map->filename[len - 2] != 'e' || map->filename[len
			- 1] != 'r')
		err_terminate(MAP_CRITERR1);
}
