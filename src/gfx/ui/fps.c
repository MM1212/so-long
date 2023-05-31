/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:33:58 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 12:08:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time/time.h>
#include <std.h>
#include "gfx/gfx.h"
#include "gfx/ui/fps.h"
#include "gfx/ui/text.h"
#include "gfx/ui/cache.h"

static void	compute_fps_cache(t_gfx_ui_text_cache *cache, size_t value)
{
	if (cache->defined && cache->value == value)
		return ;
	cache->defined = true;
	if (cache->str)
		free(cache->str);
	cache->value = value;
	cache->str = ft_strjoin_free(ft_itoa(value), " FPS");
}

void	gfx_ui_fps_draw(void)
{
	t_time						*time;
	t_gfx_ui_text_cache			*fps;
	char						ftime_buffer[30];

	time = get_time_ctx();
	if (!time || !time->frame.delta_time)
		return ;
	fps = &get_ui_elements_ctx()->fps;
	compute_fps_cache(fps, time->frame.fps);
	gfx_ui_draw_text(fps->str, 0xFFFFFF, 1, 1);
	ft_sprintf(\
		ftime_buffer, \
		sizeof(ftime_buffer), \
		"%.2f ms", \
		time->frame.delta_time \
	);
	gfx_ui_draw_text(ftime_buffer, 0xFFFFFF, 1, 2);
}
