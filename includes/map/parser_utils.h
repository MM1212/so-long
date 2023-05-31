/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:12:03 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:24:18 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include <libft.h>

# define ERROR_MAP_NOT_FOUND "Failed to load map!\n \
It might not exist or be corrupted: "
# define ERROR_MAP_NOT_COVERED_IN_WALLS "Failed to load map!\n \
It isn't fully covered in walls at line: "
# define ERR_MAP_NOT_RECT "Failed to load map!\n \
The map provided isn't rectangular \
(all lines dont have the same length): "
# define ERR_ROW_INVALID_TILE "Failed to load map!\n \
The map provided contains invalid tiles: "

bool	sl_map_parser_validate_rows(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd, \
	char *map_path \
);
bool	sl_map_parser_validate_row_length(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd, \
	char *map_path \
);
bool	sl_map_parser_validate_wall_coverage(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd, \
	char *map_path \
);
void	sl_map_parser_add_row_to_list(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd \
);
bool	sl_map_parser_validate_last_row(\
	t_list **tmp_tile_rows, \
	char *line, \
	int fd \
);

#endif
