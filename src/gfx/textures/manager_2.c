/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:08:06 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 12:08:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/textures/manager.h"
#include <utils/log.h>

t_sl_texture	*sl_get_texture_from_tag(\
	t_sl_texture_manager *texm, \
	char *tag \
)
{
	t_sl_texture	*texture;

	texture = texm->textures;
	while (texture)
	{
		if (ft_strcmp(texture->tag, tag) == 0)
			return (texture);
		texture++;
	}
	return (NULL);
}

void	sl_switch_to_texture(
	t_sl_texture_manager *texm,
	char *tag)
{
	t_sl_texture	*texture;

	if (ft_strcmp(texm->current->tag, tag) == 0)
		return ;
	texture = sl_get_texture_from_tag(texm, tag);
	if (texture)
		texm->current = texture;
	else
	{
		ft_printf(
			LOG_ERROR
			"Attempted to switch a texture tagged %s \
			that doesn't exist: TexM: %s\n",
			tag,
			texm->def_path);
	}
}
