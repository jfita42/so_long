/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:37:56 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:57 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	main_loop(t_data *data)
{
	long long	now;
	long long	elapsed_time;

	now = millitimestamp();
	elapsed_time = now - data->tictac;
	if (elapsed_time > 8)
	{
		movement(data);
		update_invader(data);
		render_player(data, data->player->dir);
		collect_collide(data);
		exit_collide(data);
		chrono(data);
	}
	return (0);
}

void	start_game(const char *mapfile)
{
	t_data	*data;

	data = init_data(mapfile);
	initialize_array(data);
	data->img_array = create_img_array(data);
	draw_img_array(data);
	update_pos(data);
	render_player(data, T_SHIPUP_IND);
	render_hud(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &on_destroy, data);
	mlx_loop_hook(data->mlx_ptr, &main_loop, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, const char **argv)
{
	if (argc == 2)
		start_game(argv[1]);
	return (0);
}
