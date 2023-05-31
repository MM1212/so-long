/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:56:24 by martiper          #+#    #+#             */
/*   Updated: 2023/05/12 12:56:35 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/gnl.h"

void	gnl_next_line(\
	int fd, \
	char **def_line \
)
{
	free(*def_line);
	*def_line = get_next_line(fd);
}
