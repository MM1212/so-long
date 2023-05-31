/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:59:48 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:59:58 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/gfx.h"
#include "gfx/window.h"
#include <context/context.h>
#include <game.h>
#include <utils/log.h>

static void	attempt_to_exit(t_sl_keycode *keycode)
{
	if (keycode->keycode != KEYCODE_ESCAPE)
		return ;
	ft_printf(LOG_INFO"Exiting..\n");
	destroy_all_contexts();
	exit(EXIT_SUCCESS);
	return ;
}

static int	hook_destroy_btn(void)
{
	attempt_to_exit(&(t_sl_keycode){true, KEYCODE_ESCAPE, 0});
	return (0);
}

void	gfx_window_management_hook(void)
{
	t_sl_game	*game;

	game = get_game();
	if (!game)
		return ;
	game->get_keys()->hook(KEYCODE_ESCAPE);
	game->get_events()->on(\
		EVENT_KEY_CHANGED, \
		(void (*)(void *))attempt_to_exit);
	mlx_hook(game->get_window()->win, \
		17, 0, \
		hook_destroy_btn, NULL);
}
