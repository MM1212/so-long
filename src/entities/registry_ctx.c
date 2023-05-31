/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registry_ctx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:34:57 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:35:17 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context/context.h>
#include "entities/registry.h"

static t_sl_entity_registry	*entity_registry_create(void)
{
	t_sl_entity_registry	*ent_reg;

	ent_reg = ft_calloc(1, sizeof(t_sl_entity_registry));
	if (!ent_reg)
		return (NULL);
	ent_reg->player = NULL;
	ent_reg->new = sl_entity_registry_new_entity;
	ent_reg->get = sl_entity_registry_get_entity;
	ent_reg->get_at = sl_entity_registry_get_entity_at;
	ent_reg->get_by_tag = sl_entity_registry_get_entity_by_tag;
	ent_reg->delete = sl_entity_registry_delete_entity;
	return (ent_reg);
}

static void	entity_registry_destroy(t_sl_entity_registry *ent_reg)
{
	ft_lstclear(&ent_reg->entities, (void (*)(void *))sl_entity_cleanup);
	free(ent_reg);
}

t_sl_entity_registry	*get_entity_registry_ctx(void)
{
	return (
		get_context(CONTEXT_ID_ENT_REGISTRY,
			(void *(*)(void))entity_registry_create,
		(void (*)(void *))entity_registry_destroy));
}
