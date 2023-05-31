/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:17:47 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 10:19:14 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/player.h"

bool	sl_scripting_player_is_movement_key(t_sl_keycodes keycode)
{
	return (\
		keycode == KEYCODE_W || keycode == KEYCODE_A || \
		keycode == KEYCODE_S || keycode == KEYCODE_D || \
		keycode == KEYCODE_ARROW_UP || keycode == KEYCODE_ARROW_LEFT || \
		keycode == KEYCODE_ARROW_DOWN || keycode == KEYCODE_ARROW_RIGHT \
	);
}
