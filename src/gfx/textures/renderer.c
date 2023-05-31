/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:50:20 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 15:40:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/textures/manager.h"
#include "gfx/image.h"
#include "gfx/window.h"
#include "gfx/g_renderer.h"
#include <camera/camera.h>

typedef t_sl_texture_manager	t_sl_texm;

void	gfx_put_texture_into_render_buffer(
	t_mlx_image *buffer,
	t_sl_texture *tex,
	t_vec2 pos
)
{
	t_vec2		iter;
	t_sl_sprite	*sprite;

	iter = vec2(0, 0);
	sprite = sl_get_current_sprite(tex);
	while (iter.x < sprite->dimensions.x)
	{
		iter.y = 0;
		while (iter.y < sprite->dimensions.y)
		{
			gfx_put_pixel_in_buffer_2(buffer,
				vec2_add(pos, iter),
				gfx_get_pixel_color_from_buffer(
					sprite->image, iter.x, iter.y), false);
			iter.y++;
		}
		iter.x++;
	}
}

void	sl_render_texture(t_sl_texm *texm, t_vec2 pos)
{
	t_sl_window	*ctx;
	t_sl_camera	*cam;
	t_vec2		translated_pos;

	ctx = get_window_ctx();
	cam = get_camera_ctx();
	if (!ctx || !cam)
		return ;
	if (!cam->is_in_view(pos))
		return ;
	translated_pos = vec2_add(vec2_sub(pos, cam->pos), vec2_div(cam->fov,
				vec2(2, 2)));
	gfx_put_texture_into_render_buffer(\
		ctx->render_buffer,
		texm->current,
		translated_pos);
}

bool	sl_handle_texture_animation(t_sl_texm *texm)
{
	t_gfx_renderer	*renderer;

	renderer = get_renderer_ctx();
	if (!renderer)
		return (false);
	if (sl_animate_texture(texm->animator, texm->current))
	{
		sl_switch_to_next_sprite(texm->current);
		renderer->ask_to_render();
		return (true);
	}
	return (false);
}
