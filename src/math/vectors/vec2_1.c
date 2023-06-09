/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:33:50 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:46:25 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/vec2.h"
#include <math.h>

t_vec2	vec2_scale(t_vec2 a, int scale)
{
	t_vec2	vec;

	vec.x = a.x * scale;
	vec.y = a.y * scale;
	return (vec);
}

t_vec2	vec2_invert(t_vec2 a)
{
	t_vec2	vec;

	vec.x = -a.x;
	vec.y = -a.y;
	return (vec);
}

t_vec2	vec2_normalize(t_vec2 a)
{
	t_vec2	vec;
	double	magnitude;

	magnitude = sqrt(a.x * a.x + a.y * a.y);
	vec.x = a.x / magnitude;
	vec.y = a.y / magnitude;
	return (vec);
}

t_vec2	vec2_clamp(t_vec2 a, t_vec2 min, t_vec2 max)
{
	t_vec2	vec;

	vec.x = a.x;
	vec.y = a.y;
	if (vec.x < min.x)
		vec.x = min.x;
	else if (vec.x > max.x)
		vec.x = max.x;
	if (vec.y < min.y)
		vec.y = min.y;
	else if (vec.y > max.y)
		vec.y = max.y;
	return (vec);
}

double	vec2_length(t_vec2 a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}
