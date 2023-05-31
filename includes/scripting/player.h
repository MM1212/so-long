/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:53:50 by martiper          #+#    #+#             */
/*   Updated: 2023/05/11 10:51:33 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <game.h>

void	sl_scripting_player_init(void);
void	sl_scripting_player_keys_init(void);
void	sl_scripting_player_handle_movement(t_sl_keycode *keycode);

bool	sl_scripting_player_is_movement_key(t_sl_keycodes keycode);
void	sl_scripting_player_handle_interact(t_sl_keycode *keycode);
void	sl_scripting_player_check_patrol_collision(t_sl_entity *player);

#endif
