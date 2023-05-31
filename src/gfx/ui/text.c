/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:24:30 by martiper          #+#    #+#             */
/*   Updated: 2023/05/10 22:31:22 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/ui/text.h"
#include <std.h>
#include "gfx/window.h"

void	gfx_ui_push_font_size(size_t size)
{
	t_sl_window	*window;
	char		font[64];

	window = get_window_ctx();
	if (!window)
		return ;
	if (size == window->font_size)
		return ;
	window->font_size = size;
	ft_sprintf(font, 64, "-misc-*-medium-r-*-*-%d-*-*-*-*-*-*-*", size);
	mlx_set_font(window->mlx, window->win, font);
}

void	gfx_ui_draw_text(char *str, int color, int x, int y)
{
	t_sl_window		*window;
	static size_t	padding;

	if (!str)
		return ;
	window = get_window_ctx();
	if (!window)
		return ;
	if (!padding)
	{
		if (window->dimensions.x < window->dimensions.y)
			padding = window->dimensions.x * 0.05;
		else
			padding = window->dimensions.y * 0.05;
	}
	mlx_string_put(\
		window->mlx, window->win, \
		x * padding / 2, y * padding, \
		color, str \
	);
}
