/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:18:20 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:39:28 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	shoot(t_data *data)
{
	long long	now;

	now = millitimestamp();
	data->player->shooting = true;
	if (now - data->player->last_shoot >= 1000)
	{
		if (data->player->dir == RIGHT)
			shoot_right(data);
		if (data->player->dir == LEFT)
			shoot_left(data);
		if (data->player->dir == UP)
			shoot_up(data);
		if (data->player->dir == DOWN)
			shoot_down(data);
		data->player->last_shoot = now;
	}
}

void	shoot_right(t_data *data)
{
	size_t		i;
	size_t		origin;
	long long	anim;
	size_t		index;

	anim = millitimestamp() + 400;
	origin = data->player->pp[1] + 16;
	data->laser = malloc(data->map->width * sizeof(t_pos));
	while (millitimestamp() < anim)
	{
		index = 0;
		i = data->player->pc[0] + TILE;
		while (data->map->tab_map[origin / TILE][i / TILE] != '1')
		{
			data->laser[index].x = i / TILE;
			data->laser[index].y = origin / TILE;
			index++;
			render_laser(data, i - 16, origin - 16, T_LASER_IND);
			i += TILE;
		}
		laser_collide(data, index);
	}
	free(data->laser);
	draw_img_array(data);
	render_player(data, data->player->dir);
}

void	shoot_left(t_data *data)
{
	size_t		i;
	size_t		origin;
	long long	anim;
	size_t		index;

	anim = millitimestamp() + 400;
	origin = data->player->pp[1] + 16;
	data->laser = malloc(data->map->width * sizeof(t_pos));
	while (millitimestamp() < anim)
	{
		index = 0;
		i = data->player->pc[0] - TILE;
		while (data->map->tab_map[origin / TILE][i / TILE] != '1')
		{
			data->laser[index].x = i / TILE;
			data->laser[index].y = origin / TILE;
			index++;
			render_laser(data, i - 16, origin - 16, T_LASER_IND);
			i -= TILE;
		}
		laser_collide(data, index);
	}
	free(data->laser);
	draw_img_array(data);
	render_player(data, data->player->dir);
}

void	shoot_up(t_data *data)
{
	size_t		i;
	size_t		origin;
	long long	anim;
	size_t		index;

	anim = millitimestamp() + 400;
	origin = data->player->pp[0] + 16;
	data->laser = malloc(data->map->height * sizeof(t_pos));
	while (millitimestamp() < anim)
	{
		index = 0;
		i = data->player->pc[1] - TILE;
		while (data->map->tab_map[i / TILE][origin / 32] != '1')
		{
			data->laser[index].y = i / TILE;
			data->laser[index].x = origin / TILE;
			index++;
			render_laser(data, origin - 16, i - 16, T_VLASER_IND);
			i -= TILE;
		}
		laser_collide(data, index);
	}
	free(data->laser);
	draw_img_array(data);
	render_player(data, data->player->dir);
}

void	shoot_down(t_data *data)
{
	size_t		i;
	size_t		origin;
	long long	anim;
	size_t		index;

	anim = millitimestamp() + 400;
	origin = data->player->pp[0] + 16;
	data->laser = malloc(data->map->height * sizeof(t_pos));
	while (millitimestamp() < anim)
	{
		index = 0;
		i = data->player->pc[1] + TILE;
		while (data->map->tab_map[i / TILE][origin / 32] != '1')
		{
			data->laser[index].y = i / TILE;
			data->laser[index].x = origin / TILE;
			index++;
			render_laser(data, origin - 16, i - 16, T_VLASER_IND);
			i += TILE;
		}
		laser_collide(data, index);
	}
	free(data->laser);
	draw_img_array(data);
	render_player(data, data->player->dir);
}
