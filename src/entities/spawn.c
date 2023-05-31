/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:23 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:33:53 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/registry.h"
#include "entities/spawn.h"
#include <map/map.h>

static int	compare_entities(t_sl_entity *a, t_sl_entity *b)
{
	return (b->type - a->type);
}

static void	sort_entities(t_sl_entity_registry *registry)
{
	ft_lstsort(registry->entities, (int (*)(void *, void *))compare_entities);
}

bool	sl_entities_spawn(void)
{
	t_sl_map					*map;
	t_sl_entity_registry		*registry;

	map = get_map_ctx();
	if (!map)
		return (false);
	registry = get_entity_registry_ctx();
	if (!registry)
		return (false);
	if (!sl_entities_spawn_load_map(map, registry))
		return (false);
	sort_entities(registry);
	return (true);
}
