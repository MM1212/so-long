/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:10:53 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:50:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <context/context.h>

static t_sl_entity	*get_player(void)
{
	t_sl_entity_registry	*ent_reg;

	ent_reg = get_entity_registry_ctx();
	if (!ent_reg)
		return (NULL);
	return (ent_reg->player);
}

static t_sl_game	*create_game(void)
{
	t_sl_game	*game;

	game = ft_calloc(1, sizeof(t_sl_game));
	if (!game)
		return (NULL);
	game->get_window = get_window_ctx;
	game->get_sprite_store = get_sprite_store_ctx;
	game->get_map = get_map_ctx;
	game->get_renderer = get_renderer_ctx;
	game->get_entity_registry = get_entity_registry_ctx;
	game->get_camera = get_camera_ctx;
	game->get_player = get_player;
	game->get_events = get_event_manager_ctx;
	game->get_keys = get_key_manager_ctx;
	game->get_time = get_time_ctx;
	game->get_ui = get_ui_elements_ctx;
	return (game);
}

t_sl_game	*get_game(void)
{
	return (get_context(\
		CONTEXT_ID_GAME, \
		(void *(*)(void))create_game, \
		free \
	));
}
