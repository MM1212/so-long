/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chests.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:35:49 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 14:08:25 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/chests.h"
#include <game.h>
#include <entities/data.h>

static bool	check_chest(t_sl_game *game, t_sl_entity *entity)
{
	t_sl_entity_data_collectible	*data;
	t_sl_entity_data_player			*player_data;

	data = entity->data;
	if (!data->collected)
		return (false);
	player_data = game->get_entity_registry()->player->data;
	if (game->get_time()->get_now() - data->collected_at > 1500)
		player_data->opening_chest = false;
	if (\
		entity->texm->current->current != 0 || \
		game->get_time()->get_now() - data->collected_at < 1000)
		return (false);
	game->stats.collectibles++;
	game->get_entity_registry()->delete(entity);
	return (true);
}

static void	on_new_frame(void *data)
{
	t_sl_game	*game;
	t_list		*iter;

	(void)data;
	game = get_game();
	if (!game)
		return ;
	iter = game->get_entity_registry()->entities;
	while (iter)
	{
		if (((t_sl_entity *)iter->content)->type == SL_ENTITY_COLLECTIBLE)
			if (check_chest(game, (t_sl_entity *)iter->content))
				break ;
		iter = iter->next;
	}
}

void	sl_scripting_chests_init(void)
{
	t_sl_game	*game;

	game = get_game();
	if (!game)
		return ;
	game->get_events()->on(EVENT_NEW_FRAME, on_new_frame);
}
