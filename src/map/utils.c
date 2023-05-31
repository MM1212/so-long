/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:32:19 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:23:08 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/utils.h"
#include "map/parser.h"
#include <std.h>
#include <utils/log.h>
#include <utils/gnl.h>

char	*sl_map_tile_get_tex_manager(t_sl_tile_type t_type)
{
	(void)t_type;
	return ("textures/map/land/texm.slprops");
}

void	sl_map_log(t_sl_map *map)
{
	ft_printf(LOG_INFO "Map %s info!\n", map->path);
	ft_printf("- Map Size: %d x %d\n", map->size.x, map->size.y);
	ft_printf("- Map Walls: %d\n", map->features.walls);
	ft_printf("- Map Free Space: %d\n", map->features.freespace);
	ft_printf("- Map Exits: %d\n", map->features.exits);
	ft_printf("- Map Players: %d\n", map->features.players);
	ft_printf("- Map Collectibles: %d\n", map->features.collectibles);
	ft_printf("- Map Patrols: %d\n", map->features.patrols);
	ft_printf("- Map Entities: %d\n", map->features.entities);
}

bool	sl_map_is_a_solid_wall(char *str)
{
	while (*str)
	{
		if (*str != MAP_CONFIG_TYPE_WALL)
			return (false);
		str++;
	}
	return (true);
}

bool	sl_map_is_covered_in_walls(char *str)
{
	if (!str || !str[0])
		return (false);
	return (
		str[0] == MAP_CONFIG_TYPE_WALL && str[ft_strlen(str)
			- 1] == MAP_CONFIG_TYPE_WALL);
}

void	sl_map_cleanup_load(t_list	**tmp_tile_rows, int fd, char *line)
{
	if (line)
		free(line);
	if (fd != -1)
	{
		line = get_next_line(fd);
		while (line)
			gnl_next_line(fd, &line);
		close(fd);
	}
	ft_lstclear(tmp_tile_rows, free);
}
