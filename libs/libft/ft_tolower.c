/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:26:34 by mm                #+#    #+#             */
/*   Updated: 2023/03/06 22:26:50 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ALPHABET_DELTA 'a' - 'A'

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += ALPHABET_DELTA;
	return (c);
}
