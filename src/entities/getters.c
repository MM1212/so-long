/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:09:47 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 15:09:56 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/registry.h"

t_sl_entity	*sl_entity_registry_get_entity(
	size_t id)
{
	t_sl_entity_registry	*registry;
	t_list					*entity;

	registry = get_entity_registry_ctx();
	if (!registry)
		return (NULL);
	entity = registry->entities;
	while (entity)
	{
		if (((t_sl_entity *)entity->content)->id == id)
			return (((t_sl_entity *)entity->content));
		entity = entity->next;
	}
	return (NULL);
}

t_sl_entity	*sl_entity_registry_get_entity_at(
	t_vec2 position)
{
	t_sl_entity_registry	*registry;
	t_list					*entity;
	t_transform				*transform;

	registry = get_entity_registry_ctx();
	if (!registry)
		return (NULL);
	entity = registry->entities;
	while (entity)
	{
		transform = &((t_sl_entity *)entity->content)->transform;
		if (\
			transform->position.x == position.x && \
			transform->position.y == position.y \
		)
			return (((t_sl_entity *)entity->content));
		entity = entity->next;
	}
	return (NULL);
}

t_sl_entity	*sl_entity_registry_get_entity_by_tag(
	char *tag)
{
	t_sl_entity_registry	*registry;
	t_list					*entity;

	registry = get_entity_registry_ctx();
	if (!registry)
		return (NULL);
	entity = registry->entities;
	while (entity)
	{
		if (ft_strcmp(((t_sl_entity *)entity->content)->tag, tag) == 0)
			return (((t_sl_entity *)entity->content));
		entity = entity->next;
	}
	return (NULL);
}
