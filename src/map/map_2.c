/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:11 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 20:53:17 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/interact.h"
#include "map/map.h"
#include "map/parser.h"
#include "map/utils.h"
#include "map/checks.h"
#include <context/context.h>
#include <utils/log.h>
#include <std.h>

bool	sl_map_is_on_bounds(t_vec2 pos)
{
	t_sl_map	*map_ctx;

	map_ctx = get_map_ctx();
	if (!map_ctx)
		return (false);
	return (
		pos.x >= 0 && pos.x < map_ctx->size.x && pos.y >= 0
		&& pos.y < map_ctx->size.y);
}

t_sl_map_tile	*sl_map_get_tile(t_vec2 pos)
{
	t_sl_map	*map_ctx;

	map_ctx = get_map_ctx();
	if (!map_ctx)
		return (NULL);
	if (!sl_map_is_on_bounds(pos))
		return (NULL);
	return (&map_ctx->tiles[pos.y / SPRITE_SIZE][pos.x / SPRITE_SIZE]);
}

bool	sl_map_load(char *map_path)
{
	t_list		*tmp_rows;
	t_sl_map	*map;

	map = get_map_ctx();
	if (!map)
		return (false);
	ft_printf(
		LOG_INFO "Loading map at path %s..\n",
		map_path);
	tmp_rows = sl_map_generate_props(map_path, &map->size);
	if (!tmp_rows)
		return (false);
	ft_printf(LOG_INFO "Map loaded, computing tiles..\n");
	sl_map_compute_tiles(tmp_rows, map);
	ft_lstclear(&tmp_rows, NULL);
	if (!map->tiles)
		return (false);
	map->path = ft_strdup(map_path);
	map->size = vec2_mul_scal(map->size, SPRITE_SIZE);
	if (!sl_map_do_checks(map))
		return (false);
	sl_map_interact_tiles(map);
	ft_printf(LOG_SUCCESS "Map %s loaded!\n", map_path);
	sl_map_log(map);
	return (true);
}
