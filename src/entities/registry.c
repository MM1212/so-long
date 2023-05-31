/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:16:09 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:38:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/registry.h"
#include <context/context.h>

static bool	define_entity(\
	t_sl_entity *entity, \
	size_t id, \
	t_sl_new_entity new \
)
{
	entity->id = id;
	entity->type = new.type;
	entity->tag = new.tag;
	entity->data = new.data;
	entity->transform.position = new.position;
	entity->transform.direction = vec2(0, 0);
	entity->transform.speed = vec2(0, 0);
	entity->texm = sl_new_texture_manager(new.texm_def_path);
	if (!entity->texm)
	{
		sl_entity_cleanup(entity);
		return (false);
	}
	return (true);
}

/*
	ATTENTON: tag member MUST BE heap allocated. THANKS.
 */
t_sl_entity	*sl_entity_registry_new_entity(
	t_sl_new_entity new
)
{
	static size_t			ent_count;
	t_sl_entity				*entity;
	t_list					*node;
	t_sl_entity_registry	*registry;

	registry = get_entity_registry_ctx();
	if (!registry)
		return (NULL);
	if (registry->get_by_tag(new.tag))
		return (NULL);
	entity = ft_calloc(1, sizeof(t_sl_entity));
	if (!entity)
		return (NULL);
	if (!define_entity(entity, ent_count++, new))
		return (NULL);
	node = ft_lstnew(entity);
	if (!node)
	{
		sl_entity_cleanup(entity);
		return (NULL);
	}
	ft_lstadd_back(&registry->entities, node);
	return (entity);
}

bool	sl_entity_registry_delete_entity(t_sl_entity *entity)
{
	t_list					*node;
	t_sl_entity_registry	*registry;
	t_list					*iter;

	node = NULL;
	registry = get_entity_registry_ctx();
	if (!registry)
		return (NULL);
	iter = registry->entities;
	while (iter)
	{
		if (((t_sl_entity *)iter->content)->id == entity->id)
		{
			node = iter;
			break ;
		}
		iter = iter->next;
	}
	if (!node)
		return (false);
	ft_lstremove(&registry->entities, node,
		(void (*)(void *))sl_entity_cleanup);
	return (true);
}
