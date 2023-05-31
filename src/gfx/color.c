/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:50:38 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 11:20:12 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/color.h"

t_gfx_color	gfx_new_color(
	COLOR_BYTE r,
	COLOR_BYTE g,
	COLOR_BYTE b,
	COLOR_BYTE a)
{
	t_gfx_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

unsigned int	gfx_color_to_int(t_gfx_color color)
{
	return (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
}

t_gfx_color	gfx_int_to_color(unsigned int color)
{
	t_gfx_color	new_color;

	new_color.a = (color >> 24) & 0xFF;
	new_color.r = (color >> 16) & 0xFF;
	new_color.g = (color >> 8) & 0xFF;
	new_color.b = color & 0xFF;
	return (new_color);
}

t_gfx_color	gfx_color_add(t_gfx_color a, t_gfx_color b)
{
	t_gfx_color	new_color;

	new_color.r = a.r + b.r;
	new_color.g = a.g + b.g;
	new_color.b = a.b + b.b;
	new_color.a = a.a + b.a;
	return (new_color);
}

unsigned int	gfx_color_add_int(unsigned int a, unsigned int b)
{
	t_gfx_color	new_color;

	new_color = gfx_int_to_color(a);
	new_color = gfx_color_add(new_color, gfx_int_to_color(b));
	return (gfx_color_to_int(new_color));
}
