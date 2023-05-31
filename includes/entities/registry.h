/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:07:11 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 15:25:00 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGISTRY_H
# define REGISTRY_H

# include "entity.h"
# include <std.h>

typedef struct s_sl_new_entity
{
	t_sl_entity_type	type;
	char				*tag;
	t_vec2				position;
	char				*texm_def_path;
	void				*data;
}	t_sl_new_entity;

typedef struct s_sl_entity_registry
{
	t_list				*entities;
	t_sl_entity			*player;
	t_sl_entity			*(*new)(t_sl_new_entity);
	t_sl_entity			*(*get)(size_t id);
	t_sl_entity			*(*get_at)(t_vec2 position);
	t_sl_entity			*(*get_by_tag)(char *tag);
	bool				(*delete)(t_sl_entity *);
}						t_sl_entity_registry;

t_sl_entity_registry	*get_entity_registry_ctx(void);
t_sl_entity				*sl_entity_registry_new_entity(\
	t_sl_new_entity new_entity \
);
t_sl_entity				*sl_entity_registry_get_entity(
							size_t id);
t_sl_entity				*sl_entity_registry_get_entity_at(
							t_vec2 position);
t_sl_entity				*sl_entity_registry_get_entity_by_tag(
							char *tag);
bool					sl_entity_registry_delete_entity(t_sl_entity *entity);

#endif
