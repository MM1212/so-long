/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:12:01 by martiper          #+#    #+#             */
/*   Updated: 2023/05/10 22:04:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/interact.h"
#include "map/map.h"
#include <utils/rand.h>

typedef t_sl_map_tile_neighbors	t_neighbors;

static bool	sl_map_is_at_an_edge(t_sl_map *map, t_vec2 position)
{
	return (position.x == 0 || position.y == 0
		|| position.x == map->size.x - SPRITE_SIZE
		|| position.y == map->size.y - SPRITE_SIZE);
}

t_neighbors	sl_map_get_pos_data(t_sl_map *map, t_vec2 pos)
{
	t_neighbors	neighbors;

	neighbors.top = sl_map_get_tile(\
		(t_vec2){pos.x, pos.y - SPRITE_SIZE});
	neighbors.bottom = sl_map_get_tile(\
		(t_vec2){pos.x, pos.y + SPRITE_SIZE});
	neighbors.left = sl_map_get_tile(\
		(t_vec2){pos.x - SPRITE_SIZE, pos.y});
	neighbors.right = sl_map_get_tile(\
		(t_vec2){pos.x + SPRITE_SIZE, pos.y});
	neighbors.top_left = sl_map_get_tile(\
		(t_vec2){pos.x - SPRITE_SIZE, pos.y - SPRITE_SIZE});
	neighbors.top_right = sl_map_get_tile(\
		(t_vec2){pos.x + SPRITE_SIZE, pos.y - SPRITE_SIZE});
	neighbors.bottom_left = sl_map_get_tile(\
		(t_vec2){pos.x - SPRITE_SIZE, pos.y + SPRITE_SIZE});
	neighbors.bottom_right = sl_map_get_tile(\
		(t_vec2){pos.x + SPRITE_SIZE, pos.y + SPRITE_SIZE});
	neighbors.in_edge = sl_map_is_at_an_edge(map, pos);
	return (neighbors);
}

#define FRSP MAP_TILE_FREE_SPACE
#define WALL MAP_TILE_WALL

static void	sl_map_interact_wall(\
	t_sl_map *map, \
	t_sl_map_tile *tile \
)
{
	t_neighbors	neighbors;

	neighbors = sl_map_get_pos_data(map, tile->position);
	if (!neighbors.in_edge && random_range(0, 1) == 0)
		sl_switch_to_texture(tile->texm, "tree_left");
	else if (!neighbors.in_edge)
		sl_switch_to_texture(tile->texm, "tree_right");
	else if (!neighbors.top && !neighbors.left)
		sl_switch_to_texture(tile->texm, "top_left");
	else if (!neighbors.top && !neighbors.right)
		sl_switch_to_texture(tile->texm, "top_right");
	else if (!neighbors.bottom && !neighbors.left)
		sl_switch_to_texture(tile->texm, "bottom_left");
	else if (!neighbors.bottom && !neighbors.right)
		sl_switch_to_texture(tile->texm, "bottom_right");
	else if (!neighbors.right)
		sl_switch_to_texture(tile->texm, "right");
	else if (!neighbors.left)
		sl_switch_to_texture(tile->texm, "left");
	else if (!neighbors.top)
		sl_switch_to_texture(tile->texm, "top");
	else if (!neighbors.bottom)
		sl_switch_to_texture(tile->texm, "bottom");
}

static void	sl_map_interact_tile(\
	t_sl_map *map, \
	t_sl_map_tile *tile \
)
{
	if (tile->type == MAP_TILE_WALL)
		sl_map_interact_wall(map, tile);
}

void	sl_map_interact_tiles(t_sl_map *map)
{
	t_vec2	iter;

	iter = vec2(0, 0);
	while (iter.y < map->size.y)
	{
		iter.x = 0;
		while (iter.x < map->size.x)
		{
			sl_map_interact_tile(map, sl_map_get_tile(iter));
			iter.x += SPRITE_SIZE;
		}
		iter.y += SPRITE_SIZE;
	}
}
