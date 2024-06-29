/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:17:15 by jfita             #+#    #+#             */
/*   Updated: 2023/11/12 16:29:45 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(long number, int fd)
{
	if ((number / 10) > 0)
	{
		ft_print(number / 10, fd);
		ft_print(number % 10, fd);
	}
	else
		ft_putchar_fd(number + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	ft_print(number, fd);
}
