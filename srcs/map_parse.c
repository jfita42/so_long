/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:18:52 by jfita             #+#    #+#             */
/*   Updated: 2024/04/02 15:24:18 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_and_check(t_data *data)
{
	map_get_elems(data->map);
	map_get_dims(data);
	check_terminate(data);
	map_get_pos(data->map, 'P');
	map_flood(data);
}

// Gets and checks EPCI
void	map_get_elems(t_map *map)
{
	map_check_elems(map->bigstr);
	map->nb_collect = count_char(map->bigstr, 'C');
	map->nb_spawn = count_char(map->bigstr, 'P');
	map->nb_exit = count_char(map->bigstr, 'E');
}

// Reads the file and makes it one big string
char	*read_map(int fd)
{
	int		readed;
	char	*line;
	char	*buffer;

	readed = 1;
	line = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFERSIZE + 1, (sizeof(char)));
	if (!buffer || !line)
		return (err_terminate("Malloc fail in read_map\n"), NULL);
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFERSIZE);
		if (readed == -1)
			return (free(buffer), free(line), NULL);
		if (readed == 0)
			return (free(buffer), close(fd), line);
		buffer[readed] = '\0';
		line = ft_strjoin_free(line, buffer);
	}
	close(fd);
	return (free(buffer), line);
}

// Gets and checks LRW.
void	map_get_dims(t_data *data)
{
	while (data->map->tab_map[data->map->height])
		data->map->height++;
	if (data->map->height > 0)
		data->map->width = ft_strlen(data->map->tab_map[0]);
	map_check_dims(data->map);
	check_terminate(data);
	map_check_walls(data->map);
}

// Gets the position of a char inside map->tab_map
void	map_get_pos(t_map *map, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tab_map[i][j] == c)
			{
				map->pos->x = j;
				map->pos->y = i;
				return ;
			}
			++j;
		}
		++i;
	}
}
