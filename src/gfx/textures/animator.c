/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 06:01:17 by martiper          #+#    #+#             */
/*   Updated: 2023/05/04 11:43:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/textures/animator.h"
#include <time/time.h>

bool	sl_animate_texture(t_sl_texture_animator *animator,
		t_sl_texture *texture)
{
	bool	should_switch;

	if (!animator || !texture || !texture->animated)
		return (false);
	animator->frame_count += time_get_delta_time();
	should_switch = animator->frame_count >= texture->frame_duration;
	if (should_switch)
		animator->frame_count = 0;
	return (should_switch);
}
