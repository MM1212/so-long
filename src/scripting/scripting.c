/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scripting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:28:22 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 14:22:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scripting/scripting.h"
#include "scripting/player.h"
#include "scripting/game/ui.h"
#include "scripting/chests.h"
#include "scripting/patrols/patrols.h"

void	sl_scripting_init(void)
{
	sl_scripting_player_init();
	sl_scripting_chests_init();
	sl_scripting_patrols_init();
	sl_scripting_game_ui_init();
}
