/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:33:20 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 11:20:28 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys/keys.h"
#include <context/context.h>
#include <events.h>
#include <std.h>

static bool	key_manager_is_pressed(t_sl_keycodes keycode)
{
	t_sl_key_manager	*manager;

	manager = get_key_manager_ctx();
	if (keycode > KEYS_MAX)
		return (false);
	if (!manager->keys[keycode]._defined)
		return (false);
	return (manager->keys[keycode].pressed);
}

static void	key_manager_hook_key(t_sl_keycodes keycode)
{
	t_sl_key_manager	*manager;

	manager = get_key_manager_ctx();
	if (keycode > KEYS_MAX)
		return ;
	if (manager->keys[keycode]._defined)
		return ;
	manager->keys[keycode] = (t_sl_keycode){true, keycode, false};
}

static t_sl_key_manager	*key_manager_create(void)
{
	t_sl_key_manager	*manager;

	manager = ft_calloc(1, sizeof(t_sl_key_manager));
	if (!manager)
		return (NULL);
	manager->is_pressed = &key_manager_is_pressed;
	manager->hook = &key_manager_hook_key;
	return (manager);
}

t_sl_key_manager	*get_key_manager_ctx(void)
{
	return (
		get_context(CONTEXT_ID_KEYS_MANAGER,
			(void *(*)(void))key_manager_create, free)
	);
}
