/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:42:39 by jfita             #+#    #+#             */
/*   Updated: 2024/04/02 15:53:27 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, size_t i, size_t x, size_t y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[i].mlx_img,
		y * 32, x * 32);
}

void	init_img(t_data *data)
{
	init_first_sprites(data);
	init_second_sprites(data);
}

void	xpm_to_img(t_data *data, size_t i, char *path)
{
	data->img[i].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&data->img[i].img_width, &data->img[i].img_height);
	if (!(data->img[i].mlx_img))
		err_terminate("XPM to IMG FAIL\n");
}

void	init_first_sprites(t_data *data)
{
	xpm_to_img(data, T_WALL1_IND, T_WALL1);
	xpm_to_img(data, T_WALL2_IND, T_WALL2);
	xpm_to_img(data, T_WALL3_IND, T_WALL3);
	xpm_to_img(data, T_WALL4_IND, T_WALL4);
	xpm_to_img(data, T_WALL5_IND, T_WALL5);
	xpm_to_img(data, T_WALL6_IND, T_WALL6);
	xpm_to_img(data, T_WALL7_IND, T_WALL7);
	xpm_to_img(data, T_WALL8_IND, T_WALL8);
	xpm_to_img(data, T_WALL9_IND, T_WALL9);
	xpm_to_img(data, T_SHIPUP_IND, T_SHIPUP);
	xpm_to_img(data, T_SHIPDOWN_IND, T_SHIPDOWN);
	xpm_to_img(data, T_SHIPLEFT_IND, T_SHIPLEFT);
	xpm_to_img(data, T_SHIPRIGHT_IND, T_SHIPRIGHT);
	xpm_to_img(data, T_SHIPDUL_IND, T_SHIPDUL);
	xpm_to_img(data, T_SHIPDUR_IND, T_SHIPDUR);
	xpm_to_img(data, T_SHIPDDL_IND, T_SHIPDDL);
	xpm_to_img(data, T_SHIPDDR_IND, T_SHIPDDR);
	xpm_to_img(data, T_TERRA_IND3, T_TERRA3);
	xpm_to_img(data, T_TERRA_IND4, T_TERRA4);
}

void	init_second_sprites(t_data *data)
{
	xpm_to_img(data, T_BACK_IND, T_BACK);
	xpm_to_img(data, T_BACK2_IND, T_BACK2);
	xpm_to_img(data, T_BACK3_IND, T_BACK3);
	xpm_to_img(data, T_BACK4_IND, T_BACK4);
	xpm_to_img(data, T_BACK5_IND, T_BACK5);
	xpm_to_img(data, T_BACK6_IND, T_BACK6);
	xpm_to_img(data, T_BACK7_IND, T_BACK7);
	xpm_to_img(data, T_BACK8_IND, T_BACK8);
	xpm_to_img(data, T_BACK9_IND, T_BACK9);
	xpm_to_img(data, T_BACK10_IND, T_BACK10);
	xpm_to_img(data, T_BACKN_IND, T_BACKN);
	xpm_to_img(data, T_EXIT_IND, T_EXIT);
	xpm_to_img(data, T_COLLECT_IND, T_COLLECT);
	xpm_to_img(data, T_COLLECT1_IND, T_COLLECT1);
	xpm_to_img(data, T_COLLECT2_IND, T_COLLECT2);
	xpm_to_img(data, T_COLLECT3_IND, T_COLLECT3);
	xpm_to_img(data, T_COLLECT4_IND, T_COLLECT4);
	xpm_to_img(data, T_COLLECT5_IND, T_COLLECT5);
	xpm_to_img(data, T_COLLECT6_IND, T_COLLECT6);
	xpm_to_img(data, T_COLLECT7_IND, T_COLLECT7);
	xpm_to_img(data, T_COLLECT8_IND, T_COLLECT8);
	xpm_to_img(data, T_TERRA_IND, T_TERRA);
	xpm_to_img(data, T_TERRA_IND1, T_TERRA1);
	xpm_to_img(data, T_TERRA_IND2, T_TERRA2);
}
