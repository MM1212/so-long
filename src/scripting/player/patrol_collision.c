/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:41:58 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:49:19 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/player.h"
#include <entities/data.h>
#include <utils/log.h>

static void	check_patrol_collision_with_player(\
	t_sl_entity *patrol, \
	t_sl_entity *player \
)
{
	t_sl_map_tile	*patrol_tile;
	t_sl_map_tile	*player_tile;
	char			error_msg[128];

	patrol_tile = sl_map_get_tile(patrol->transform.position);
	player_tile = sl_map_get_tile(player->transform.position);
	if (!patrol_tile || !player_tile)
		return ;
	if (patrol_tile->id != player_tile->id)
		return ;
	ft_sprintf(error_msg, \
		128,
		"\n\n"LOG_SUCCESS"You lost to patrol id %d!\n\n", \
		((t_sl_entity_data_patrol *)patrol->data)->id \
	);
	destroy_all_contexts();
	ft_printf(error_msg);
	exit(EXIT_SUCCESS);
}

void	sl_scripting_player_check_patrol_collision(t_sl_entity *player)
{
	static t_timestamp	last_check;
	static bool			running;
	t_sl_game			*game;
	t_list				*entities;
	t_sl_entity			*entity;

	game = get_game();
	if (!player || !game)
		return ;
	if (running || game->get_time()->get_now() - last_check < 500)
		return ;
	running = true;
	last_check = game->get_time()->get_now();
	entities = game->get_entity_registry()->entities;
	while (entities)
	{
		entity = (t_sl_entity *)entities->content;
		if (entity->type == SL_ENTITY_PATROL)
			check_patrol_collision_with_player(entity, player);
		entities = entities->next;
	}
	running = false;
}
