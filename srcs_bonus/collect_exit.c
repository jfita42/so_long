/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:25:03 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:37:45 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect_collide(t_data *data)
{
	t_player	*player;
	char		**map;

	player = data->player;
	map = data->map->tab_map;
	if (map[player->pc[1] / TILE][player->pc[0] / TILE] == 'C')
		terraform(data, (player->pc[1] / TILE), (player->pc[0] / TILE));
}

void	exit_collide(t_data *data)
{
	t_player	*player;
	char		**map;
	static bool	called;

	player = data->player;
	map = data->map->tab_map;
	if (player->collect == 0)
	{
		data->img_array[data->map->exit[0]][data->map->exit[1]]
			= &data->img[T_EXIT_IND];
		if (!called)
		{
			draw_img_array(data);
			called = 1;
		}
		if (map[player->pc[1] / TILE][player->pc[0] / TILE] == 'E')
		{
			ft_printf("YOU TERRAFORMED THE SYSTEM, GGWP\n");
			on_destroy(data);
		}
	}
}

void	terraform(t_data *data, int i, int j)
{
	t_img	***array;
	int		r;

	r = ft_range_rand(5);
	array = data->img_array;
	data->player->collect--;
	array[i][j] = &data->img[T_TERRA_IND + r];
	data->map->tab_map[i][j] = '0';
}
