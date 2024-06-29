/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:45:38 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:39:32 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		millisecond;

	gettimeofday(&timeval, NULL);
	millisecond = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (millisecond);
}

void	chrono(t_data *data)
{
	long long	now;

	now = millitimestamp();
	if (now > data->tictac)
		data->tictac = now;
	if (now - data->player->cooldown > 1000)
		data->player->cooldown = now;
}
