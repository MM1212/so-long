/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:54:15 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:56:10 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/helpers.h"

int	mini(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int	maxi(int n1, int n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}

int	clampi(int n, int min, int max)
{
	return (maxi(mini(n, max), min));
}
