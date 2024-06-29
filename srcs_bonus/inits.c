/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:50:28 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:33 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player(t_data *data)
{
	data->player->collect = data->map->nb_collect;
	data->player->dir = 21;
	data->player->moves = 0;
	init_pos(data, 'P');
	data->player->pp[0] = data->player->pos->x;
	data->player->pp[1] = data->player->pos->y;
	data->player->hp = HP;
}

void	init_mlx(t_data *data, size_t width, size_t height)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		err_terminate("Mlx init fail\n");
	check_terminate(data);
	if (data->map->width < HP + 4)
		data->win_ptr = mlx_new_window(data->mlx_ptr, (HP + 4) * 32, (height
					+ 1) * 32, "So Long");
	else
		data->win_ptr = mlx_new_window(data->mlx_ptr, width * 32, (height + 1)
				* 32, "So Long");
	if (!(data->win_ptr))
		err_terminate("Mlx new window fail\n");
}

t_data	*init_data(const char *mapfile)
{
	t_data	*data;
	int		fd;

	if (open(mapfile, __O_DIRECTORY) > 2)
	{
		fd = open(mapfile, __O_DIRECTORY);
		err_terminate("Input file is a directory\n");
		close(fd);
	}
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		err_terminate("Error opening file\n");
	data = data_zero();
	check_terminate(data);
	data->map->filename = ft_strdup(mapfile);
	if (!data->map->filename)
		err_terminate("strdup fail for map->filename");
	check_terminate(data);
	parse_map(data, fd);
	init_mlx(data, data->map->width, data->map->height);
	init_img(data);
	init_player(data);
	init_invader(data);
	check_terminate(data);
	return (data);
}
