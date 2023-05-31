/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:06:20 by martiper          #+#    #+#             */
/*   Updated: 2023/05/10 22:52:25 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H
# ifndef SPRITE_SIZE
#  define SPRITE_SIZE 64
# endif
# include <gfx/image.h>
# include <math/vec2.h>
# include <mlx.h>

typedef struct s_sl_sprite
{
	char		*path;
	t_vec2		dimensions;
	t_mlx_image	*image;
}				t_sl_sprite;

/*
		* Loads a sprite from a file if not already in the registry.
		* Returns a pointer to the sprite.
 */
t_sl_sprite		*sl_load_sprite(char *path);
void			sl_free_sprite(t_sl_sprite *sprite);

#endif
