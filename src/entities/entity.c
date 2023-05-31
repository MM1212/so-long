/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:23:25 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:05:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/entity.h"
#include <game.h>

// TODO: CREATE FUNCTION TO CLEANUP TEXM
void	sl_entity_cleanup(t_sl_entity *entity)
{
	if (entity->data)
		free(entity->data);
	if (entity->texm)
		sl_texture_manager_destroy(entity->texm);
	free(entity->tag);
	free(entity);
}

t_vec2	sl_entity_compute_new_position(\
	t_sl_entity *entity
)
{
	t_vec2	new_pos;

	new_pos = vec2_add(entity->transform.position, \
		vec2_mul(entity->transform.direction, \
		entity->transform.speed) \
	);
	new_pos = vec2_clamp(\
		new_pos, \
		vec2(0, 0), \
		vec2_sub(get_map_ctx()->size, \
		vec2(SPRITE_SIZE, SPRITE_SIZE)) \
	);
	return (new_pos);
}

void	sl_entity_move_to(
	t_sl_entity *entity, \
	t_vec2 new_pos, \
	bool attempt_to_render, \
	bool update_cam
)
{
	t_sl_game	*game;

	game = get_game();
	if (!game)
		return ;
	entity->transform.position = new_pos;
	if (attempt_to_render \
		&& game->get_camera()->is_in_view(entity->transform.position))
		game->get_renderer()->ask_to_render();
	if (update_cam)
		game->get_camera()->update_position();
}

void	sl_entity_move(
	t_sl_entity *entity, \
	bool attempt_to_render, \
	bool update_cam
)
{
	sl_entity_move_to(\
		entity, \
		sl_entity_compute_new_position(entity), \
		attempt_to_render, \
		update_cam \
	);
}
