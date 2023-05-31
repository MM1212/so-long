/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vignette.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:01:51 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:37:16 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIGNETTE_H
# define VIGNETTE_H

# include "image.h"
# include <math.h>
# include <math/vec2.h>

# ifndef GFX_VIGNETTE_ENABLED
#  define GFX_VIGNETTE_ENABLED 0
# endif
# ifndef GFX_VIGNETTE_INTENSITY
#  define GFX_VIGNETTE_INTENSITY 100.0f
# endif
# ifndef GFX_VIGNETTE_RADIUS
#  define GFX_VIGNETTE_RADIUS 0.75f
# endif

void	gfx_apply_vignette(\
	t_mlx_image *render_buffer \
);

#endif
