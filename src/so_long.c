/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:14:59 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:01:00 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>
#include <utils/error.h>
#include <utils/io.h>
#include <utils/log.h>
#include <scripting/scripting.h>

static int	clean_exit(bool ok)
{
	destroy_all_contexts();
	if (ok)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

static bool	setup(int ac, char **av)
{
	t_sl_game	*game;
	t_sl_window	*ctx;

	if (!sl_io_parse(ac, av))
		return (false);
	game = get_game();
	if (!game)
		return (false);
	if (!sl_map_load(av[0]))
		return (false);
	ctx = game->get_window();
	if (!ctx || !game->get_camera())
		return (false);
	if (!sl_entities_spawn())
		sl_error("Failed to spawn all the entities.", NULL);
	game->get_camera()->update_position();
	if (!gfx_define_window(
			game->get_camera()->fov.x, game->get_camera()->fov.y))
		return (false);
	game->get_renderer()->ask_to_render();
	sl_key_manager_hook();
	gfx_window_management_hook();
	sl_scripting_init();
	return (true);
}

static void	start(void)
{
	t_sl_game	*game;
	t_sl_window	*ctx;

	game = get_game();
	if (!game)
		return ;
	ctx = game->get_window();
	if (!ctx)
		return ;
	mlx_loop_hook(ctx->mlx, game->get_renderer()->render_thread, NULL);
	mlx_loop(ctx->mlx);
}

int	main(int ac, char **av)
{
	ac--;
	av++;
	if (!setup(ac, av))
		return (clean_exit(false));
	start();
	return (clean_exit(true));
}
