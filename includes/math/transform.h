/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:55:19 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 11:18:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "vec2.h"

typedef struct s_transform
{
	t_vec2		position;
	t_vec2		direction;
	t_vec2		speed;
}			t_transform;

#endif
