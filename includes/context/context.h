/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:53:44 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:50:40 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H
# define MAX_CONTEXTS 16
# include <stddef.h>

typedef enum e_context_ids
{
	CONTEXT_ID_UI_ELEMENTS,
	CONTEXT_ID_EVENT_MANAGER,
	CONTEXT_ID_RENDERER,
	CONTEXT_ID_TIME,
	CONTEXT_ID_ENT_REGISTRY,
	CONTEXT_ID_KEYS_MANAGER,
	CONTEXT_ID_MAP,
	CONTEXT_ID_SPRITE_STORE,
	CONTEXT_ID_CAMERA,
	CONTEXT_ID_WINDOW,
	CONTEXT_ID_GAME
}	t_context_ids;

void	*get_context(int ctx_id, void *(*init)(void), void (*destroy)(void *));
void	*get_context_destructor(int ctx_id, void (*destroy)(void *));
void	destroy_context(int ctx_id);
void	destroy_all_contexts(void);

#endif
