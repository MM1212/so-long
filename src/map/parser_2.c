/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:45:36 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 12:55:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/parser.h"
#include "map/utils.h"

static void	get_features_from_tile(char tile, t_sl_map_features *features)
{
	if (tile == MAP_CONFIG_TYPE_COLLECTIBLE || tile == MAP_CONFIG_TYPE_EXIT
		|| tile == MAP_CONFIG_TYPE_PLAYER)
		features->entities++;
	if (tile == MAP_CONFIG_TYPE_COLLECTIBLE)
		features->collectibles++;
	else if (tile == MAP_CONFIG_TYPE_EXIT)
		features->exits++;
	else if (tile == MAP_CONFIG_TYPE_PLAYER)
		features->players++;
	else if (tile == MAP_CONFIG_TYPE_FREE_SPACE)
		features->freespace++;
	else if (tile == MAP_CONFIG_TYPE_WALL)
		features->walls++;
	else if (tile == MAP_CONFIG_TYPE_PATROL)
		features->patrols++;
}

static void	compute_tile(\
	char row, \
	t_vec2 iter, \
	t_vec2 dims, \
	t_sl_map *map \
)
{
	t_sl_map_tile	*tile;

	get_features_from_tile(row, &map->features);
	tile = &map->tiles[iter.y][iter.x];
	tile->id = iter.x + iter.y * dims.x;
	tile->position = vec2_mul_scal(iter, SPRITE_SIZE);
	tile->type = sl_map_get_tile_type_from_char(row);
	tile->texm = sl_new_texture_manager(
			sl_map_tile_get_tex_manager(tile->type));
}

static void	compute_tiles(\
	t_sl_map *map, \
	t_list *rows, \
	char **matrix \
)
{
	t_vec2			iter;
	char			*row;

	iter = vec2(0, 0);
	while (iter.y < map->size.y)
	{
		row = rows->content;
		map->tiles[iter.y] = ft_calloc(map->size.x, sizeof(t_sl_map_tile));
		if (!map->tiles[iter.y])
			return ;
		iter.x = 0;
		while (iter.x < map->size.x)
		{
			compute_tile(row[iter.x], iter, map->size, map);
			iter.x++;
		}
		iter.y++;
		*matrix++ = row;
		rows = rows->next;
	}
}

void	sl_map_compute_tiles(t_list *rows, t_sl_map *map)
{
	map->tiles = ft_calloc(map->size.y, sizeof(t_sl_map_tile *));
	if (!map->tiles)
		return ;
	map->definition = ft_calloc(ft_lstsize(rows) + 1, sizeof(char *));
	if (!map->definition)
		return ;
	compute_tiles(map, rows, map->definition);
}
