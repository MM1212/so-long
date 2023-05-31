/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:50:03 by martiper          #+#    #+#             */
/*   Updated: 2023/05/11 11:42:37 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/entity.h"
#include "entities/spawners.h"
#include "entities/data.h"
#include <map/map.h>
#include <utils/error.h>
#include <std.h>

#define SPAWN_EXIT_ERROR "Failed to spawn exit entity, \
	most likely it is already spawned"

t_sl_entity	*sl_entities_spawn_player(
	t_sl_entity_registry *registry,
	t_vec2 pos)
{
	t_sl_entity		*entity;
	t_sl_new_entity	new;

	new = (t_sl_new_entity){
		.type = SL_ENTITY_PLAYER,
		.tag = ft_strdup("player"),
		.position = pos,
		.texm_def_path = "textures/player/texm.slprops",
		.data = ft_calloc(1, sizeof(t_sl_entity_data_player))
	};
	entity = registry->new(new);
	if (!entity)
		return (NULL);
	registry->player = entity;
	return (entity);
}

static char	*get_exit_tex_for_pos(t_vec2 pos)
{
	t_sl_map	*map;
	size_t		offset_to_walls[4];

	map = get_map_ctx();
	if (!map)
		return (NULL);
	offset_to_walls[0] = pos.x;
	offset_to_walls[1] = map->size.x - pos.x;
	offset_to_walls[2] = pos.y;
	offset_to_walls[3] = map->size.y - pos.y;
	if (offset_to_walls[0] < offset_to_walls[1]
		&& offset_to_walls[0] < offset_to_walls[2]
		&& offset_to_walls[0] < offset_to_walls[3])
		return ("left");
	else if (offset_to_walls[1] < offset_to_walls[0]
		&& offset_to_walls[1] < offset_to_walls[2]
		&& offset_to_walls[1] < offset_to_walls[3])
		return ("right");
	else if (offset_to_walls[2] < offset_to_walls[0]
		&& offset_to_walls[2] < offset_to_walls[1]
		&& offset_to_walls[2] < offset_to_walls[3])
		return ("top");
	else
		return ("bottom");
}

t_sl_entity	*sl_entities_spawn_exit(
	t_sl_entity_registry *registry,
	t_vec2 pos)
{
	t_sl_entity		*entity;
	t_sl_new_entity	new;

	new = (t_sl_new_entity){
		.type = SL_ENTITY_EXIT,
		.tag = ft_strdup("exit"),
		.position = pos,
		.texm_def_path = "textures/boats/b_00/texm.slprops",
		.data = NULL
	};
	entity = registry->new(new);
	if (entity)
		sl_switch_to_texture(entity->texm, get_exit_tex_for_pos(pos));
	else
		return (sl_error(SPAWN_EXIT_ERROR, NULL));
	return (entity);
}

t_sl_entity	*sl_entities_spawn_collectible(
	t_sl_entity_registry *registry,
	t_vec2 pos)
{
	t_sl_entity		*entity;
	t_sl_new_entity	new;
	static int		collectible_count;
	char			*collectible_str;

	collectible_str = ft_itoa(collectible_count++);
	new = (t_sl_new_entity){
		.type = SL_ENTITY_COLLECTIBLE,
		.tag = ft_strjoin("collectible_", collectible_str),
		.position = pos,
		.texm_def_path = "textures/chests/texm.slprops",
		.data = ft_calloc(1, sizeof(t_sl_entity_data_collectible))
	};
	free(collectible_str);
	entity = registry->new(new);
	return (entity);
}

t_sl_entity	*sl_entities_spawn_patrol(
	t_sl_entity_registry *registry,
	t_vec2 pos)
{
	t_sl_entity		*entity;
	t_sl_new_entity	new;
	static int		patrol_count;
	char			*patrol_str;

	patrol_str = ft_itoa(patrol_count++);
	new = (t_sl_new_entity){
		.type = SL_ENTITY_PATROL,
		.tag = ft_strjoin("patrol_", patrol_str),
		.position = pos,
		.texm_def_path = "textures/patrol/texm.slprops",
		.data = ft_calloc(1, sizeof(t_sl_entity_data_patrol))
	};
	free(patrol_str);
	entity = registry->new(new);
	if (entity)
		((t_sl_entity_data_patrol *)entity->data)->id = patrol_count;
	return (entity);
}
