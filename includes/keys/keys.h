/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:24:50 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 13:10:40 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define KEYS_MAX 0xFFFF

# include <std.h>

typedef enum e_sl_keycodes
{
	KEYCODE_ESCAPE = 65307,
	KEYCODE_W = 119,
	KEYCODE_A = 97,
	KEYCODE_S = 115,
	KEYCODE_D = 100,
	KEYCODE_ARROW_UP = 65362,
	KEYCODE_ARROW_LEFT = 65361,
	KEYCODE_ARROW_DOWN = 65364,
	KEYCODE_ARROW_RIGHT = 65363,
	KEYCODE_E = 101,
}						t_sl_keycodes;

// backwards compatibility
typedef t_sl_keycodes	t_gfx_keycodes;

typedef struct s_sl_keycode
{
	bool				_defined;
	unsigned short		keycode;
	bool				pressed;
}						t_sl_keycode;

typedef struct s_key_manager
{
	t_sl_keycode		keys[KEYS_MAX];
	bool				(*is_pressed)(t_sl_keycodes);
	void				(*hook)(t_sl_keycodes);
}						t_sl_key_manager;

t_sl_key_manager		*get_key_manager_ctx(void);
void					sl_key_manager_hook(void);
#endif
