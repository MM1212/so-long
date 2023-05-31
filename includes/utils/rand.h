/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:38:50 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 11:34:35 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAND_H
# define RAND_H

# include <std.h>

size_t	random_int(size_t seed);
size_t	random_range(size_t min, size_t max);

#endif
