/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:31:21 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 11:42:36 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

# include <math.h>

typedef struct s_vector2
{
	int				x;
	int				y;
}					t_vector2;

typedef t_vector2	t_vec2;

t_vec2				vec2(int x, int y);
t_vec2				vec2_add(t_vec2 a, t_vec2 b);
t_vec2				vec2_sub(t_vec2 a, t_vec2 b);
t_vec2				vec2_mul(t_vec2 a, t_vec2 b);
t_vec2				vec2_mul_scal(t_vec2 a, int constant);
t_vec2				vec2_div(t_vec2 a, t_vec2 b);
t_vec2				vec2_div_scal(t_vec2 a, int constant);
t_vec2				vec2_scale(t_vec2 a, int b);
t_vec2				vec2_invert(t_vec2 a);
t_vec2				vec2_normalize(t_vec2 a);
t_vec2				vec2_clamp(t_vec2 a, t_vec2 min, t_vec2 max);
double				vec2_length(t_vec2 a);
double				vec2_dist(t_vec2 a, t_vec2 b);

#endif
