/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:21:41 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:11 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		on_destroy(data);
	if (keysym == XK_space)
		shoot(data);
	if (!data->player->shooting)
	{
		if (keysym == XK_s)
			data->player->move_down = 1;
		if (keysym == XK_w)
			data->player->move_up = 1;
		if (keysym == XK_a)
			data->player->move_left = 1;
		if (keysym == XK_d)
			data->player->move_right = 1;
		if (data->player->move_up && data->player->move_left)
			data->player->move_dul = 1;
		if (data->player->move_up && data->player->move_right)
			data->player->move_dur = 1;
		if (data->player->move_down && data->player->move_left)
			data->player->move_ddl = 1;
		if (data->player->move_down && data->player->move_right)
			data->player->move_ddr = 1;
	}
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_space)
		data->player->shooting = false;
	if (keysym == XK_s)
		data->player->move_down = 0;
	if (keysym == XK_w)
		data->player->move_up = 0;
	if (keysym == XK_a)
		data->player->move_left = 0;
	if (keysym == XK_d)
		data->player->move_right = 0;
	if (!data->player->move_up || !data->player->move_left)
		data->player->move_dul = 0;
	if (!data->player->move_up || !data->player->move_right)
		data->player->move_dur = 0;
	if (!data->player->move_down || !data->player->move_left)
		data->player->move_ddl = 0;
	if (!data->player->move_down || !data->player->move_right)
		data->player->move_ddr = 0;
	return (0);
}

int	on_destroy(t_data *data)
{
	free_data(data);
	ft_printf("Exit\n");
	exit(0);
	return (0);
}
