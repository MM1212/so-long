/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:53:23 by martiper          #+#    #+#             */
/*   Updated: 2023/05/06 11:03:39 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera/camera.h"
#include <context/context.h>
#include <entities/registry.h>
#include <map/map.h>
#include <utils/error.h>
#include <utils/log.h>
#include <std.h>

#define CAMERA_FOV_PARSER_ERROR "Could not parse camera fov! \
			Expected <number>x<number> and got: "

void	sl_camera_update_position(void)
{
	t_sl_entity_registry	*registry;
	t_sl_camera				*camera;
	t_sl_map				*map;
	t_vec2					half_fov;

	camera = get_camera_ctx();
	if (!camera)
		return ;
	registry = get_entity_registry_ctx();
	if (!registry)
		return ;
	map = get_map_ctx();
	if (!map)
		return ;
	camera->pos = vec2_add(\
		registry->player->transform.position, \
		vec2(SPRITE_SIZE / 2, SPRITE_SIZE / 2) \
	);
	half_fov = vec2_div(camera->fov, vec2(2, 2));
	camera->pos = vec2_clamp(\
		camera->pos, \
		half_fov, \
		vec2_sub(map->size, half_fov) \
	);
}

bool	sl_camera_is_in_view(t_vec2 position)
{
	t_sl_camera	*camera;
	t_vec2		cam_bound_box[2];
	t_vec2		pos_bound_box[2];
	t_vec2		sprite_size;

	camera = get_camera_ctx();
	if (!camera)
		return (false);
	sprite_size = vec2(SPRITE_SIZE, SPRITE_SIZE);
	cam_bound_box[0] = vec2_sub(
			camera->pos, vec2_div_scal(camera->fov, 2));
	cam_bound_box[1] = vec2_add(
			camera->pos, vec2_div_scal(camera->fov, 2));
	pos_bound_box[0] = position;
	pos_bound_box[1] = vec2_add(position, sprite_size);
	return (sl_map_is_on_bounds(position)
		&& pos_bound_box[0].x <= cam_bound_box[1].x
		&& pos_bound_box[0].y <= cam_bound_box[1].y
		&& pos_bound_box[1].x >= cam_bound_box[0].x
		&& pos_bound_box[1].y >= cam_bound_box[0].y);
}

static t_sl_camera	*create_camera(void)
{
	t_sl_camera	*camera;
	t_sl_map	*map;
	char		**fov;

	map = get_map_ctx();
	if (!map)
		return (NULL);
	camera = ft_calloc(1, sizeof(t_sl_camera));
	if (!camera)
		return (NULL);
	camera->is_in_view = sl_camera_is_in_view;
	camera->update_position = sl_camera_update_position;
	fov = ft_split(CAMERA_FOV, 'x');
	if (!fov || fov[0] == NULL || fov[1] == NULL)
		return (sl_error(CAMERA_FOV_PARSER_ERROR, CAMERA_FOV));
	camera->fov = vec2(ft_atoi(fov[0]), ft_atoi(fov[1]));
	camera->fov = vec2_clamp(camera->fov, vec2(1, 1), map->size);
	camera->fov = vec2_mul_scal(camera->fov, SPRITE_SIZE);
	ft_printf(
		LOG_INFO "Created the camera with fov of %dx%d\n",
		camera->fov.x,
		camera->fov.y);
	ft_split_free(fov);
	return (camera);
}

t_sl_camera	*get_camera_ctx(void)
{
	return (get_context(
			CONTEXT_ID_CAMERA,
			(void *(*)(void))create_camera, free));
}
