/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:26:24 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 12:30:26 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time/time.h"

t_timestamp	time_get_now(void)
{
	return (clock() * 1000.0 / CLOCKS_PER_SEC);
}

size_t	time_get_elapsed(void)
{
	t_time	*time;
	clock_t	now;
	double	timestamp;

	time = get_time_ctx();
	if (!time)
		return (0);
	now = clock();
	timestamp = (now - time->started) * 1000.0 / CLOCKS_PER_SEC;
	return ((size_t)timestamp);
}

double	time_get_delta_time(void)
{
	t_time	*time;

	time = get_time_ctx();
	if (!time)
		return (0);
	return (time->frame.delta_time);
}

void	time_def_internal_on_frame_rendered(void)
{
	t_time	*time;

	time = get_time_ctx();
	if (!time)
		return ;
	time->frame.frame_time = 0;
}
