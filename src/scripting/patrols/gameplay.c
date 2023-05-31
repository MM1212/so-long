/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:19:05 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 12:22:37 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/patrols/gameplay.h"
#include <utils/log.h>

t_vec2	sl_scripting_patrols_choose_direction(\
	t_sl_map_tile_neighbors *neighbors \
)
{
	size_t	rand;
	t_vec2	dir;

	rand = (size_t)random_range(0, 3);
	if (rand == 0 && neighbors->left && \
		neighbors->left->type != MAP_TILE_WALL \
	)
		dir = vec2(-1, 0);
	else if (rand == 1 && neighbors->right && \
		neighbors->right->type != MAP_TILE_WALL \
	)
		dir = vec2(1, 0);
	else if (rand == 2 && neighbors->top && \
		neighbors->top->type != MAP_TILE_WALL \
	)
		dir = vec2(0, -1);
	else if (rand == 3 && neighbors->bottom && \
		neighbors->bottom->type != MAP_TILE_WALL \
	)
		dir = vec2(0, 1);
	else
		return (sl_scripting_patrols_choose_direction(neighbors));
	return (dir);
}

void	sl_scripting_patrols_check_if_lost(t_vec2 patrol_pos)
{
	t_sl_game	*game;
	t_sl_entity	*player;
	t_vec2		player_pos;

	game = get_game();
	if (!game)
		return ;
	player = game->get_entity_registry()->player;
	player_pos = sl_map_get_tile(player->transform.position)->position;
	if (vec2_dist(player_pos, patrol_pos) < SPRITE_SIZE)
	{
		destroy_all_contexts();
		ft_printf("\n\n"LOG_SUCCESS"U lost!\n\n");
		exit(EXIT_SUCCESS);
	}
}

void	sl_scripting_patrols_stop_patrol(
	t_sl_entity *entity \
)
{
	t_sl_game				*game;
	t_sl_entity_data_patrol	*data;

	game = get_game();
	if (!game)
		return ;
	data = entity->data;
	data->last_move = game->get_time()->get_now();
	entity->transform.speed = vec2(0, 0);
	if (entity->transform.direction.x > 0)
		sl_switch_to_texture(entity->texm, "idle_right");
	else
		sl_switch_to_texture(entity->texm, "idle_left");
	sl_scripting_patrols_check_if_lost(\
		sl_map_get_tile(entity->transform.position)->position \
	);
}
