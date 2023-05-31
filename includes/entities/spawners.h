/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawners.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:51:17 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:52:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAWNERS_H
# define SPAWNERS_H

# include "registry.h"

t_sl_entity	*sl_entities_spawn_player(\
	t_sl_entity_registry *registry, \
	t_vec2 pos \
);
t_sl_entity	*sl_entities_spawn_exit(\
	t_sl_entity_registry *registry, \
	t_vec2 pos \
);
t_sl_entity	*sl_entities_spawn_collectible(\
	t_sl_entity_registry *registry, \
	t_vec2 pos \
);
t_sl_entity	*sl_entities_spawn_patrol(\
	t_sl_entity_registry *registry, \
	t_vec2 pos \
);

#endif
