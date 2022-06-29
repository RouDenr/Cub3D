/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:03:52 by decordel          #+#    #+#             */
/*   Updated: 2022/05/02 18:46:39 by decordel         ###   ########.fr       */
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
