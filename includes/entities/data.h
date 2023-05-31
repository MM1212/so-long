/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:33:41 by martiper          #+#    #+#             */
/*   Updated: 2023/05/11 11:41:53 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H

# define DATA_H

# include <time/time.h>

typedef struct s_entity_data_collectible
{
	bool		collected;
	t_timestamp	collected_at;
}	t_sl_entity_data_collectible;

typedef struct s_entity_data_player
{
	bool		opening_chest;
}	t_sl_entity_data_player;

typedef struct s_entity_data_patrol
{
	t_timestamp	last_move;
	size_t		id;
}	t_sl_entity_data_patrol;

#endif
