/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:01:17 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:43:36 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include <gfx/textures/manager.h>
# include <math/vec2.h>
# include <std.h>

typedef struct s_sl_map_features
{
	size_t	walls;
	size_t	freespace;
	size_t	exits;
	size_t	players;
	size_t	collectibles;
	size_t	patrols;
	size_t	entities;
}	t_sl_map_features;

typedef enum e_sl_tile_type
{
	MAP_TILE_NONE = -1,
	MAP_TILE_WALL,
	MAP_TILE_FREE_SPACE
}							t_sl_tile_type;

typedef struct s_sl_map_tile
{
	size_t					id;
	t_sl_tile_type			type;
	t_vec2					position;
	t_sl_texture_manager	*texm;
}	t_sl_map_tile;

typedef struct s_sl_map
{
	t_vec2				size;
	t_sl_map_features	features;
	t_sl_map_tile		**tiles;
	char				**definition;
	char				*path;
}	t_sl_map;

#endif
