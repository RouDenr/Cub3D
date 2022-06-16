/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:03:52 by decordel          #+#    #+#             */
/*   Updated: 2022/05/20 12:39:04 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *content, size_t size)
{
	while (lst)
	{
		if (!ft_memcmp(lst->content, content, size))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
