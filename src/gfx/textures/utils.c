/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:05:54 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 12:56:06 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/sprites/sprite.h"
#include "gfx/textures/texture.h"
#include "gfx/textures/manager.h"
#include <utils/error.h>

t_sl_sprite	*sl_get_current_sprite(t_sl_texture *texture)
{
	return (texture->sprites[texture->current]);
}

void	sl_switch_to_next_sprite(t_sl_texture *texture)
{
	texture->current++;
	if (texture->current == texture->size)
		texture->current = 0;
}

void	*sl_texture_manager_internal_stop_parser(\
	t_sl_texture_manager *texm, \
	char *def_line, \
	char *msg, char *param \
)
{
	if (texm)
		sl_texture_manager_destroy(texm);
	if (def_line)
		free(def_line);
	return (sl_error(msg, param));
}
