/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:00:19 by martiper          #+#    #+#             */
/*   Updated: 2023/05/09 21:40:49 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include <context/context.h>
#include <std.h>
#include <utils/log.h>

void	*sl_error(char *msg, char *param)
{
	if (!param)
		param = "";
	destroy_all_contexts();
	ft_printf(\
		"Error\n" \
		LOG_ERROR"%s%s\n", \
		msg, \
		param \
	);
	exit(EXIT_FAILURE);
	return (NULL);
}
