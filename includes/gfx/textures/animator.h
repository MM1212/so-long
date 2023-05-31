/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 05:52:17 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:58:33 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATOR_H
# define ANIMATOR_H

# include "gfx/textures/texture.h"
# include <std.h>

typedef struct s_sl_texture_animator
{
	float	frame_count;
}			t_sl_texture_animator;

bool	sl_animate_texture(\
	t_sl_texture_animator *animator, \
	t_sl_texture *texture \
);

#endif
