/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:11:23 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:24:03 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"
#include "map/parser.h"
#include "map/parser_utils.h"
#include "map/utils.h"
#include <gfx/textures/manager.h>
#include <utils/error.h>
#include <utils/log.h>
#include <std.h>

bool	sl_map_parser_validate_rows(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd, \
	char *map_path \
)
{
	while (line)
	{
		if (!sl_map_is_row_valid(line))
		{
			sl_map_cleanup_load(tmp_tile_rows, fd, line);
			return ((bool)sl_error(ERR_ROW_INVALID_TILE, map_path));
		}
		if (!sl_map_parser_validate_row_length(\
			tmp_tile_rows, line, \
			fd, map_path \
		))
			return (false);
		if (!sl_map_parser_validate_wall_coverage(\
			tmp_tile_rows, line, \
			fd, map_path \
		))
			return (false);
		sl_map_parser_add_row_to_list(tmp_tile_rows, line, fd);
		line = get_next_line(fd);
	}
	return (true);
}

bool	sl_map_parser_validate_row_length(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd, \
	char *map_path \
)
{
	t_list	*node;

	node = ft_lstlast(*tmp_tile_rows);
	if (node && ft_strlen(node->content) != ft_strlen(line))
	{
		sl_map_cleanup_load(tmp_tile_rows, fd, line);
		return ((bool)sl_error(ERR_MAP_NOT_RECT, map_path));
	}
	return (true);
}

bool	sl_map_parser_validate_wall_coverage(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd, \
	char *map_path \
)
{
	int	count;

	count = ft_lstsize(*tmp_tile_rows);
	if (\
		(count == 0 && !sl_map_is_a_solid_wall(line)) || \
		(count > 0 && !sl_map_is_covered_in_walls(line)) \
	)
	{
		sl_map_cleanup_load(tmp_tile_rows, fd, line);
		return ((bool)sl_error(ERROR_MAP_NOT_COVERED_IN_WALLS, map_path));
	}
	return (true);
}

void	sl_map_parser_add_row_to_list(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd \
)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (!node)
	{
		sl_map_cleanup_load(tmp_tile_rows, fd, line);
		return ;
	}
	ft_lstadd_back(tmp_tile_rows, node);
}

bool	sl_map_parser_validate_last_row(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd \
)
{
	t_list	*node;

	node = ft_lstlast(*tmp_tile_rows);
	if (!sl_map_is_a_solid_wall(node->content))
	{
		sl_map_cleanup_load(tmp_tile_rows, fd, NULL);
		return ((bool)sl_error(ERROR_MAP_NOT_COVERED_IN_WALLS, line));
	}
	return (true);
}
