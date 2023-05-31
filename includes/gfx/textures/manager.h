/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 05:46:38 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 12:57:45 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H

# include "animator.h"
# include "texture.h"
# include <math/vec2.h>

typedef struct s_sl_texture_manager
{
	t_sl_texture			*textures;
	size_t					size;
	t_sl_texture			*current;
	t_sl_texture_animator	*animator;
	char					*def_path;
}	t_sl_texture_manager;

t_sl_texture_manager	*sl_new_texture_manager(char *texm_def_path);
void					sl_render_texture(\
	t_sl_texture_manager *texm, \
	t_vec2 pos \
);
t_sl_texture			*sl_get_texture_from_tag(\
	t_sl_texture_manager *texm, \
	char *tag \
);
void					sl_switch_to_texture( \
	t_sl_texture_manager *texm, \
	char *tag \
);
void					gfx_put_texture_into_render_buffer(\
	t_mlx_image *buffer, \
	t_sl_texture *tex, \
	t_vec2 pos \
);
bool					sl_handle_texture_animation(\
	t_sl_texture_manager *texm \
);
void					sl_texture_manager_destroy(\
	t_sl_texture_manager *texm \
);
void					*sl_texture_manager_internal_stop_parser(\
	t_sl_texture_manager *texm, \
	char *def_line, \
	char *msg, char *param \
);

#endif
