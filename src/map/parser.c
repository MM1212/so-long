/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:46:04 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:24:34 by martiper         ###   ########.fr       */
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

bool	sl_map_does_config_char_exist(char c)
{
	return (
		c == MAP_CONFIG_TYPE_WALL || c == MAP_CONFIG_TYPE_FREE_SPACE
		|| c == MAP_CONFIG_TYPE_EXIT || c == MAP_CONFIG_TYPE_COLLECTIBLE
		|| c == MAP_CONFIG_TYPE_PLAYER || c == MAP_CONFIG_TYPE_PATROL);
}

/* t_list	*sl_map_generate_props(char *map_path, t_vec2 *dims)
{
	t_list	*tmp_tile_rows;
	t_list	*node;
	int		fd;
	int		count;
	char	*line;

	tmp_tile_rows = NULL;
	if (!map_path || !ft_str_endswith(map_path, ".ber"))
		return (sl_error(ERROR_MAP_NOT_FOUND, map_path));
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		sl_map_cleanup_load(&tmp_tile_rows, fd, NULL);
		return (sl_error(ERROR_MAP_NOT_FOUND, map_path));
	}
	line = get_next_line(fd);
	if (!line)
	{
		sl_map_cleanup_load(&tmp_tile_rows, fd, line);
		return (sl_error(ERROR_MAP_NOT_FOUND, map_path));
	}
	while (line)
	{
		if (!sl_map_is_row_valid(line))
		{
			sl_map_cleanup_load(&tmp_tile_rows, fd, line);
			return (sl_error(ERR_ROW_INVALID_TILE, map_path));
		}
		node = ft_lstlast(tmp_tile_rows);
		if (node && ft_strlen(node->content) != ft_strlen(line))
		{
			sl_map_cleanup_load(&tmp_tile_rows, fd, line);
			return (sl_error(ERR_MAP_NOT_RECT, map_path));
		}
		count = ft_lstsize(tmp_tile_rows);
		if (
			(count == 0 && !sl_map_is_a_solid_wall(line)) || (count > 0
				&& !sl_map_is_covered_in_walls(line)))
		{
			sl_map_cleanup_load(&tmp_tile_rows, fd, line);
			return (sl_error(ERROR_MAP_NOT_COVERED_IN_WALLS, map_path));
		}
		node = ft_lstnew(line);
		if (!node)
		{
			sl_map_cleanup_load(&tmp_tile_rows, fd, line);
			return (NULL);
		}
		ft_lstadd_back(&tmp_tile_rows, node);
		line = get_next_line(fd);
	}
	if (!sl_map_is_a_solid_wall(node->content))
	{
		sl_map_cleanup_load(&tmp_tile_rows, fd, NULL);
		return (sl_error(ERROR_MAP_NOT_COVERED_IN_WALLS, line));
	}
	dims->x = ft_strlen(node->content);
	dims->y = ft_lstsize(tmp_tile_rows);
	close(fd);
	return (tmp_tile_rows);
} */

static int	open_map_file(char *map_path, t_list **tmp_tile_rows)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		sl_map_cleanup_load(tmp_tile_rows, fd, NULL);
		return (-1);
	}
	return (fd);
}

t_list	*sl_map_generate_props(char *map_path, t_vec2 *dims)
{
	t_list	*tmp_tile_rows;
	int		fd;
	char	*line;

	tmp_tile_rows = NULL;
	if (!map_path || !ft_str_endswith(map_path, ".ber"))
		return (sl_error(ERROR_MAP_NOT_FOUND, map_path));
	fd = open_map_file(map_path, &tmp_tile_rows);
	if (fd == -1)
		return (sl_error(ERROR_MAP_NOT_FOUND, map_path));
	line = get_next_line(fd);
	if (!line)
	{
		sl_map_cleanup_load(&tmp_tile_rows, fd, line);
		return (sl_error(ERROR_MAP_NOT_FOUND, map_path));
	}
	if (!sl_map_parser_validate_rows(&tmp_tile_rows, line, fd, map_path))
		return (NULL);
	if (!sl_map_parser_validate_last_row(&tmp_tile_rows, line, fd))
		return (NULL);
	dims->x = ft_strlen(ft_lstlast(tmp_tile_rows)->content);
	dims->y = ft_lstsize(tmp_tile_rows);
	close(fd);
	return (tmp_tile_rows);
}
