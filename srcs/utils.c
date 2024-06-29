/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:20:24 by jfita             #+#    #+#             */
/*   Updated: 2024/03/20 22:38:22 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rand(void)
{
	int		fd;
	char	buf[1];

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0 || read(fd, buf, 1) < 0)
		return ((void)close(fd), -1);
	close(fd);
	return (buf[0]);
}

int	ft_range_rand(int max)
{
	int	r;

	r = ft_rand() % max;
	if (r < 0)
		r = -r;
	return (r);
}

void	init_pos(t_data *data, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->tab_map[i][j] == c)
			{
				data->player->pos->x = j * 32;
				data->player->pos->y = i * 32;
			}
			j++;
		}
		i++;
	}
}

size_t	xor_shift(size_t value)
{
	value ^= (value << 21);
	value ^= (value >> 35);
	value ^= (value << 4);
	return (value);
}

size_t	pseudo_rand(size_t x, size_t y, size_t range, t_data *data)
{
	size_t	seed;
	size_t	pseudo;

	seed = x * 4286 + y * data->map->width + data->map->height;
	seed = xor_shift(seed);
	pseudo = (seed % range);
	return (pseudo);
}
