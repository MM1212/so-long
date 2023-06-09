/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:46:42 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 11:42:48 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/vec2.h"

t_vec2	vec2_div(t_vec2 a, t_vec2 b)
{
	t_vec2	vec;

	vec.x = a.x / b.x;
	vec.y = a.y / b.y;
	return (vec);
}

t_vec2	vec2_div_scal(t_vec2 a, int constant)
{
	t_vec2	vec;

	vec.x = a.x / constant;
	vec.y = a.y / constant;
	return (vec);
}

double	vec2_dist(t_vec2 a, t_vec2 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}
