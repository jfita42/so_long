/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invaders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:30:01 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:44 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invader_alloc(int i, int j, t_data *data)
{
	t_invader	*invader;
	int			rng;

	rng = ft_range_rand(3);
	invader = ft_calloc(sizeof(t_invader), 1);
	if (invader == NULL)
		err_terminate("Malloc fail for invader init\n");
	invader->pp[0] = j * TILE;
	invader->pp[1] = i * TILE;
	invader->spawn[0] = invader->pp[0];
	invader->spawn[1] = invader->pp[1];
	invader->alive = true;
	invader->collide = false;
	invader->last_death = 0;
	invader->cooldown = 0;
	invader->dir = 0;
	invader->moving = 1;
	invader->sprite = T_INVADER_IND + rng;
	if (data->invader == NULL)
		data->invader = ft_lstnew(invader);
	else
		ft_lstadd_front(&data->invader, ft_lstnew(invader));
}

void	init_invader(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->tab_map[i][j] == 'M'
				|| data->map->tab_map[i][j] == 'E')
			{
				invader_alloc(i, j, data);
				check_terminate(data);
			}
			j++;
		}
		i++;
	}
}

void	update_invader(t_data *data)
{
	t_list		*lst;
	t_invader	*invader;

	lst = data->invader;
	while (lst)
	{
		invader = (t_invader *)lst->content;
		update__invader_pos(invader);
		invader_movement(invader);
		move_invader(invader, invader->dir, data);
		if (invader->alive)
		{
			draw_invader(data, invader);
			render_invader(data, invader);
		}
		if (!invader->alive && invader->last_death <= millitimestamp())
			respawn_invader(invader);
		player_collide(data, invader);
		update__invader_pos(invader);
		lst = lst->next;
	}
	lst = data->invader;
}

void	player_collide(t_data *data, t_invader *invader)
{
	t_player	*player;
	long long	now;

	player = data->player;
	now = millitimestamp();
	if (player->tc[0] == invader->tc[0] && player->tc[1] == invader->tc[1]
		&& invader->alive)
	{
		if (now - player->inv_frame >= 1000)
		{
			if (player->hp <= 1)
			{
				ft_printf("GAME OVER\n");
				on_destroy(data);
			}
			ft_printf("HP DOWN\n");
			player->hp--;
			player->inv_frame = now;
			reset_hud(data);
			render_hud(data);
		}
	}
}
