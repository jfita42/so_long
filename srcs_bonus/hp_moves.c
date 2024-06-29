/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hp_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:12:34 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:14 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_hud(t_data *data)
{
	size_t	i;

	reset_hud(data);
	i = 0;
	while (i < data->player->hp)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img[T_SHIPUP_IND].mlx_img, i * 32, (data->map->height) * 32);
		i++;
	}
	render_hud_moves(data);
}

void	render_hud_moves(t_data *data)
{
	size_t	i;
	char	*moves;
	char	*msg;

	i = HP * 32;
	msg = "Move count: ";
	moves = ft_itoa(data->player->moves);
	msg = ft_strjoin(msg, moves);
	if (!moves || !msg)
		err_terminate("Malloc fail for moves itoa\n");
	check_terminate(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, (HP) * 32, ((data->map->height
				+ 1) * 32) - 8, 0xFFFFFF, msg);
	free(moves);
	free(msg);
}

void	reset_hud(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map->width)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img[T_BACKN_IND].mlx_img, i * 32, (data->map->height) * 32);
		i++;
	}
}
