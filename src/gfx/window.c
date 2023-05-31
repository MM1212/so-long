/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:15:24 by martiper          #+#    #+#             */
/*   Updated: 2023/05/11 12:43:37 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/gfx.h"
#include "gfx/window.h"
#include <context/context.h>
#include <game.h>

static t_sl_window	*window_create(void)
{
	t_sl_window	*window;

	window = ft_calloc(1, sizeof(t_sl_window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		free(window);
		return (NULL);
	}
	return (window);
}

static void	window_destroy(t_sl_window *window)
{
	if (!window)
		return ;
	if (window->render_buffer)
	{
		mlx_destroy_image(window->mlx, window->render_buffer->img);
		free(window->render_buffer);
	}
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	if (window->mlx)
		mlx_destroy_display(window->mlx);
	free(window->mlx);
	free(window);
}

t_sl_window	*get_window_ctx(void)
{
	return (get_context(
			CONTEXT_ID_WINDOW,
			(void *(*)(void))window_create,
		(void (*)(void *))window_destroy));
}

bool	gfx_define_window(size_t width, size_t height)
{
	t_sl_window	*window;

	window = get_window_ctx();
	if (!window)
		return (false);
	window->win = mlx_new_window(window->mlx, width, height, WINDOW_TITLE);
	window->dimensions.x = width;
	window->dimensions.y = height;
	window->render_buffer = NULL;
	window->font_size = -1;
	if (!window->win)
	{
		mlx_destroy_display(window->mlx);
		free(window);
		return (false);
	}
	window->render_buffer = gfx_create_image_buffer(\
		window->mlx, window->dimensions.x, window->dimensions.y);
	if (!window->render_buffer || !window->render_buffer->img)
		return (false);
	gfx_ui_push_font_size(WINDOW_DEFAULT_FONT_SIZE * WINDOW_UI_SCALE);
	return (true);
}
