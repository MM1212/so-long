/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 04:13:05 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:50:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define WINDOW_TITLE "So Long"

# ifndef PLAYER_SPEED_MULTIPLIER
#  define PLAYER_SPEED_MULTIPLIER 0.2
# endif

# include "camera/camera.h"
# include "entities/registry.h"
# include "entities/spawn.h"
# include "events.h"
# include "gfx/g_renderer.h"
# include "gfx/sprites/store.h"
# include "gfx/window.h"
# include "gfx/ui/text.h"
# include "gfx/ui/cache.h"
# include "keys/keys.h"
# include "map/map.h"
# include "std.h"
# include "time/time.h"

typedef struct s_sl_game_stats
{
	size_t	collectibles;
	size_t	moves;
	size_t	time;
}				t_sl_game_stats;

typedef struct s_sl_game
{
	t_sl_game_stats			stats;
	t_sl_window				*(*get_window)(void);
	t_sl_sprite_store		*(*get_sprite_store)(void);
	t_sl_map				*(*get_map)(void);
	t_gfx_renderer			*(*get_renderer)(void);
	t_sl_entity_registry	*(*get_entity_registry)(void);
	t_sl_camera				*(*get_camera)(void);
	t_sl_entity				*(*get_player)(void);
	t_sl_key_manager		*(*get_keys)(void);
	t_sl_event_manager		*(*get_events)(void);
	t_time					*(*get_time)(void);
	t_gfx_ui_elements		*(*get_ui)(void);
}							t_sl_game;

t_sl_game					*get_game(void);
void						sl_game_draw_ui(void);

#endif
