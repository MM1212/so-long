/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:17:10 by martiper          #+#    #+#             */
/*   Updated: 2023/05/10 22:32:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "gfx/image.h"
# include <math/vec2.h>
# include <std.h>

# define WINDOW_DEFAULT_FONT_SIZE 12
# ifndef WINDOW_UI_SCALE
#  define WINDOW_UI_SCALE 1.0
# endif

typedef struct s_sl_window
{
	void		*mlx;
	void		*win;
	t_mlx_image	*render_buffer;
	t_vec2		dimensions;
	size_t		font_size;
}				t_sl_window;

t_sl_window		*get_window_ctx(void);
bool			gfx_define_window(size_t width, size_t height);
void			gfx_window_management_hook(void);

#endif
