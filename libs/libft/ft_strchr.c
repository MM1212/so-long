/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:27:33 by mm                #+#    #+#             */
/*   Updated: 2023/04/11 15:14:59 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (const unsigned char)*s != (const unsigned char)c)
		s++;
	if ((const unsigned char)*s == (const unsigned char)c)
		return ((char *)s);
	return (NULL);
}
