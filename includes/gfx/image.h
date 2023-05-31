/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:24:15 by martiper          #+#    #+#             */
/*   Updated: 2023/05/31 12:35:36 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "color.h"
# include <gfx/def.h>
# include <math/vec2.h>
# include <std.h>

typedef struct s_mlx_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	size_t		width;
	size_t		height;
}				t_mlx_image;

t_mlx_image		*gfx_create_image_buffer(\
	t_mlx_instance_ptr mlx, \
	int width, \
	int height \
);

void			gfx_put_pixel_in_buffer(\
	t_mlx_image *image, \
	t_vec2 pos, \
	t_gfx_color color, \
	bool draw_black \
);

void			gfx_put_pixel_in_buffer_2(\
	t_mlx_image *image, \
	t_vec2 pos, \
	unsigned int color, \
	bool draw_black \
);

void			gfx_draw_image_to_window(\
	t_mlx_instance_ptr mlx, \
	t_mlx_window_ptr win, \
	t_mlx_image *image, \
	t_vec2 pos \
);

void			gfx_clear_image(t_mlx_image *image);

unsigned int	gfx_get_pixel_color_from_buffer(\
	t_mlx_image *image, \
	int x, \
	int y \
);

void			gfx_resize_image(\
	t_mlx_instance_ptr *mlx, \
	t_mlx_image **image_ptr, \
	t_vec2 new_size \
);
#endif
