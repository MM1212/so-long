/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:35:31 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 12:25:59 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/rand.h"
#include <math.h>

/*
	returns a random float number
 */
size_t	random_int(size_t seed)
{
	static size_t	cache;

	if (!cache)
		cache = 1;
	cache = cache * 1103515245 + 12345 + seed;
	return ((unsigned int)(cache / 65536) % 32768);
}

size_t	random_range(size_t min, size_t max)
{
	return (random_int(0) % (max - min + 1) + min);
}
