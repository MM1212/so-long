/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:30:38 by mm                #+#    #+#             */
/*   Updated: 2023/04/12 15:49:25 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*orig;

	orig = s;
	while (*s++)
		;
	s--;
	while (s != orig && *s != (unsigned char)c)
		s--;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
