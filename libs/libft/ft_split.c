/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:38:03 by jfita             #+#    #+#             */
/*   Updated: 2024/02/27 19:22:29 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	ft_putword(char *word, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
}

static char	**ft_memalloc(char **array, char const *s, char c)
{
	size_t	len;
	size_t	index;
	size_t	i;

	i = 0;
	index = 0;
	while (s[index])
	{
		len = 0;
		while (s[index + len] && s[index + len] != c)
			len++;
		if (len > 0)
		{
			array[i] = malloc(sizeof(char) * (len + 1));
			if (!array[i])
				return (free_tab(array), NULL);
			ft_putword(array[i], (s + index), c);
			i++;
			index = index + len;
		}
		else
			index++;
	}
	array[i] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**array;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = ft_memalloc(array, s, c);
	if (!array)
		return (NULL);
	return (array);
}
