/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:35:45 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 12:31:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <std.h>

# ifndef FPS_CAP
#  define FPS_CAP -1
# endif
# ifndef FPS_REFRESH_RATE
#  define FPS_REFRESH_RATE 100
# endif

typedef long long	t_timestamp;

typedef struct s_frame_time
{
	clock_t		last_frame;
	double		delta_time;
	double		frame_time;
	double		fps_count_time;
	size_t		fps;
	long		fps_cap;
	bool		are_fps_capped;
	t_timestamp	_last_compute_timestamp;
	void		(*compute_fps)(void);
	bool		(*should_render_frame)(void);
	void		(*parse_frame)(void);
	void		(*on_frame_rendered)(void);
}	t_frame_time;

typedef struct s_time
{
	clock_t			started;
	size_t			(*get_elapsed)(void);
	t_timestamp		(*get_now)(void);
	t_frame_time	frame;
}	t_time;

t_time		*get_time_ctx(void);

double		time_get_delta_time(void);
t_timestamp	time_get_now(void);
size_t		time_get_elapsed(void);
void		time_def_internal_on_frame_rendered(void);

#endif
