/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:49:27 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:49:14 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/interact.h"
#include "map/map.h"
#include "map/parser.h"
#include "map/utils.h"
#include <context/context.h>
#include <utils/log.h>
#include <std.h>

static t_sl_map	*ctx_create_map(void)
{
	t_sl_map	*map;

	map = ft_calloc(1, sizeof(t_sl_map));
	if (!map)
		return (NULL);
	return (map);
}

static void	free_map_tiles(t_sl_map *map)
{
	t_vec2	iter;

	iter = vec2(0, 0);
	while (iter.y < map->size.y / SPRITE_SIZE)
	{
		iter.x = 0;
		while (iter.x < map->size.x / SPRITE_SIZE)
			sl_map_tile_destroy(&map->tiles[iter.y][iter.x++]);
		free(map->tiles[iter.y]);
		iter.y++;
	}
	free(map->tiles);
}

static void	ctx_free_map(t_sl_map *map)
{
	t_vec2	iter;

	if (!map)
		return ;
	ft_printf(LOG_INFO"Cleaning up map..\n");
	iter = vec2(0, 0);
	if (map->tiles)
		free_map_tiles(map);
	iter.y = 0;
	if (map->definition)
	{
		while (map->definition[iter.y])
			free(map->definition[iter.y++]);
		free(map->definition);
	}
	if (map->path)
		free(map->path);
	free(map);
}

t_sl_map	*get_map_ctx(void)
{
	return (get_context(CONTEXT_ID_MAP,
			(void *(*)(void))ctx_create_map,
		(void (*)(void *))ctx_free_map));
}
