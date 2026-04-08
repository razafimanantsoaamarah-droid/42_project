/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:41:41 by maherraz          #+#    #+#             */
/*   Updated: 2026/02/28 00:28:19 by maherraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_words(char **arr, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < filled)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	**fill_array(char **array, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s && i < words)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		len = word_len(s, c);
		array[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!array[i])
			return (free_words(array, i));
		ft_strlcpy(array[i], s, len + 1);
		i++;
		s += len;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	return (fill_array(array, s, c, words));
}
