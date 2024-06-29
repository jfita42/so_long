/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:18:55 by jfita             #+#    #+#             */
/*   Updated: 2024/04/08 15:38:03 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_terminate(t_data *data)
{
	if (err_terminate(NULL))
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
}

int	err_terminate(char *msg)
{
	static int	called;

	if (msg != NULL)
	{
		called = 1;
		ft_printf(msg);
	}
	return (called);
}
