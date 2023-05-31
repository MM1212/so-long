/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_renderer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:31:21 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:04:12 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_RENDERER_H
# define G_RENDERER_H

# include <camera/camera.h>
# include <std.h>

typedef struct s_gfx_renderer
{
	bool		should_render;
	void		(*ask_to_render)(void);
	void		(*mark_as_rendered)(void);
	t_sl_camera	*(*get_cam)();
	int			(*render_thread)(void);
}				t_gfx_renderer;

t_gfx_renderer	*get_renderer_ctx(void);
int				gfx_defs_internal_renderer_render_thread(void);

#endif
