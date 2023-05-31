/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrols.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:45:07 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 14:24:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATROLS_H
# define PATROLS_H

# ifndef PATROLS_MOVE_INTERVAL
#  define PATROLS_MOVE_INTERVAL 2500
# endif
# ifndef PATROLS_STOP_INTERVAL
#  define PATROLS_STOP_INTERVAL 500
# endif

void	sl_scripting_patrols_init(void);

#endif
