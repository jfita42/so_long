/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:26:06 by jfita             #+#    #+#             */
/*   Updated: 2024/04/02 14:34:12 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_img_array(t_data *data, int i, int j)
{
	size_t	r;
	t_img	***img_array;

	r = pseudo_rand(i, j, 47, data);
	img_array = data->img_array;
	if (data->map->tab_map[i][j] == '0' || data->map->tab_map[i][j] == 'P')
	{
		if (r <= 9)
			img_array[i][j] = &data->img[T_BACK_IND + r];
		else
			img_array[i][j] = &data->img[T_BACKN_IND];
	}
	else if (data->map->tab_map[i][j] == '1')
		img_array[i][j] = &data->img[T_WALL1_IND + ft_range_rand(9)];
	else if (data->map->tab_map[i][j] == 'C')
		img_array[i][j] = &data->img[T_COLLECT_IND + ft_range_rand(9)];
	else if (data->map->tab_map[i][j] == 'E')
		img_array[i][j] = &data->img[T_EXIT_IND];
}

t_img	***create_img_array(t_data *data)
{
	t_img	***img_array;
	size_t	i;
	size_t	j;

	i = 0;
	img_array = data->img_array;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			fill_img_array(data, i, j);
			j++;
		}
		i++;
	}
	return (img_array);
}

void	initialize_array(t_data *data)
{
	size_t	j;
	size_t	i;

	data->img_array = ft_calloc(data->map->height, sizeof(t_img **));
	if (data->img_array == NULL)
	{
		err_terminate("Malloc 1 fail in img_array");
		check_terminate(data);
	}
	i = 0;
	while (i < data->map->height)
	{
		data->img_array[i] = ft_calloc(data->map->width, sizeof(t_img *));
		if (data->img_array[i] == NULL)
			err_terminate("Malloc 2 fail in img_array");
		j = 0;
		while (j < data->map->width)
		{
			data->img_array[i][j] = NULL;
			j++;
		}
		i++;
	}
	data->nb_imgs = i;
	check_terminate(data);
}
