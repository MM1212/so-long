/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:18:21 by martiper          #+#    #+#             */
/*   Updated: 2023/05/10 23:22:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <gfx/ui/fps.h>
#include <gfx/ui/cache.h>

static void	compute_stat_cache(\
	t_gfx_ui_text_cache *cache, \
	size_t value, \
	char *prefix, \
	char *suffix
)
{
	char	*tmp;

	if (cache->defined && cache->value == value)
		return ;
	cache->defined = 1;
	if (cache->str)
		free(cache->str);
	cache->value = value;
	if (!prefix)
		prefix = "";
	if (!suffix)
		suffix = "";
	tmp = ft_itoa(value);
	cache->str = ft_strjoin(prefix, tmp);
	free(tmp);
	tmp = cache->str;
	cache->str = ft_strjoin(cache->str, suffix);
	free(tmp);
}

static void	sl_game_draw_stats(void)
{
	t_gfx_ui_elements			*ctx;
	t_sl_game					*game;

	game = get_game();
	ctx = game->get_ui();
	if (!game || !ctx)
		return ;
	compute_stat_cache(&ctx->time, game->stats.time, "Time: ", "s");
	compute_stat_cache(&ctx->collectibles_spawned, \
		game->get_map()->features.collectibles, \
		" / ", "" \
	);
	compute_stat_cache(\
		&ctx->collectible, \
		game->stats.collectibles, \
		"Chests: ", ctx->collectibles_spawned.str \
	);
	compute_stat_cache(&ctx->moves, game->stats.moves, "Moves: ", "");
	compute_stat_cache(&ctx->enemies, game->get_map()->features.patrols, \
		"Patrols: ", "" \
	);
	gfx_ui_draw_text(ctx->time.str, 0xFFFFFF, 1, 3);
	gfx_ui_draw_text(ctx->collectible.str, 0xFFFFFF, 1, 4);
	gfx_ui_draw_text(ctx->moves.str, 0xFFFFFF, 1, 5);
	gfx_ui_draw_text(ctx->enemies.str, 0xFFFFFF, 1, 6);
}

void	sl_game_draw_ui(void)
{
	gfx_ui_fps_draw();
	sl_game_draw_stats();
}
