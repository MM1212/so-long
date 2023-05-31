/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:42:32 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 11:44:32 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx/textures/t_parser.h"

void	*sl_textures_internal_parse_texture_tag(\
	int fd, \
	char **line, \
	t_sl_texture *texture \
)
{
	char	*tmp;

	tmp = *line;
	if (!ft_str_startswith(*line, "tag: "))
		return (sl_error(TEX_SPRITE_COUNT_FAILED, texture->def_path));
	(*line) += ft_strlen("tag: ");
	texture->tag = ft_strtrim(*line, " ");
	free(tmp);
	if (ft_strlen(texture->tag) == 0)
		return (sl_error(TEX_SPRITE_COUNT_FAILED, texture->def_path));
	*line = get_next_line(fd);
	return (NULL);
}

void	*sl_textures_internal_parse_texture_size(\
	int fd, \
	char **line, \
	t_sl_texture *texture \
)
{
	char	*tmp;

	tmp = *line;
	if (!ft_str_startswith(*line, "size: "))
		return (sl_error(TEX_SPRITE_COUNT_FAILED, texture->def_path));
	while (!ft_isdigit(**line))
		(*line)++;
	texture->size = ft_atoi(*line);
	free(tmp);
	if (texture->size <= 0)
		return (sl_error(TEX_SPRITE_COUNT_FAILED, texture->def_path));
	*line = get_next_line(fd);
	return (NULL);
}

bool	sl_textures_internal_parse_texture_sprite(\
	char *line, \
	t_sl_texture *texture, \
	size_t count \
)
{
	if (!texture->sprites)
		texture->sprites = ft_calloc(texture->size + 1, sizeof(t_sl_sprite *));
	if (!texture->sprites)
		return (false);
	texture->sprites[texture->size] = NULL;
	*(texture->sprites + count) = sl_load_sprite(line);
	return (*(texture->sprites + count) != NULL);
}

void	*sl_textures_internal_parse_texture_anim_duration(\
	int fd, \
	char **line, \
	t_sl_texture *texture \
)
{
	char	*tmp;

	tmp = *line;
	if (!ft_str_startswith(*line, "frame_duration: "))
		return (sl_error(TEX_ANIMATOR_FAILED, texture->def_path));
	while (!ft_isdigit(**line))
		(*line)++;
	texture->frame_duration = ft_atoi(*line);
	free(tmp);
	texture->animated = texture->frame_duration > 0;
	*line = get_next_line(fd);
	return (NULL);
}
