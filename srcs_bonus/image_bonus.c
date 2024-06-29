/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:14 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:17 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_bonus_sprites(t_data *data)
{
	xpm_to_img(data, T_LASER_IND, T_LASER);
	xpm_to_img(data, T_LASER1_IND, T_LASER1);
	xpm_to_img(data, T_LASER2_IND, T_LASER2);
	xpm_to_img(data, T_LASER3_IND, T_LASER3);
	xpm_to_img(data, T_VLASER_IND, T_VLASER);
	xpm_to_img(data, T_VLASER1_IND, T_VLASER1);
	xpm_to_img(data, T_VLASER2_IND, T_VLASER2);
	xpm_to_img(data, T_VLASER3_IND, T_VLASER3);
	xpm_to_img(data, T_INVADER_IND, T_INVADER);
	xpm_to_img(data, T_INVADER1_IND, T_INVADER1);
	xpm_to_img(data, T_INVADER2_IND, T_INVADER2);
	xpm_to_img(data, T_INVADERS_IND, T_INVADERS);
	xpm_to_img(data, T_BOOM_IND, T_BOOM);
	xpm_to_img(data, T_BOOM1_IND, T_BOOM1);
	xpm_to_img(data, T_BOOM2_IND, T_BOOM2);
	xpm_to_img(data, T_BOOM3_IND, T_BOOM3);
}
