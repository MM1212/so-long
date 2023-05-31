/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:43:44 by martiper          #+#    #+#             */
/*   Updated: 2023/05/11 11:51:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/checks.h"
#include "map/parser.h"
#include "map/interact.h"
#include <utils/error.h>

static bool	free_path_check(char **map, t_vec2 begin)
{
	if (!sl_map_is_on_bounds(vec2_mul_scal(begin, SPRITE_SIZE)))
		return (false);
	if (map[begin.y][begin.x] == MAP_CONFIG_TYPE_EXIT)
		return (true);
	else if (\
		map[begin.y][begin.x] == MAP_CONFIG_TYPE_WALL || \
		map[begin.y][begin.x] == MAP_CONFIG_TYPE_PATROL || \
		map[begin.y][begin.x] == '_')
		return (false);
	map[begin.y][begin.x] = '_';
	begin.y++;
	if (free_path_check(map, begin))
		return (true);
	begin.y -= 2;
	if (free_path_check(map, begin))
		return (true);
	begin.y++;
	begin.x++;
	if (free_path_check(map, begin))
		return (true);
	begin.x -= 2;
	if (free_path_check(map, begin))
		return (true);
	begin.x++;
	return (false);
}

static char	**duplicate_map_def(t_sl_map *map)
{
	char	**new;
	size_t	size;
	size_t	idx;

	size = map->size.y / SPRITE_SIZE;
	new = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!new)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		new[idx] = ft_strdup(map->definition[idx]);
		if (!new[idx])
		{
			ft_split_free(new);
			return (NULL);
		}
		idx++;
	}
	return (new);
}

static	bool	do_find_free_path(t_sl_map *map)
{
	t_vec2	player_pos;
	t_vec2	iter;
	char	**map_def;
	bool	ok;

	iter = vec2(0, -1);
	player_pos = vec2(-1, -1);
	while (++iter.y < map->size.y / SPRITE_SIZE)
	{
		iter.x = 0;
		while (iter.x < map->size.x / SPRITE_SIZE)
		{
			if (map->definition[iter.y][iter.x] == MAP_CONFIG_TYPE_PLAYER)
			{
				player_pos = iter;
				break ;
			}
			iter.x++;
		}
	}
	map_def = duplicate_map_def(map);
	ok = free_path_check(map_def, player_pos);
	ft_split_free(map_def);
	return (ok);
}

bool	sl_map_do_checks(t_sl_map *map)
{
	char	msg[256];
	bool	ok;

	ok = true;
	if (map->features.players != 1)
	{
		ft_sprintf(msg, 256, "Map must have exactly one player. Found %d.", \
			map->features.players);
		ok = false;
	}
	if (map->features.exits != 1)
	{
		ft_sprintf(msg, 256, "Map must have exactly one exit. Found %d.", \
			map->features.exits);
		ok = false;
	}
	if (!do_find_free_path(map))
	{
		ft_sprintf(msg, 256, \
			"Map must have a free path from player to exit.");
		ok = false;
	}
	if (!ok)
		sl_error(msg, NULL);
	return (true);
}
