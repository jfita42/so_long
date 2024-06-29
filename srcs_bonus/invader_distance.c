/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invader_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:40:26 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:37 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_invrdist(t_invader *invader, t_data *data)
{
	int			dist;
	t_invader	*p;
	char		**map;

	p = invader;
	map = data->map->tab_map;
	if (map[(p->tr[1]) / TILE][(p->tr[0]) / TILE + 1] == '1' || map[(p->br[1])
		/ TILE][(p->br[0]) / TILE + 1] == '1')
	{
		if (map[(p->pc[1] / TILE)][(p->pc[0] / TILE)] == '1')
			return (-32);
		dist = TILE - (p->br[0] % TILE) - 1;
		if (dist > SPEED)
			return (SPEED);
		if (dist == 0)
			invader->collide = true;
		return (dist);
	}
	return (SPEED);
}

int	get_invldist(t_invader *invader, t_data *data)
{
	int			dist;
	t_invader	*p;
	char		**map;

	p = invader;
	map = data->map->tab_map;
	if (map[(p->tl[1]) / TILE][(p->tl[0]) / TILE - 1] == '1' || map[(p->bl[1])
		/ TILE][(p->bl[0]) / TILE - 1] == '1')
	{
		if (map[(p->pc[1] / TILE)][(p->pc[0] / TILE)] == '1')
			return (-32);
		dist = (p->bl[0] % TILE);
		if (dist > SPEED)
			return (SPEED);
		if (dist == 0)
			invader->collide = true;
		return (dist);
	}
	return (SPEED);
}

int	get_invddist(t_invader *invader, t_data *data)
{
	int			dist;
	t_invader	*p;
	char		**map;

	p = invader;
	map = data->map->tab_map;
	if (map[(p->bl[1]) / TILE + 1][(p->bl[0]) / TILE] == '1' || map[(p->br[1])
		/ TILE + 1][(p->br[0]) / TILE] == '1')
	{
		if (map[(p->pc[1] / TILE)][(p->pc[0] / TILE)] == '1')
			return (-32);
		dist = TILE - (p->bl[1] % TILE) - 1;
		if (dist > SPEED)
			return (SPEED);
		if (dist == 0)
			invader->collide = true;
		return (dist);
	}
	return (SPEED);
}

int	get_invudist(t_invader *invader, t_data *data)
{
	int			dist;
	t_invader	*p;
	char		**map;

	p = invader;
	map = data->map->tab_map;
	if (map[(p->tl[1]) / TILE - 1][(p->tl[0]) / TILE] == '1' || map[(p->tr[1])
		/ TILE - 1][(p->tr[0]) / TILE] == '1')
	{
		if (map[(p->pc[1] / TILE)][(p->pc[0] / TILE)] == '1')
			return (-32);
		dist = (p->tl[1] % TILE);
		if (dist > SPEED)
			return (SPEED);
		if (dist == 0)
			invader->collide = true;
		return (dist);
	}
	return (SPEED);
}
