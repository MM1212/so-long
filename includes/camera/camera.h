/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:47:44 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:55:23 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <std.h>
# include "math/vec2.h"

# ifndef CAMERA_FOV
#  define CAMERA_FOV "6x4"
# endif

/*
	interface Camera {
		vec2 fov; // the size of fov in width/height
		vec2 pos; // the pos where to place the fov box
	}
 */
typedef struct s_sl_camera
{
	t_vec2	fov;
	t_vec2	pos;
	void	(*update_position)(void);
	bool	(*is_in_view)(t_vec2 position);
}			t_sl_camera;

t_sl_camera	*get_camera_ctx(void);
void		sl_camera_update_position(void);
bool		sl_camera_is_in_view(t_vec2 position);

#endif
