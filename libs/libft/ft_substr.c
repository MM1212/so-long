/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:42:35 by mm                #+#    #+#             */
/*   Updated: 2023/04/12 10:11:00 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*error_return(void)
{
	char	*ptr;

	ptr = malloc(sizeof(char));
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_length;
	char	*substr;

	str_length = ft_strlen(s);
	if (start >= str_length)
		return (error_return());
	if (len > str_length - start)
		len = str_length - start;
	substr = ft_calloc(sizeof(char), len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
