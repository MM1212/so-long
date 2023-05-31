/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:38:12 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:37:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/textures/manager.h"
#include "gfx/textures/texture.h"
#include <utils/log.h>
#include <std.h>

void	sl_texture_destroy(t_sl_texture *texture)
{
	if (!texture)
		return ;
	if (texture->def_path)
		free(texture->def_path);
	if (texture->tag)
		free(texture->tag);
	if (texture->sprites)
		free(texture->sprites);
}

void	sl_texture_manager_destroy(t_sl_texture_manager *texm)
{
	size_t	idx;

	idx = 0;
	if (!texm)
		return ;
	if (texm->def_path)
		free(texm->def_path);
	if (texm->textures)
	{
		while (idx < texm->size)
			sl_texture_destroy(&texm->textures[idx++]);
		free(texm->textures);
	}
	if (texm->animator)
		free(texm->animator);
	free(texm);
}
