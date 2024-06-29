/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:03 by jfita             #+#    #+#             */
/*   Updated: 2023/11/10 15:44:58 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1temp;
	unsigned char	*s2temp;

	s1temp = (unsigned char *)s1;
	s2temp = (unsigned char *)s2;
	i = 0;
	while (i < n && s1temp[i] == s2temp[i])
		i++;
	if (i < n)
		return (s1temp[i] - s2temp[i]);
	return (0);
}
