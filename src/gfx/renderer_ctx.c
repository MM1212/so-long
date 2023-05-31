/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_ctx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:03:20 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:04:24 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/g_renderer.h"
#include <context/context.h>

static void	gfx_renderer_ask_to_render(void)
{
	t_gfx_renderer	*ctx;

	ctx = get_renderer_ctx();
	if (!ctx)
		return ;
	ctx->should_render = true;
}

static void	gfx_renderer_mark_as_rendered(void)
{
	t_gfx_renderer	*ctx;

	ctx = get_renderer_ctx();
	if (!ctx)
		return ;
	ctx->should_render = false;
}

static t_gfx_renderer	*renderer_create(void)
{
	t_gfx_renderer	*renderer;

	renderer = ft_calloc(1, sizeof(t_gfx_renderer));
	if (!renderer)
		return (NULL);
	renderer->should_render = false;
	renderer->ask_to_render = gfx_renderer_ask_to_render;
	renderer->mark_as_rendered = gfx_renderer_mark_as_rendered;
	renderer->get_cam = get_camera_ctx;
	renderer->render_thread = gfx_defs_internal_renderer_render_thread;
	return (renderer);
}

t_gfx_renderer	*get_renderer_ctx(void)
{
	return (get_context(\
		CONTEXT_ID_RENDERER, \
		(void *(*)(void))renderer_create, free \
	));
}
