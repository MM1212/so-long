/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:00:35 by martiper          #+#    #+#             */
/*   Updated: 2023/05/11 10:41:43 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/player.h"
#include "entities/data.h"

static bool	is_wall(t_vec2 pos)
{
	t_sl_map_tile	*tile;

	tile = sl_map_get_tile(pos);
	if (!tile)
		return (true);
	return (tile->type == MAP_TILE_WALL);
}

static bool	is_valid_move(t_sl_entity *player, t_vec2 *new_pos)
{
	t_vec2	dir;

	dir = player->transform.direction;
	*new_pos = sl_entity_compute_new_position(player);
	if (is_wall(*new_pos))
		return (false);
	if (dir.x > 0 || dir.y < 0)
	{
		if (is_wall(vec2_add(*new_pos, vec2(SPRITE_SIZE - 1, 0))))
			return (false);
	}
	if (dir.x > 0 || dir.y > 0)
	{
		if (is_wall(vec2_add(*new_pos, vec2(SPRITE_SIZE - 1, SPRITE_SIZE - 1))))
			return (false);
	}
	if (dir.y > 0 || dir.x < 0)
	{
		if (is_wall(vec2_add(*new_pos, vec2(0, SPRITE_SIZE - 1))))
			return (false);
	}
	return (true);
}

static bool	compute_direction_speed(\
	t_sl_keycodes keycode, \
	t_sl_entity *player, \
	bool moving \
)
{
	t_transform				*transform;

	if (!sl_scripting_player_is_movement_key(keycode))
		return (false);
	transform = &player->transform;
	if (moving)
	{
		if (keycode == KEYCODE_W || keycode == KEYCODE_ARROW_UP)
			transform->direction = vec2(0, -1);
		else if (keycode == KEYCODE_A || keycode == KEYCODE_ARROW_LEFT)
			transform->direction = vec2(-1, 0);
		else if (keycode == KEYCODE_S || keycode == KEYCODE_ARROW_DOWN)
			transform->direction = vec2(0, 1);
		else if (keycode == KEYCODE_D || keycode == KEYCODE_ARROW_RIGHT)
			transform->direction = vec2(1, 0);
		else
			return (false);
		transform->speed = vec2(\
			SPRITE_SIZE * PLAYER_SPEED_MULTIPLIER, \
			SPRITE_SIZE * PLAYER_SPEED_MULTIPLIER);
	}
	else
		transform->speed = vec2(0, 0);
	return (true);
}

static void	on_player_move_change(\
	t_sl_game *game, \
	t_sl_entity *player, \
	bool moving, \
	t_sl_keycodes keycode \
)
{
	t_vec2	new_pos;

	if (!compute_direction_speed(keycode, player, moving))
		return ;
	if (moving && !((t_sl_entity_data_player *)player->data)->opening_chest)
	{
		if (player->transform.direction.x == 1)
			sl_switch_to_texture(player->texm, "running_right");
		else
			sl_switch_to_texture(player->texm, "running_left");
		if (!is_valid_move(player, &new_pos))
			return ;
		if (
			sl_map_get_tile(player->transform.position)->id != \
			sl_map_get_tile(new_pos)->id
		)
			game->stats.moves++;
		sl_entity_move_to(player, new_pos, true, true);
		game->get_events()->emit(EVENT_ON_PLAYER_MOVE, player);
		return ;
	}
	if (player->transform.direction.x == 1)
		sl_switch_to_texture(player->texm, "idle_right");
	else
		sl_switch_to_texture(player->texm, "idle_left");
}

void	sl_scripting_player_handle_movement(t_sl_keycode *keycode)
{
	t_sl_game	*game;

	game = get_game();
	if (\
		!game || \
		!game->get_entity_registry() || \
		!game->get_entity_registry()->player \
	)
		return ;
	on_player_move_change(\
		game, \
		game->get_entity_registry()->player, \
		keycode->pressed, \
		keycode->keycode \
	);
}
