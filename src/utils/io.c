/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:09:11 by martiper          #+#    #+#             */
/*   Updated: 2023/05/08 12:25:28 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/io.h"
#include <utils/error.h>
#include <utils/log.h>
#include <libft.h>

static void	print_usage(void)
{
	ft_printf(LOG_INFO "Usage: "STD_COLOR_ORANGE"./so_long <map_path>\n");
}

bool	sl_io_parse(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf(LOG_ERROR "Invalid number of arguments!\n");
		print_usage();
		return (false);
	}
	return (true);
}
