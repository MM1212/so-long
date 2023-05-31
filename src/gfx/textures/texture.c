/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 06:03:42 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:46:52 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/textures/texture.h"
#include "gfx/textures/t_parser.h"

static void	next_line(int fd, char **def_line)
{
	free(*def_line);
	*def_line = get_next_line(fd);
}

static void	parse(\
	int fd, \
	char **def_line, \
	t_sl_texture *texture, \
	size_t *sprite_count
)
{
	while (*def_line)
	{
		if (!texture->tag)
			sl_textures_internal_parse_texture_tag(fd, def_line, texture);
		else if (!texture->size)
			sl_textures_internal_parse_texture_size(fd, def_line, texture);
		else if (texture->frame_duration == -1)
			sl_textures_internal_parse_texture_anim_duration(\
				fd, def_line, texture \
			);
		else if (texture->size > 0 && ft_str_startswith(*def_line, "---"))
			next_line(fd, def_line);
		else if (sl_textures_internal_parse_texture_sprite(\
			*def_line, texture, (*sprite_count)++ \
			) \
		)
			next_line(fd, def_line);
		else
		{
			free(*def_line);
			sl_error(TEX_SPRITE_LOAD_FAILED, texture->def_path);
			return ;
		}
	}
}

bool	sl_new_texture(char *def_path, t_sl_texture *texture)
{
	char	*def_line;
	int		fd;
	size_t	sprite_count;

	fd = open(def_path, O_RDONLY);
	if (fd == -1)
		return ((bool)sl_error(FILE_NOT_FOUND, def_path));
	def_line = get_next_line(fd);
	sprite_count = 0;
	texture->frame_duration = -1;
	texture->def_path = ft_strdup(def_path);
	parse(fd, &def_line, texture, &sprite_count);
	close(fd);
	texture->current = 0;
	return (true);
}
