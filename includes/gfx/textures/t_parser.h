/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:41:34 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:44:59 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PARSER_H
# define T_PARSER_H

# include "gfx/textures/texture.h"
# include <gfx/sprites/store.h>
# include <std.h>
# include <utils/error.h>
# include <utils/log.h>

# define FILE_NOT_FOUND "Failed to load tex definition file.\n \
File not found or corrupted: "
# define TEX_TAG_FAILED "Failed to load tex definition file.\n \
Could not parse tex tag: "
# define TEX_SPRITE_COUNT_FAILED "Failed to load tex definition file.\n \
Could not parse tex sprite count: "
# define TEX_SPRITE_ALLOC_FAILED "Failed to load tex definition file.\n \
Could not alloc for sprite ptrs: "
# define TEX_ANIMATOR_FAILED "Failed to load tex definition file.\n \
Could not parse tex anim duration: "
# define TEX_SPRITE_LOAD_FAILED "Failed to load tex definition file.\n \
Could not load a sprite for: "

void	*sl_textures_internal_parse_texture_tag(\
	int fd, \
	char **line, \
	t_sl_texture *texture \
);
void	*sl_textures_internal_parse_texture_size(\
	int fd, \
	char **line, \
	t_sl_texture *texture \
);
bool	sl_textures_internal_parse_texture_sprite(\
	char *line, \
	t_sl_texture *texture, \
	size_t count \
);
void	*sl_textures_internal_parse_texture_anim_duration(\
	int fd, \
	char **line, \
	t_sl_texture *texture \
);

#endif
