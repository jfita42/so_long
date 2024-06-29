/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:04:59 by jfita             #+#    #+#             */
/*   Updated: 2024/02/08 18:13:21 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	unbr_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	print_u(unsigned int nbr)
{
	if (nbr > 9)
	{
		print_u(nbr / 10);
		print_u(nbr % 10);
	}
	else
		ft_putchar_fd(nbr + 48, 1);
}

int	ft_print_u(unsigned int nbr)
{
	print_u(nbr);
	return (unbr_len(nbr));
}
