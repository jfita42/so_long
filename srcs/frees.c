/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:21 by jfita             #+#    #+#             */
/*   Updated: 2024/04/01 18:03:03 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Frees a data structure and all its members
void	free_data(t_data *data)
{
	if (data)
	{
		if (data->map != NULL)
			free_map(data->map);
		if (data->fmap != NULL)
			free_map(data->fmap);
		if (data->player != NULL)
			free_player(data->player);
		free_array(data);
		if (data->mlx_ptr || data->win_ptr || data->img)
			free_mlx(data);
		free(data);
	}
}

void	free_mlx(t_data *data)
{
	size_t	i;

	i = -1;
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	while (data->img && ++i < NBRIMG + 1)
		if (data->img[i].mlx_img)
			mlx_destroy_image(data->mlx_ptr, data->img[i].mlx_img);
	if (data->img != NULL)
		free(data->img);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

// Frees a map structure and all its members
void	free_map(t_map *map)
{
	size_t	i;

	if (map->tab_map != NULL)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->tab_map[i]);
			i++;
		}
		free(map->tab_map);
	}
	if (map->filename != NULL)
		free(map->filename);
	if (map->bigstr != NULL)
		free(map->bigstr);
	if (map->pos != NULL)
		free(map->pos);
	free(map);
}

void	free_player(t_player *player)
{
	if (player->pos != NULL)
		free(player->pos);
	free(player);
}

void	free_array(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_imgs)
	{
		free(data->img_array[i]);
		i++;
	}
	free(data->img_array);
}
