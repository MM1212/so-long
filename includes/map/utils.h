/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:35:40 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:22:24 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map/defs.h"

char	*sl_map_tile_get_tex_manager(t_sl_tile_type t_type);
void	sl_map_log(t_sl_map *map);
bool	sl_map_is_a_solid_wall(char *str);
bool	sl_map_is_covered_in_walls(char *str);
void	sl_map_cleanup_load(t_list	**tmp_tile_rows, int fd, char *line);

#endif
