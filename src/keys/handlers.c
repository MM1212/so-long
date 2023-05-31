/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:49:52 by martiper          #+#    #+#             */
/*   Updated: 2023/05/04 23:15:11 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys/keys.h"
#include <events.h>
#include <gfx/window.h>

static int	on_key_pressed(int keycode)
{
	t_sl_key_manager	*manager;
	t_sl_event_manager	*events;

	manager = get_key_manager_ctx();
	if (keycode > KEYS_MAX)
		return (0);
	if (!manager->keys[keycode]._defined)
		return (0);
	manager->keys[keycode].pressed = true;
	events = get_event_manager_ctx();
	if (!events)
		return (0);
	events->emit(EVENT_KEY_CHANGED, &manager->keys[keycode]);
	return (0);
}

static int	on_key_released(int keycode)
{
	t_sl_key_manager	*manager;
	t_sl_event_manager	*events;

	manager = get_key_manager_ctx();
	if (keycode > KEYS_MAX)
		return (0);
	if (!manager->keys[keycode]._defined)
		return (0);
	manager->keys[keycode].pressed = false;
	events = get_event_manager_ctx();
	if (!events)
		return (0);
	events->emit(EVENT_KEY_CHANGED, &manager->keys[keycode]);
	return (0);
}

void	sl_key_manager_hook(void)
{
	t_sl_window	*ctx;

	ctx = get_window_ctx();
	if (!ctx)
		return ;
	mlx_hook(ctx->win, 2, 1L << 0, on_key_pressed, NULL);
	mlx_key_hook(ctx->win, on_key_released, NULL);
}
