/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:19:32 by mm                #+#    #+#             */
/*   Updated: 2023/04/19 21:36:25 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, int (*f)(void *))
{
	while (lst)
	{
		if (f(lst->content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
