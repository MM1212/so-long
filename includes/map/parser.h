/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:43:32 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:59:01 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <std.h>
# include "map/map.h"

typedef enum e_map_configuration_type
{
	MAP_CONFIG_TYPE_WALL = '1',
	MAP_CONFIG_TYPE_FREE_SPACE = '0',
	MAP_CONFIG_TYPE_EXIT = 'E',
	MAP_CONFIG_TYPE_COLLECTIBLE = 'C',
	MAP_CONFIG_TYPE_PLAYER = 'P',
	MAP_CONFIG_TYPE_PATROL = 'M'
}		t_map_configuration_type;

bool	sl_map_does_config_char_exist(char c);
t_list	*sl_map_generate_props(char *map_path, t_vec2 *dims);
void	sl_map_compute_tiles(t_list *rows, t_sl_map *map);

#endif
