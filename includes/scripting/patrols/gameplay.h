/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:15:51 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 12:33:48 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

# include <math/vec2.h>
# include <entities/entity.h>
# include <entities/data.h>
# include <map/interact.h>
# include <utils/rand.h>
# include <game.h>

void	sl_scripting_patrols_check_if_lost(t_vec2 patrol_pos);
void	sl_scripting_patrols_stop_patrol(\
	t_sl_entity *entity \
);
t_vec2	sl_scripting_patrols_choose_direction(\
	t_sl_map_tile_neighbors *neighbors \
);
#endif
