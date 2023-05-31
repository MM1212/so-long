/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:38:28 by martiper          #+#    #+#             */
/*   Updated: 2023/05/02 12:12:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define COLOR_BYTE unsigned char

typedef struct s_gfx_color
{
	COLOR_BYTE	a;
	COLOR_BYTE	r;
	COLOR_BYTE	g;
	COLOR_BYTE	b;
}				t_gfx_color;

t_gfx_color		gfx_new_color(COLOR_BYTE r, COLOR_BYTE g, COLOR_BYTE b,
					COLOR_BYTE a);
unsigned int	gfx_color_to_int(t_gfx_color color);
t_gfx_color		gfx_int_to_color(unsigned int color);
t_gfx_color		gfx_color_add(t_gfx_color a, t_gfx_color b);
unsigned int	gfx_color_add_int(unsigned int a, unsigned int b);

#endif