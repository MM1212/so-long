/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:30:17 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:07:35 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/def.h"
#include "gfx/g_renderer.h"
#include "gfx/window.h"
#include <game.h>
#include "map/m_renderer.h"
#include "entities/renderer.h"
#include "gfx/vignette.h"

static void	render(t_sl_window *window)
{
	sl_render_map();
	sl_render_entities();
	gfx_apply_vignette(window->render_buffer);
	gfx_draw_image_to_window(\
		window->mlx, window->win, \
		window->render_buffer, vec2(0, 0) \
	);
	sl_game_draw_ui();
}

int	gfx_defs_internal_renderer_render_thread(void)
{
	t_sl_game		*game;

	game = get_game();
	if (!game)
		return (1);
	if (game->get_time()->frame.should_render_frame())
	{
		sl_handle_map_animations();
		sl_handle_entities_animations();
		game->get_events()->emit(EVENT_NEW_FRAME, NULL);
		if (\
			game->get_renderer()->should_render && \
			game->get_window()->render_buffer \
		)
		{
			render(game->get_window());
			game->get_renderer()->mark_as_rendered();
		}
		game->get_time()->frame.parse_frame();
		game->get_time()->frame.compute_fps();
		game->get_time()->frame.on_frame_rendered();
	}
	return (0);
}
