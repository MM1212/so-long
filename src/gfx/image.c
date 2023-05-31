/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:32:39 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 15:42:28 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/gfx.h"

t_mlx_image	*gfx_create_image_buffer(
	t_mlx_instance_ptr mlx, int width, int height)
{
	t_mlx_image	*image;

	if (!mlx)
		return (NULL);
	image = ft_calloc(1, sizeof(t_mlx_image));
	if (!image)
		return (NULL);
	image->width = width;
	image->height = height;
	image->img = mlx_new_image(mlx, width, height);
	if (!image->img)
		return (image);
	image->addr = mlx_get_data_addr(\
		image->img, \
		&image->bits_per_pixel, \
		&image->line_length, \
		&image->endian \
	);
	return (image);
}

unsigned int	gfx_get_pixel_color_from_buffer(
	t_mlx_image *image,
	int x,
	int y)
{
	char	*dst;

	if (!image || !image->addr)
		return (0);
	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel
				/ 8));
	return (*(unsigned int *)dst);
}

void	gfx_put_pixel_in_buffer_2(
	t_mlx_image *image,
	t_vec2 pos,
	unsigned int color,
	bool draw_black
)
{
	char	*dst;

	if (!image || !image->addr)
		return ;
	if (!draw_black && color == 0xFF000000)
		return ;
	if (
		pos.x < 0 || (size_t)pos.x >= image->width || \
		pos.y < 0 || (size_t)pos.y >= image->height \
	)
		return ;
	dst = image->addr + \
		(\
			pos.y * image->line_length + \
			pos.x * (image->bits_per_pixel / 8) \
		);
	*(unsigned int *)dst = color;
}

void	gfx_put_pixel_in_buffer(
	t_mlx_image *image,
	t_vec2 pos,
	t_gfx_color color,
	bool draw_black
)
{
	gfx_put_pixel_in_buffer_2(image, pos, gfx_color_to_int(color), draw_black);
}
