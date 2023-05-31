/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:10:12 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 14:35:01 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/player.h"
#include "entities/data.h"
#include <game.h>
#include <utils/log.h>

static void	play_player_idle_anim(t_sl_entity *player)
{
	if (player->transform.direction.x == 1)
		sl_switch_to_texture(player->texm, "idle_right");
	else
		sl_switch_to_texture(player->texm, "idle_left");
}

static void	handle_exit_interact(void)
{
	t_sl_game	*game;

	game = get_game();
	if (!game)
		return ;
	if (game->stats.collectibles < game->get_map()->features.collectibles)
		return ;
	destroy_all_contexts();
	ft_printf("\n\n"LOG_SUCCESS"U won!\n\n");
	exit(EXIT_SUCCESS);
}

static void	handle_chest_interact(t_sl_entity *entity, t_sl_entity *player)
{
	t_sl_entity_data_collectible	*data;

	data = entity->data;
	((t_sl_entity_data_player *)player->data)->opening_chest = true;
	data->collected = true;
	data->collected_at = get_game()->get_time()->get_now();
	sl_switch_to_texture(entity->texm, "opening");
	play_player_idle_anim(player);
}

void	sl_scripting_player_handle_interact(t_sl_keycode *keycode)
{
	t_sl_entity						*player;
	t_sl_entity_registry			*registry;
	t_sl_entity						*entity;

	if (keycode->keycode != KEYCODE_E || keycode->pressed)
		return ;
	ft_printf(LOG_INFO "Interacting..\n");
	registry = get_game()->get_entity_registry();
	player = registry->player;
	entity = registry->get_at(\
		sl_map_get_tile(vec2_add(\
				player->transform.position, \
				vec2(SPRITE_SIZE / 2, SPRITE_SIZE / 2) \
			) \
		)->position \
	);
	if (!entity)
		return ;
	if (entity->type == SL_ENTITY_COLLECTIBLE)
		handle_chest_interact(entity, player);
	else if (entity->type == SL_ENTITY_EXIT)
		handle_exit_interact();
}
