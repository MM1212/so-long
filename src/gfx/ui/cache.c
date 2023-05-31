/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:38:54 by martiper          #+#    #+#             */
/*   Updated: 2023/05/07 19:43:23 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/ui/cache.h"
#include <context/context.h>

static t_gfx_ui_elements	*ui_elements_create(void)
{
	t_gfx_ui_elements	*elements;

	elements = ft_calloc(1, sizeof(t_gfx_ui_elements));
	if (!elements)
		return (NULL);
	return (elements);
}

static void	ui_elements_destroy(t_gfx_ui_elements *elements)
{
	if (!elements)
		return ;
	if (elements->fps.str)
		free(elements->fps.str);
	if (elements->time.str)
		free(elements->time.str);
	if (elements->collectible.str)
		free(elements->collectible.str);
	if (elements->moves.str)
		free(elements->moves.str);
	if (elements->enemies.str)
		free(elements->enemies.str);
	if (elements->collectibles_spawned.str)
		free(elements->collectibles_spawned.str);
	free(elements);
}

t_gfx_ui_elements	*get_ui_elements_ctx(void)
{
	return (get_context(\
		CONTEXT_ID_UI_ELEMENTS, \
		(void *(*)(void))ui_elements_create, \
		(void (*)(void *))ui_elements_destroy \
	));
}
