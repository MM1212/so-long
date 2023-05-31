/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:05:38 by mm                #+#    #+#             */
/*   Updated: 2023/04/13 02:00:41 by mm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

#define NUMERIC_CHARS "0123456789"
#define INT_MAX_2 147483648

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', (unsigned int)fd);
		if (n == INT_MIN)
		{
			ft_putchar_fd('2', (unsigned int)fd);
			n = INT_MAX_2;
		}
		else
			n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(NUMERIC_CHARS[n % 10], (unsigned int)fd);
}
