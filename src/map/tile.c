/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:41:34 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 20:24:54 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/parser.h"
#include "map/tile.h"

t_sl_tile_type	sl_map_get_tile_type_from_char(char c)
{
	if (!sl_map_does_config_char_exist(c))
		return (-1);
	if (c == MAP_CONFIG_TYPE_WALL)
		return (MAP_TILE_WALL);
	return (MAP_TILE_FREE_SPACE);
}

bool	sl_map_is_row_valid(const char *row)
{
	while (*row)
		if (!sl_map_does_config_char_exist(*row++))
			return (false);
	return (true);
}

void	sl_map_tile_destroy(t_sl_map_tile *tile)
{
	if (!tile || !tile->texm)
		return ;
	sl_texture_manager_destroy(tile->texm);
}
