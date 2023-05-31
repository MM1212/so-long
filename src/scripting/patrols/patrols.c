/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:35:49 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 12:34:17 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/patrols/patrols.h"
#include "scripting/patrols/gameplay.h"
#include <game.h>
#include <entities/data.h>
#include <map/interact.h>
#include <utils/rand.h>
#include <utils/log.h>

static void	check_patrol(t_sl_game *game, t_sl_entity *entity)
{
	t_sl_entity_data_patrol	*data;
	t_sl_map_tile_neighbors	neighbors;

	data = entity->data;
	if (game->get_time()->get_now() - data->last_move < PATROLS_STOP_INTERVAL)
		return ;
	if (vec2_length(entity->transform.speed) > 0)
		return (sl_scripting_patrols_stop_patrol(entity));
	if (game->get_time()->get_now() - data->last_move < PATROLS_MOVE_INTERVAL)
		return ;
	data->last_move = game->get_time()->get_now();
	neighbors = sl_map_get_pos_data(\
		game->get_map(), \
		sl_map_get_tile(entity->transform.position)->position \
	);
	entity->transform.speed = vec2(SPRITE_SIZE, SPRITE_SIZE);
	entity->transform.direction = sl_scripting_patrols_choose_direction(\
		&neighbors \
	);
	if (entity->transform.direction.x > 0)
		sl_switch_to_texture(entity->texm, "running_right");
	else
		sl_switch_to_texture(entity->texm, "running_left");
	sl_entity_move(entity, true, false);
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
		if (((t_sl_entity *)iter->content)->type == SL_ENTITY_PATROL)
			check_patrol(game, (t_sl_entity *)iter->content);
		iter = iter->next;
	}
}

void	sl_scripting_patrols_init(void)
{
	t_sl_game	*game;

	game = get_game();
	if (!game)
		return ;
	game->get_events()->on(EVENT_NEW_FRAME, on_new_frame);
}
