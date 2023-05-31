/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:10:46 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 14:22:14 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACT_H
# define INTERACT_H

# include "map/defs.h"

typedef struct s_sl_map_tile_neighbors
{
	t_sl_map_tile	*top;
	t_sl_map_tile	*right;
	t_sl_map_tile	*bottom;
	t_sl_map_tile	*left;
	t_sl_map_tile	*top_right;
	t_sl_map_tile	*top_left;
	t_sl_map_tile	*bottom_right;
	t_sl_map_tile	*bottom_left;
	bool			in_edge;
}	t_sl_map_tile_neighbors;

void					sl_map_interact_tiles(t_sl_map *map);
t_sl_map_tile_neighbors	sl_map_get_pos_data(t_sl_map *map, t_vec2 pos);

#endif
