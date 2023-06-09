/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:17:45 by mm                #+#    #+#             */
/*   Updated: 2023/04/10 14:35:36 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_8_BIT_UNSIGNED_CHAR 0x80 // 2 ^ 8

int	ft_isascii(int c)
{
	return (c >= 0 && c < MAX_8_BIT_UNSIGNED_CHAR);
}
