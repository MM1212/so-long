/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:10:46 by martiper          #+#    #+#             */
/*   Updated: 2023/04/23 07:12:03 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
	Outputs msg + param to the stdout.
	Clears all the contexts & exits the process.
 */
void	*sl_error(char *msg, char *param);

#endif