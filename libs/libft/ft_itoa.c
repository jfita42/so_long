/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:27:49 by jfita             #+#    #+#             */
/*   Updated: 2023/11/12 17:09:08 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size += 1;
	}
	if (n == 0)
		size = 1;
	else
	{
		while (n > 0)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	size;
	long	number;
	int		isneg;

	size = ft_size((long)n);
	isneg = 0;
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	number = (long)n;
	if (number < 0)
	{
		number *= -1;
		ptr[0] = '-';
		isneg = 1;
	}
	ptr[size] = '\0';
	while (size > (size_t)isneg)
	{
		ptr[size - 1] = number % 10 + '0';
		number = number / 10;
		size--;
	}
	return (ptr);
}
