/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:58:24 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:39:02 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_report(int err_no)
{
	static int		checks;
	static t_error	*map_err;

	if (!checks)
		map_err = error_zero();
	if (!err_terminate(NULL))
	{
		checks++;
		if (err_no != -1)
			err_set(err_no, map_err);
		if (checks == 7 || err_no == ERR_R)
		{
			if (err_eval(map_err))
			{
				ft_printf("/!\\ MAP ERROR /!\\\n");
				err_print(map_err);
			}
			free(map_err);
		}
	}
}

void	err_set(int err_no, t_error *map_err)
{
	if (err_no == ERR_S)
		map_err->err_spawn = true;
	if (err_no == ERR_E)
		map_err->err_ext = true;
	if (err_no == ERR_C)
		map_err->err_col = true;
	if (err_no == ERR_I)
		map_err->err_inv = true;
	if (err_no == ERR_W)
		map_err->err_wall = true;
	if (err_no == ERR_R)
		map_err->err_rect = true;
	if (err_no == ERR_L)
		map_err->err_line = true;
}

bool	err_eval(t_error *map_err)
{
	if (map_err->err_spawn || map_err->err_ext || map_err->err_col
		|| map_err->err_inv || map_err->err_wall || map_err->err_rect
		|| map_err->err_line)
		return (true);
	else
		return (false);
}

void	err_print(t_error *map_err)
{
	if (map_err->err_spawn == true)
		ft_printf(MAP_ERR0);
	if (map_err->err_ext == true)
		ft_printf(MAP_ERR1);
	if (map_err->err_col == true)
		ft_printf(MAP_ERR2);
	if (map_err->err_inv == true)
		ft_printf(MAP_ERR3);
	if (map_err->err_wall == true)
		ft_printf(MAP_ERR4);
	if (map_err->err_rect == true)
		ft_printf(MAP_ERR5);
	if (map_err->err_line == true)
		ft_printf(MAP_ERR8);
	err_terminate("--FIX THESE BEFORE ATTEMPTING FLOODFILL--\n");
}
