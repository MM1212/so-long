/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:08:52 by mm                #+#    #+#             */
/*   Updated: 2023/04/21 12:27:33 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

#define INT_MAX_2 147483648

size_t	compute_integer_size(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		if (n == INT_MIN)
		{
			n = INT_MAX_2;
			count++;
		}
		else
			n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	sanitize_input(char *str, int *n)
{
	size_t	tmp_count;

	tmp_count = 0;
	if (*n < 0)
	{
		str[tmp_count++] = '-';
		if (*n == INT_MIN)
		{
			*n = INT_MAX_2;
			str[tmp_count++] = '2';
		}
		else
			*n = -(*n);
	}
	else if (*n == 0)
		str[tmp_count++] = '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	length;

	length = compute_integer_size(n);
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	sanitize_input(str, &n);
	while (n > 0)
	{
		str[length-- - 1] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
