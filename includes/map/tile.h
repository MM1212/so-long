/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:32:51 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 20:25:09 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_H
# define TILE_H

# include "map/defs.h"

t_sl_tile_type	sl_map_get_tile_type_from_char(char c);
void			sl_map_tile_destroy(t_sl_map_tile *tile);
bool			sl_map_is_row_valid(const char *row);

#endif
