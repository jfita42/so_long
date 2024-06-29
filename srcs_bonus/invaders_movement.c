/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invaders_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:30:01 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:40 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_invader(t_invader *invader, int dir, t_data *data)
{
	if (dir == INVDOWN || dir == INVUP || dir == INVLEFT || dir == INVRIGHT)
		inv_move_straight(invader, dir, data);
	if (dir == INVDUL || dir == INVDUR || dir == INVDDL || dir == INVDDR)
		inv_move_diag(invader, dir, data);
}

void	inv_move_straight(t_invader *invader, int dir, t_data *data)
{
	if (dir == INVDOWN)
	{
		invader->pp[1] += get_invddist(invader, data);
	}
	if (dir == INVUP)
	{
		invader->pp[1] -= get_invudist(invader, data);
	}
	if (dir == INVLEFT)
	{
		invader->pp[0] -= get_invldist(invader, data);
	}
	if (dir == INVRIGHT)
	{
		invader->pp[0] += get_invrdist(invader, data);
	}
}

void	inv_move_diag(t_invader *invader, int dir, t_data *data)
{
	if (dir == INVDUL)
	{
		invader->pp[1] -= (get_invudist(invader, data) / 2);
		invader->pp[0] -= (get_invldist(invader, data) / 2);
	}
	if (dir == INVDUR)
	{
		invader->pp[1] -= (get_invudist(invader, data) / 2);
		invader->pp[0] += (get_invrdist(invader, data) / 2);
	}
	if (dir == INVDDL)
	{
		invader->pp[1] += (get_invddist(invader, data) / 2);
		invader->pp[0] -= (get_invldist(invader, data) / 2);
	}
	if (dir == INVDDR)
	{
		invader->pp[1] += (get_invddist(invader, data) / 2);
		invader->pp[0] += (get_invrdist(invader, data) / 2);
	}
}

void	invader_movement(t_invader *invader)
{
	long long	current_time;
	int			rng;

	current_time = millitimestamp();
	rng = ft_range_rand(8);
	if (current_time - invader->cooldown >= 1000 || invader->collide == true)
	{
		rng = ft_range_rand(8);
		invader->dir = rng;
		invader->cooldown = current_time;
		invader->collide = false;
	}
}

void	update__invader_pos(t_invader *invader)
{
	invader->tl[0] = invader->pp[0] + 2;
	invader->tl[1] = invader->pp[1] + 2;
	invader->tr[0] = invader->pp[0] + TILE - 2;
	invader->tr[1] = invader->pp[1] + 2;
	invader->bl[0] = invader->pp[0] + 2;
	invader->bl[1] = invader->pp[1] + TILE - 2;
	invader->br[0] = invader->pp[0] + TILE - 2;
	invader->br[1] = invader->pp[1] + TILE - 2;
	invader->pc[0] = invader->pp[0] + (TILE / 2);
	invader->pc[1] = invader->pp[1] + (TILE / 2);
	invader->tc[0] = invader->pc[0] / TILE;
	invader->tc[1] = invader->pc[1] / TILE;
}
