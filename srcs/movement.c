/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:27:17 by jfita             #+#    #+#             */
/*   Updated: 2024/04/02 17:33:01 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, int dir)
{
	if (dir == DOWN || dir == UP || dir == LEFT || dir == RIGHT)
		move_straight(data, dir);
	if (dir == DUL || dir == DUR || dir == DDL || dir == DDR)
		move_diag(data, dir);
	draw_movement(data);
	update_pos(data);
	render_player(data, dir);
}

void	count_moves(t_data *data, int pixels)
{
	static int	distance;

	if (pixels > 0)
	{
		distance = distance + pixels;
		if (distance >= 32)
		{
			data->player->moves++;
			distance = distance - 32;
			ft_printf("MOVES: %d\n", data->player->moves);
		}
	}
}

void	move_straight(t_data *data, int dir)
{
	if (dir == DOWN)
	{
		data->player->pp[1] += get_ddist(data);
		count_moves(data, get_ddist(data));
	}
	if (dir == UP)
	{
		data->player->pp[1] -= get_udist(data);
		count_moves(data, get_udist(data));
	}
	if (dir == LEFT)
	{
		data->player->pp[0] -= get_ldist(data);
		count_moves(data, get_ldist(data));
	}
	if (dir == RIGHT)
	{
		data->player->pp[0] += get_rdist(data);
		count_moves(data, get_rdist(data));
	}
}

void	move_diag(t_data *data, int dir)
{
	if (dir == DUL)
	{
		data->player->pp[1] -= (get_udist(data) / 2);
		data->player->pp[0] -= (get_ldist(data) / 2);
		count_moves(data, (get_udist(data) / 2 + get_ldist(data) / 2));
	}
	if (dir == DUR)
	{
		data->player->pp[1] -= (get_udist(data) / 2);
		data->player->pp[0] += (get_rdist(data) / 2);
		count_moves(data, (get_udist(data) / 2 + get_rdist(data) / 2));
	}
	if (dir == DDL)
	{
		data->player->pp[1] += (get_ddist(data) / 2);
		data->player->pp[0] -= (get_ldist(data) / 2);
		count_moves(data, (get_ddist(data) / 2 + get_ldist(data) / 2));
	}
	if (dir == DDR)
	{
		data->player->pp[1] += (get_ddist(data) / 2);
		data->player->pp[0] += (get_rdist(data) / 2);
		count_moves(data, (get_ddist(data) / 2 + get_rdist(data) / 2));
	}
}

void	movement(t_data *data)
{
	if (data->player->move_dul)
		move_player(data, DUL);
	else if (data->player->move_dur)
		move_player(data, DUR);
	else if (data->player->move_ddl)
		move_player(data, DDL);
	else if (data->player->move_ddr)
		move_player(data, DDR);
	else if (data->player->move_down)
		move_player(data, DOWN);
	else if (data->player->move_up)
		move_player(data, UP);
	else if (data->player->move_left)
		move_player(data, LEFT);
	else if (data->player->move_right)
		move_player(data, RIGHT);
}
