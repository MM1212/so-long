/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:03:36 by mm                #+#    #+#             */
/*   Updated: 2023/04/12 17:05:58 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*buffer;

	size = ft_strlen(s) + 1;
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s, size);
	return (buffer);
}
