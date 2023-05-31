/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vignette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:55:14 by martiper          #+#    #+#             */
/*   Updated: 2023/05/31 12:36:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/vignette.h"
#include <math.h>

// https://www.shadertoy.com/view/lsKSWR
/*
void	mainImage( out vec4 fragColor, in vec2 fragCoord )
{
	vec2	uv;

	uv = fragCoord.xy / iResolution.xy;
    uv *=  1.0 - uv.yx;   //vec2(1.0)- uv.yx; -> 1.-u.yx; Thanks FabriceNeyret !
    float vig = uv.x*uv.y * 15.0; // multiply with sth for intensity
    vig = pow(vig, 0.25);
	// change pow for modifying the extend of the  vignette
    fragColor = vec4(vig);
}
*/

#if GFX_VIGNETTE_ENABLED

static void	apply_per_pixel(
	t_mlx_image *render_buffer,
	float intensity,
	float radius,
	t_vec2 pos)
{
	float		uv_x;
	float		uv_y;
	float		vig;
	t_gfx_color	color;

	uv_x = (float)pos.x / render_buffer->width;
	uv_y = (float)pos.y / render_buffer->height;
	uv_x *= 1.0 - uv_x;
	uv_y *= 1.0 - uv_y;
	vig = uv_x * uv_y * intensity;
	vig = powf(vig, radius);
	if (vig > 1.0f)
		vig = 1.0f;
	color = gfx_int_to_color(\
		gfx_get_pixel_color_from_buffer(render_buffer, pos.x, pos.y) \
	);
	color.r *= vig;
	color.g *= vig;
	color.b *= vig;
	gfx_put_pixel_in_buffer(
		render_buffer,
		pos,
		color,
		true);
}

void	gfx_apply_vignette(t_mlx_image *render_buffer)
{
	t_vec2	iter;

	iter = vec2(0, 0);
	while ((size_t)iter.x < render_buffer->width)
	{
		iter.y = 0;
		while ((size_t)iter.y < render_buffer->height)
		{
			apply_per_pixel(\
				render_buffer, \
				GFX_VIGNETTE_INTENSITY, \
				GFX_VIGNETTE_RADIUS, \
				iter \
			);
			iter.y++;
		}
		iter.x++;
	}
}

#else

void	gfx_apply_vignette(t_mlx_image *render_buffer)
{
	(void)render_buffer;
}

#endif
