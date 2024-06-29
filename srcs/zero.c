/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:47:37 by jfita             #+#    #+#             */
/*   Updated: 2024/04/02 14:48:44 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*data_zero(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		err_terminate("Malloc fail in data_zero\n");
	check_terminate(data);
	data->img = img_zero();
	data->map = map_zero();
	data->fmap = map_zero();
	data->player = player_zero();
	check_terminate(data);
	return (data);
}

t_player	*player_zero(void)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
	{
		err_terminate("Malloc fail in player_zero\n");
		return (NULL);
	}
	player->pos = ft_calloc(1, sizeof(t_pos));
	if (!player->pos)
	{
		free_player(player);
		err_terminate("Malloc fail for pos- player_zero");
		return (NULL);
	}
	return (player);
}

t_img	*img_zero(void)
{
	t_img	*img;

	img = ft_calloc(NBRIMG + 1, sizeof(t_img));
	if (!img)
		err_terminate("Malloc fail in img_zero\n");
	return (img);
}

t_map	*map_zero(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		err_terminate("Malloc fail in map_zero\n");
		return (NULL);
	}
	map->pos = ft_calloc(1, sizeof(t_pos));
	if (!map->pos)
	{
		free_map(map);
		err_terminate("Malloc fail in map_zero\n");
		return (NULL);
	}
	return (map);
}
