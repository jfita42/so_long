/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:14:13 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:39:24 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_player(t_data *data, int index)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[index].mlx_img, data->player->pp[0], data->player->pp[1]);
}

void	draw_movement(t_data *data)
{
	put_movement(data, data->player->pp[0], data->player->pp[1] - TILE);
	put_movement(data, data->player->pp[0] + TILE, data->player->pp[1]);
	put_movement(data, data->player->pp[0], data->player->pp[1] + TILE);
	put_movement(data, data->player->pp[0] - TILE, data->player->pp[1]);
	put_movement(data, data->player->pp[0], data->player->pp[1]);
	put_movement(data, data->player->tr[0] + 1, data->player->tr[1] - 1);
	put_movement(data, data->player->br[0] + 1, data->player->br[1] + 1);
	put_movement(data, data->player->bl[0] - 1, data->player->bl[1] + 1);
}

void	put_movement(t_data *data, int x, int y)
{
	int		draw_x;
	int		draw_y;
	t_img	*img;

	draw_x = (x / 32);
	draw_y = (y / 32);
	img = data->img_array[draw_y][draw_x];
	if (img != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img,
			draw_x * 32, draw_y * 32);
}

void	draw_img_array(t_data *data)
{
	size_t	y;
	size_t	x;
	size_t	draw_x;
	size_t	draw_y;
	t_img	*img;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			img = data->img_array[y][x];
			if (img != NULL)
			{
				draw_x = x * TILE;
				draw_y = y * TILE;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					img->mlx_img, draw_x, draw_y);
			}
			x++;
		}
		y++;
	}
}
