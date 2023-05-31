/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:32:30 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:34:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/registry.h"
#include "entities/spawn.h"
#include "entities/spawners.h"
#include <map/map.h>
#include <map/parser.h>
#include <utils/log.h>

static bool	is_def_an_entity(t_map_configuration_type type)
{
	return (\
		type == MAP_CONFIG_TYPE_COLLECTIBLE || \
		type == MAP_CONFIG_TYPE_EXIT || \
		type == MAP_CONFIG_TYPE_PLAYER || \
		type == MAP_CONFIG_TYPE_PATROL \
	);
}

static t_sl_entity	*spawn_entity(t_sl_entity_registry *registry,
									t_map_configuration_type type,
									t_vec2 pos)
{
	if (type == MAP_CONFIG_TYPE_COLLECTIBLE)
		return (sl_entities_spawn_collectible(registry, pos));
	else if (type == MAP_CONFIG_TYPE_EXIT)
		return (sl_entities_spawn_exit(registry, pos));
	else if (type == MAP_CONFIG_TYPE_PLAYER)
		return (sl_entities_spawn_player(registry, pos));
	else if (type == MAP_CONFIG_TYPE_PATROL)
		return (sl_entities_spawn_patrol(registry, pos));
	return (NULL);
}

static bool	spawn_2(
	t_vec2 iter,
	t_map_configuration_type iter_type,
	t_sl_entity_registry *registry
)
{
	t_sl_entity	*entity;

	entity = spawn_entity(registry, iter_type, iter);
	if (!entity)
		return (false);
	else
		ft_printf(\
			LOG_INFO "Spawned entity %s[%d] at (%d, %d)\n", \
			entity->tag, entity->id, \
			entity->transform.position.x, \
			entity->transform.position.y \
		);
	return (true);
}

bool	sl_entities_spawn_load_map(\
	t_sl_map *map, \
	t_sl_entity_registry *registry \
)
{
	t_vec2						iter;
	t_map_configuration_type	iter_type;

	iter = vec2(0, 0);
	while (iter.y < map->size.y)
	{
		iter.x = 0;
		while (iter.x < map->size.x)
		{
			iter_type = (t_map_configuration_type)map->definition[iter.y
				/ SPRITE_SIZE][iter.x / SPRITE_SIZE];
			if (\
				is_def_an_entity(iter_type) && \
				!spawn_2(iter, iter_type, registry) \
			)
				return (false);
			iter.x += SPRITE_SIZE;
		}
		iter.y += SPRITE_SIZE;
	}
	return (true);
}
