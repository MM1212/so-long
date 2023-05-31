/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:00:31 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 13:09:52 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "scripting/game/ui.h"

#define SECOND_TO_MS 1000

static	void	count_time(void *data)
{
	static t_timestamp	last_time;
	t_sl_game			*game;
	t_timestamp			now;

	(void)data;
	game = get_game();
	if (!game)
		return ;
	now = game->get_time()->get_now();
	if (!last_time)
		last_time = now;
	if (now - last_time < SECOND_TO_MS)
		return ;
	last_time = now;
	game->stats.time++;
	game->get_renderer()->ask_to_render();
}

void	sl_scripting_game_ui_init(void)
{
	t_sl_game	*game;

	game = get_game();
	if (!game)
		return ;
	game->get_events()->on(EVENT_NEW_FRAME, count_time);
}
