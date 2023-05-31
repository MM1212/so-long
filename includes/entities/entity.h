/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:54:55 by martiper          #+#    #+#             */
/*   Updated: 2023/05/11 11:57:16 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "gfx/textures/manager.h"
# include "map/defs.h"
# include "math/transform.h"
# include <stdlib.h>

typedef enum e_sl_entity_type
{
	SL_ENTITY_PLAYER,
	SL_ENTITY_PATROL,
	SL_ENTITY_COLLECTIBLE,
	SL_ENTITY_EXIT,
}							t_sl_entity_type;

typedef struct s_sl_entity
{
	size_t					id;
	t_sl_entity_type		type;
	char					*tag;
	t_transform				transform;
	t_sl_texture_manager	*texm;
	void					*data;
}							t_sl_entity;

void	sl_entity_cleanup(t_sl_entity *entity);
t_vec2	sl_entity_compute_new_position(t_sl_entity *entity);
void	sl_entity_move(\
	t_sl_entity *entity, \
	bool attempt_to_render, \
	bool update_cam \
);
void	sl_entity_move_to(\
	t_sl_entity *entity, \
	t_vec2 new_pos, \
	bool attempt_to_render, \
	bool update_cam \
);

#endif
