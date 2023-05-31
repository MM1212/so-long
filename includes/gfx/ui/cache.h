/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:34:08 by martiper          #+#    #+#             */
/*   Updated: 2023/05/07 19:41:18 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CACHE_H
# define CACHE_H

# include "text.h"

/*
	This prevents us computing a string every frame
	We need to track all ui element cache into a struct
	so that we can cleanup everything at the end
 */
typedef struct s_gfx_ui_elements
{
	t_gfx_ui_text_cache	fps;
	t_gfx_ui_text_cache	time;
	t_gfx_ui_text_cache	collectible;
	t_gfx_ui_text_cache	moves;
	t_gfx_ui_text_cache	enemies;
	t_gfx_ui_text_cache	collectibles_spawned;
}	t_gfx_ui_elements;

t_gfx_ui_elements	*get_ui_elements_ctx(void);

#endif