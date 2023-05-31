/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:11:25 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 14:49:45 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_H
# define STORE_H

# include "sprite.h"
# include <std.h>
# include <context/context.h>

typedef t_list	t_sl_sprite_store;

t_sl_sprite_store	*get_sprite_store_ctx(void);
t_sl_sprite			*sl_get_sprite(char *path);

#endif
