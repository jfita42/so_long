/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:41:26 by jfita             #+#    #+#             */
/*   Updated: 2023/11/13 15:25:55 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	if ((dst == NULL || src == NULL) && size == 0)
		return (0);
	srclen = ft_strlen((char *)src);
	dstlen = ft_strlen((char *)dst);
	i = 0;
	j = dstlen;
	if (dstlen < size - 1 && size > 0)
	{
		while (src[i] && dstlen + i < size - 1)
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	if (size <= dstlen)
		dstlen = size;
	return (srclen + dstlen);
}
