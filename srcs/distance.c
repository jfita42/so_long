/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:40:26 by jfita             #+#    #+#             */
/*   Updated: 2024/04/02 17:31:02 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_rdist(t_data *data)
{
	int			dist;
	t_player	*p;
	char		**map;

	p = data->player;
	map = data->map->tab_map;
	if (map[(p->tr[1]) / TILE][(p->tr[0]) / TILE + 1] == '1' || map[(p->br[1])
		/ TILE][(p->br[0]) / TILE + 1] == '1')
	{
		if (map[(p->pc[1] / TILE)][(p->pc[0] / TILE)] == '1')
			return (-32);
		dist = TILE - (p->br[0] % TILE) - 1;
		if (dist > SPEED)
			return (SPEED);
		return (dist);
	}
	return (SPEED);
}

int	get_ldist(t_data *data)
{
	int			dist;
	t_player	*p;
	char		**map;

	p = data->player;
	map = data->map->tab_map;
	if (map[(p->tl[1]) / TILE][(p->tl[0]) / TILE - 1] == '1' || map[(p->bl[1])
		/ TILE][(p->bl[0]) / TILE - 1] == '1')
	{
		if (map[(p->pc[1] / TILE)][(p->pc[0] / TILE)] == '1')
			return (-32);
		dist = (p->bl[0] % TILE);
		if (dist > SPEED)
			return (SPEED);
		return (dist);
	}
	return (SPEED);
}

int	get_ddist(t_data *data)
{
	int			dist;
	t_player	*p;
	char		**map;

	p = data->player;
	map = data->map->tab_map;
	if (map[(p->bl[1]) / TILE + 1][(p->bl[0]) / TILE] == '1' || map[(p->br[1])
		/ TILE + 1][(p->br[0]) / TILE] == '1')
	{
		if (map[(p->pc[1] / TILE)][(p->pc[0] / TILE)] == '1')
			return (-32);
		dist = TILE - (p->bl[1] % TILE) - 1;
		if (dist > SPEED)
			return (SPEED);
		return (dist);
	}
	return (SPEED);
}

int	get_udist(t_data *data)
{
	int			dist;
	t_player	*p;
	char		**map;

	p = data->player;
	map = data->map->tab_map;
	if (map[(p->tl[1]) / TILE - 1][(p->tl[0]) / TILE] == '1' || map[(p->tr[1])
		/ TILE - 1][(p->tr[0]) / TILE] == '1')
	{
		if (map[(p->pc[1] / TILE)][(p->pc[0] / TILE)] == '1')
			return (-32);
		dist = (p->tl[1] % TILE);
		if (dist > SPEED)
			return (SPEED);
		return (dist);
	}
	return (SPEED);
}

void	update_pos(t_data *data)
{
	t_player	*p;

	p = data->player;
	p->tl[0] = p->pp[0] + 2;
	p->tl[1] = p->pp[1] + 2;
	p->tr[0] = p->pp[0] + TILE - 2;
	p->tr[1] = p->pp[1] + 2;
	p->bl[0] = p->pp[0] + 2;
	p->bl[1] = p->pp[1] + TILE - 2;
	p->br[0] = p->pp[0] + TILE - 2;
	p->br[1] = p->pp[1] + TILE - 2;
	p->pc[0] = p->pp[0] + (TILE / 2);
	p->pc[1] = p->pp[1] + (TILE / 2);
}
