/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:50:38 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 13:33:26 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAWN_H
# define SPAWN_H

# include <std.h>

bool	sl_entities_spawn(void);
bool	sl_entities_spawn_load_map(\
	t_sl_map *map, \
	t_sl_entity_registry *registry \
);

#endif
