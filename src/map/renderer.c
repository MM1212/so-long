/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:25:19 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:56:26 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"
#include "map/m_renderer.h"
#include <camera/camera.h>
#include <gfx/sprites/sprite.h>
#include <gfx/textures/manager.h>
#include <std.h>

void	sl_render_map(void)
{
	t_sl_map	*map;
	t_vec2		iter;
	t_sl_camera	*cam;

	map = get_map_ctx();
	cam = get_camera_ctx();
	if (!map || !cam)
		return ;
	iter = vec2(0, 0);
	while (iter.y < \
		clampi(cam->pos.y + cam->fov.y - SPRITE_SIZE, 0, map->size.y) \
	)
	{
		iter.x = 0;
		while (iter.x < \
			clampi(cam->pos.x + cam->fov.x - SPRITE_SIZE, 0, map->size.x) \
		)
		{
			sl_render_texture(
				sl_map_get_tile(iter)->texm,
				iter);
			iter.x += SPRITE_SIZE;
		}
		iter.y += SPRITE_SIZE;
	}
}

void	sl_handle_map_animations(void)
{
	t_sl_map	*map;
	t_vec2		iter;
	t_sl_camera	*cam;
	t_vec2		max;

	map = get_map_ctx();
	cam = get_camera_ctx();
	if (!map || !cam)
		return ;
	iter = vec2(0, 0);
	max = map->size;
	while (iter.y < max.y)
	{
		iter.x = 0;
		while (iter.x < max.x)
		{
			if (cam->is_in_view(iter))
				sl_handle_texture_animation(sl_map_get_tile(iter)->texm);
			iter.x += SPRITE_SIZE;
		}
		iter.y += SPRITE_SIZE;
	}
}
