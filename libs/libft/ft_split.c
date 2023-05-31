/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:36 by martiper          #+#    #+#             */
/*   Updated: 2023/05/05 01:04:03 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static void	count_letters_and_words(
	const char *str,
	const char delimiter,
	size_t *letters,
	size_t *words)
{
	bool	is_on_word;

	*letters = 0;
	*words = 0;
	is_on_word = false;
	while (*str)
	{
		if (*str != delimiter)
		{
			if (!is_on_word)
			{
				(*words)++;
				is_on_word = true;
			}
			(*letters)++;
		}
		else
			is_on_word = false;
		str++;
	}
}

static void	fill_buffers(
	const char *str,
	const char delimiter,
	char **ptrs,
	char *buffer)
{
	bool	is_on_word;

	is_on_word = false;
	while (*str)
	{
		if (*str != delimiter)
		{
			*buffer = *str;
			if (!is_on_word)
			{
				is_on_word = true;
				*ptrs++ = buffer;
			}
			buffer++;
		}
		else
		{
			if (is_on_word)
			{
				*buffer++ = '\0';
				is_on_word = false;
			}
		}
		str++;
	}
}

static void	*cleanup_malloc_null(
	char **ptrs,
	char *buffer,
	size_t size)
{
	if (ptrs)
	{
		while (size > 0)
		{
			free(ptrs[--size]);
		}
		if (size == 0)
			free(ptrs);
	}
	if (buffer)
		free(buffer);
	return (NULL);
}

void	ft_split_free(
	char **split
)
{
	size_t	idx;

	idx = 0;
	if (!split)
		return ;
	while (split[idx])
		free(split[idx++]);
	free(split);
}

char	**ft_split(
	char const *s,
	char c)
{
	size_t	words;
	size_t	letters;
	char	**ptrs;
	char	**tmp;
	char	*buffer;

	count_letters_and_words(s, c, &letters, &words);
	ptrs = ft_calloc(sizeof(char *), words + 1);
	if (!ptrs)
		return (NULL);
	buffer = ft_calloc(sizeof(char), letters + words);
	if (!buffer)
		return (cleanup_malloc_null(ptrs, buffer, 0));
	ptrs[words] = NULL;
	fill_buffers(s, c, ptrs, buffer);
	tmp = ptrs;
	while (*tmp)
	{
		*tmp = ft_strdup(*tmp);
		if (!*tmp)
			return (cleanup_malloc_null(ptrs, buffer, tmp - ptrs));
		tmp++;
	}
	free(buffer);
	return (ptrs);
}
