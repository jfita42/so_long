/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invaders2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:17:30 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:53 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	respawn_invader(t_invader *invader)
{
	int	rng;

	rng = ft_range_rand(3);
	invader->pp[0] = invader->spawn[0];
	invader->pp[1] = invader->spawn[1];
	invader->sprite = T_INVADER_IND + rng;
	invader->alive = true;
}

void	kill_invader(t_invader *invader)
{
	invader->alive = false;
	invader->last_death = millitimestamp() + RSPWN;
}

void	render_invader(t_data *data, t_invader *invader)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[invader->sprite].mlx_img, invader->pp[0], invader->pp[1]);
}

void	draw_invader(t_data *data, t_invader *invader)
{
	put_movement(data, invader->pp[0], invader->pp[1] - TILE);
	put_movement(data, invader->pp[0] + TILE, invader->pp[1]);
	put_movement(data, invader->pp[0], invader->pp[1] + TILE);
	put_movement(data, invader->pp[0] - TILE, invader->pp[1]);
	put_movement(data, invader->pp[0], invader->pp[1]);
	put_movement(data, invader->tr[0] + 1, invader->tr[1] - 1);
	put_movement(data, invader->br[0] + 1, invader->br[1] + 1);
	put_movement(data, invader->bl[0] - 1, invader->bl[1] + 1);
}

void	free_invader(t_data *data)
{
	t_list	*lst;
	t_list	*next;

	lst = data->invader;
	while (lst)
	{
		next = lst->next;
		free(lst->content);
		free(lst);
		lst = next;
	}
	data->invader = NULL;
}
