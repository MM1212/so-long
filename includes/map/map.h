/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:19:44 by martiper          #+#    #+#             */
/*   Updated: 2023/04/23 12:01:35 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "defs.h"
# include "tile.h"
# include <math/vec2.h>
# include <stddef.h>

t_sl_map		*get_map_ctx(void);
t_sl_map_tile	*sl_map_get_tile(t_vec2 pos);
bool			sl_map_is_on_bounds(t_vec2 pos);
bool			sl_map_load(char *map_path);

#endif