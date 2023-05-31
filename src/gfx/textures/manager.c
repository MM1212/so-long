/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:39:09 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 12:57:32 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/textures/manager.h"
#include <camera/camera.h>
#include <gfx/gfx.h>
#include <std.h>
#include <utils/error.h>
#include <utils/log.h>
#include <utils/rand.h>
#include <utils/gnl.h>

#define FILE_NOT_FOUND "Failed to load texm definition file.\n \
			File not found or corrupted: "
#define TEX_MANAGER_ALLOC_FAILED "Failed to load texm definition file.\n \
			Could not alloc enough space for it: "
#define TEX_SPRITE_COUNT_FAILED "Failed to load texm definition file.\n \
			Could not parse tex sprite count: "
#define TEX_SPRITE_FAILED "Failed to load texm definition file.\n \
			Could not load tex sprite: "
#define TEXM_INVALID_COUNT "Failed to load texm definition file.\n \
			Size provided doesn't match the amount of texs given: "

typedef t_sl_texture_manager	t_sl_texm;

static bool	parse_texm_size(char *line, t_sl_texm *texm)
{
	if (!ft_str_startswith(line, "size: "))
		return (false);
	while (!ft_isdigit(*line))
		line++;
	texm->size = ft_atoi(line);
	if (texm->size > 0)
		texm->textures = ft_calloc(texm->size, sizeof(t_sl_texture));
	return (texm->textures != NULL && texm->size > 0);
}

static t_sl_texm	*create_texture_manager(char *texm_def_path)
{
	t_sl_texm	*texm;

	texm = ft_calloc(1, sizeof(t_sl_texm));
	if (!texm)
		return (sl_error(TEX_MANAGER_ALLOC_FAILED, texm_def_path));
	texm->def_path = ft_strdup(texm_def_path);
	texm->animator = ft_calloc(1, sizeof(t_sl_texture_animator));
	if (!texm->animator)
		return (sl_texture_manager_internal_stop_parser(\
			texm, NULL, \
			TEX_MANAGER_ALLOC_FAILED, texm_def_path \
		));
	return (texm);
}

static void	load_texture(\
	t_sl_texm *texm, \
	int fd,
	char **def_line, \
	t_sl_texture *texture \
)
{
	bool	parsed;

	parsed = sl_new_texture(*def_line, texture);
	gnl_next_line(fd, def_line);
	if (!parsed)
		sl_texture_manager_internal_stop_parser(\
			texm, *def_line, \
			TEX_SPRITE_FAILED, texm->def_path \
		);
	if (texture->frame_duration > texm->animator->frame_count)
		texm->animator->frame_count = texture->frame_duration;
}

static void	parse(\
	char **def_line, \
	int fd, \
	t_sl_texm *texm, \
	size_t *tex_count \
)
{
	bool	parsed;

	while (*def_line)
	{
		if (!texm->size)
		{
			parsed = parse_texm_size(*def_line, texm);
			gnl_next_line(fd, def_line);
			if (!parsed)
				sl_texture_manager_internal_stop_parser(texm, *def_line, \
					TEX_SPRITE_COUNT_FAILED, texm->def_path);
		}
		else if (texm->size > 0 && ft_str_startswith(*def_line, "---"))
			gnl_next_line(fd, def_line);
		else if ((*tex_count) >= texm->size)
			sl_texture_manager_internal_stop_parser(texm, *def_line, \
				TEXM_INVALID_COUNT, texm->def_path);
		else
			load_texture(texm, fd, def_line, texm->textures + (*tex_count)++);
	}
}

t_sl_texm	*sl_new_texture_manager(char *texm_def_path)
{
	char		*def_line;
	int			fd;
	size_t		tex_count;
	t_sl_texm	*texm;

	fd = open(texm_def_path, O_RDONLY);
	if (fd == -1)
		return (sl_error(FILE_NOT_FOUND, texm_def_path));
	tex_count = 0;
	texm = create_texture_manager(texm_def_path);
	def_line = get_next_line(fd);
	parse(&def_line, fd, texm, &tex_count);
	close(fd);
	texm->current = texm->textures;
	texm->animator->frame_count = (float)random_range(0, \
		(size_t)texm->animator->frame_count);
	return (texm);
}
