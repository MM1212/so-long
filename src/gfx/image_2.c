/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:01:20 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:02:14 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/gfx.h"

void	gfx_draw_image_to_window(
	t_mlx_instance_ptr mlx,
	t_mlx_window_ptr win,
	t_mlx_image *image,
	t_vec2 pos
)
{
	if (!mlx || !win || !image || !image->img)
		return ;
	mlx_put_image_to_window(mlx, win, image->img, pos.x, pos.y);
}

void	gfx_clear_image(
	t_mlx_image *image
)
{
	size_t			x;
	size_t			y;
	unsigned int	color;

	if (!image || !image->img)
		return ;
	color = gfx_color_to_int(gfx_new_color(0, 0, 0, 255));
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			gfx_put_pixel_in_buffer_2(image, vec2(x, y), color, true);
			x++;
		}
		y++;
	}
}

static void	resize_image(\
	t_mlx_image *image, \
	t_mlx_image *new_image, \
	t_vec2 new_size \
)
{
	t_vec2		iter;

	iter = vec2(0, 0);
	while (iter.y < new_size.y)
	{
		iter.x = 0;
		while (iter.x < new_size.x)
		{
			gfx_put_pixel_in_buffer_2(new_image, iter,
				gfx_get_pixel_color_from_buffer(image,
					(int)(iter.x * image->width / new_size.x),
					(int)(iter.y * image->height / new_size.y)),
				true);
			iter.x++;
		}
		iter.y++;
	}
}

// copy image pixels to new_image using nearest neighbor
void	gfx_resize_image(
	t_mlx_instance_ptr *mlx,
	t_mlx_image **image_ptr,
	t_vec2 new_size
)
{
	t_mlx_image	*new_image;
	t_mlx_image	*image;

	image = *image_ptr;
	new_image = gfx_create_image_buffer(mlx, new_size.x, new_size.y);
	if (!new_image || !new_image->img)
		return ;
	gfx_clear_image(new_image);
	resize_image(image, new_image, new_size);
	mlx_destroy_image(mlx, image->img);
	free(image);
	*image_ptr = new_image;
}
