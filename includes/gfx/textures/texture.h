/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 05:47:50 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:22:22 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "gfx/sprites/sprite.h"
# include <std.h>

typedef struct s_sl_texture
{
	char		*tag;
	t_sl_sprite	**sprites;
	size_t		size;
	size_t		current;
	bool		animated;
	short		frame_duration;
	char		*def_path;
}				t_sl_texture;

bool			sl_new_texture(char *def_path, t_sl_texture *texture);
t_sl_sprite		*sl_get_current_sprite(t_sl_texture *texture);
void			sl_switch_to_next_sprite(t_sl_texture *texture);
/*
	Free's the texture contents;
	Since each texture is a part of the Texture Manager,
	we don't need to free the texture itself.
 */
void			sl_texture_destroy(t_sl_texture *texture);

#endif
