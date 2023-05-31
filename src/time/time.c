/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:57:41 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:43:16 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context/context.h>
#include <gfx/g_renderer.h>
#include <std.h>
#include <utils/log.h>
#include "time/time.h"

static void	compute_fps(void)
{
	t_time			*time;
	t_frame_time	*frame;
	t_timestamp		now;
	t_gfx_renderer	*renderer;

	time = get_time_ctx();
	renderer = get_renderer_ctx();
	if (!time || !renderer)
		return ;
	now = time->get_now();
	frame = &time->frame;
	if (frame->_last_compute_timestamp != -1 && time->get_now()
		- frame->_last_compute_timestamp < FPS_REFRESH_RATE)
		return ;
	time->frame._last_compute_timestamp = now;
	time->frame.fps = (size_t)round(1000.0 / time->frame.delta_time);
	time->frame.fps_count_time = 0;
	renderer->ask_to_render();
}

static bool	should_render_frame(void)
{
	t_time	*time;
	clock_t	now;
	double	delta;

	time = get_time_ctx();
	if (!time)
		return (false);
	if (!time->frame.are_fps_capped)
		return (true);
	if (time->frame.last_frame == -1)
		time->frame.last_frame = clock();
	now = clock();
	delta = (now - time->frame.last_frame) * 1000.0 / CLOCKS_PER_SEC;
	return ((delta) >= 1000.0 / time->frame.fps_cap);
}

static void	parse_frame(void)
{
	t_time	*time;
	clock_t	now;

	time = get_time_ctx();
	if (!time)
		return ;
	now = clock();
	time->frame.delta_time = (now - time->frame.last_frame) * 1000.0
		/ CLOCKS_PER_SEC;
	time->frame.frame_time += time->frame.delta_time;
	time->frame.last_frame = now;
}

static t_time	*create_time(void)
{
	t_time	*time;

	time = ft_calloc(1, sizeof(t_time));
	if (!time)
		return (NULL);
	time->started = clock();
	time->get_now = time_get_now;
	time->get_elapsed = time_get_elapsed;
	time->frame.fps_cap = FPS_CAP;
	time->frame.are_fps_capped = FPS_CAP > 0;
	time->frame.last_frame = -1;
	time->frame.delta_time = 0;
	time->frame.frame_time = 0;
	time->frame.fps_count_time = 0;
	time->frame._last_compute_timestamp = -1;
	time->frame.compute_fps = compute_fps;
	time->frame.should_render_frame = should_render_frame;
	time->frame.on_frame_rendered = time_def_internal_on_frame_rendered;
	time->frame.parse_frame = parse_frame;
	ft_printf(LOG_INFO "Fps Limit: %d\n", time->frame.fps_cap);
	return (time);
}

t_time	*get_time_ctx(void)
{
	return (get_context(\
		CONTEXT_ID_TIME, \
		(void *(*)(void))create_time, \
		free \
	));
}
