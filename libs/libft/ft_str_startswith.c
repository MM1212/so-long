/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_startswith.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:15:22 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 20:15:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_str_startswith(const char *str, const char *substr)
{
	return (ft_strnstr(str, substr, ft_strlen(str)) == str);
}

bool	ft_str_endswith(const char *str, const char *substr)
{
	size_t	str_len;
	size_t	substr_len;

	str_len = ft_strlen(str);
	substr_len = ft_strlen(substr);
	if (substr_len > str_len)
		return (false);
	return (ft_strnstr(str, substr, str_len) == str + str_len - substr_len);
}
