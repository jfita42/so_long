/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:17:12 by jfita             #+#    #+#             */
/*   Updated: 2024/02/08 18:13:24 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	hex_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		len ++;
	}
	return (len);
}

static void	print_hex(unsigned int nbr, int flag)
{
	static char	hexlow[] = "0123456789abcdef";
	static char	hexup[] = "0123456789ABCDEF";

	if (nbr >= 16)
		print_hex((nbr / 16), flag);
	if (flag == 1)
		write(1, &hexlow[nbr % 16], 1);
	else if (flag == 2)
		write(1, &hexup[nbr % 16], 1);
}

int	ft_print_xx(unsigned int nbr, int flag)
{
	print_hex(nbr, flag);
	return (hex_len(nbr));
}
