/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:58:06 by martiper          #+#    #+#             */
/*   Updated: 2023/05/11 10:45:39 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/player.h"
#include <game.h>

static void	hook_keys(t_sl_key_manager *keys)
{
	keys->hook(KEYCODE_W);
	keys->hook(KEYCODE_A);
	keys->hook(KEYCODE_S);
	keys->hook(KEYCODE_D);
	keys->hook(KEYCODE_ARROW_LEFT);
	keys->hook(KEYCODE_ARROW_RIGHT);
	keys->hook(KEYCODE_ARROW_UP);
	keys->hook(KEYCODE_ARROW_DOWN);
	keys->hook(KEYCODE_E);
}

void	sl_scripting_player_keys_init(void)
{
	t_sl_game	*game;

	game = get_game();
	if (!game)
		return ;
	hook_keys(game->get_keys());
	game->get_events()->on(\
		EVENT_KEY_CHANGED, \
		(void (*)(void *))sl_scripting_player_handle_movement \
	);
	game->get_events()->on(\
		EVENT_KEY_CHANGED, \
		(void (*)(void *))sl_scripting_player_handle_interact \
	);
	game->get_events()->on(\
		EVENT_ON_PLAYER_MOVE, \
		(void (*)(void *))sl_scripting_player_check_patrol_collision \
	);
}
