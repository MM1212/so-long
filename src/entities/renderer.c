/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:09:18 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:46:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/registry.h"
#include "entities/renderer.h"
#include <camera/camera.h>
#include <gfx/textures/manager.h>

void	sl_render_entities(void)
{
	t_sl_entity_registry	*registry;
	t_list					*iter;
	t_sl_entity				*entity;

	registry = get_entity_registry_ctx();
	iter = registry->entities;
	while (iter)
	{
		entity = iter->content;
		if (entity->type != SL_ENTITY_PLAYER)
			sl_render_texture(entity->texm, entity->transform.position);
		iter = iter->next;
	}
	sl_render_texture(\
		registry->player->texm, \
		registry->player->transform.position \
	);
}

void	sl_handle_entities_animations(void)
{
	t_sl_entity_registry	*registry;
	t_list					*iter;
	t_sl_entity				*entity;
	t_sl_camera				*cam;

	registry = get_entity_registry_ctx();
	cam = get_camera_ctx();
	iter = registry->entities;
	while (iter)
	{
		entity = iter->content;
		if (cam->is_in_view(entity->transform.position))
			sl_handle_texture_animation(entity->texm);
		iter = iter->next;
	}
}
