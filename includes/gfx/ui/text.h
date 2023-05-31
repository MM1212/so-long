/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:27:39 by martiper          #+#    #+#             */
/*   Updated: 2023/05/10 22:31:27 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_H
# define TEXT_H

# include <std.h>

typedef struct s_gfx_ui_text_cache
{
	bool	defined;
	size_t	value;
	char	*str;
}	t_gfx_ui_text_cache;

void	gfx_ui_draw_text(char *str, int color, int x, int y);
void	gfx_ui_push_font_size(size_t size);

#endif
