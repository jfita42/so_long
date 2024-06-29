/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_laser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:32:04 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:39:26 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	laser_collide(t_data *data, size_t index)
{
	t_list		*lst;
	t_invader	*invader;

	lst = data->invader;
	while (lst)
	{
		invader = (t_invader *)lst->content;
		check_laser(invader, data, index);
		lst = lst->next;
	}
}

void	check_laser(t_invader *invader, t_data *data, size_t index)
{
	size_t		i;
	long long	anim;
	int			rng;

	i = 0;
	anim = millitimestamp() + 500;
	while (i < index)
	{
		if (data->laser[i].x == invader->tc[0]
			&& data->laser[i].y == invader->tc[1] && invader->alive)
		{
			while (millitimestamp() < anim)
			{
				rng = ft_range_rand(4);
				invader->sprite = T_BOOM_IND + rng;
				render_boom(data, invader);
			}
			kill_invader(invader);
		}
		i++;
	}
}

void	render_laser(t_data *data, int x, int y, int index)
{
	size_t	rng;

	rng = ft_range_rand(4);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[index
		+ rng].mlx_img, x, y);
}

void	render_boom(t_data *data, t_invader *invader)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[invader->sprite].mlx_img, invader->pp[0], invader->pp[1]);
}
