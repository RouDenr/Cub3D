/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:22:26 by decordel          #+#    #+#             */
/*   Updated: 2022/06/03 18:24:57 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel_content(t_list **lst, char *cont, size_t size)
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	head = *lst;
	if (!ft_strncmp((char *)head->content, cont, size))
	{
		*lst = head->next;
		ft_lstdelone(head, free);
		return ;
	}
	while (head->next)
	{
		if (!ft_strncmp((char *)head->next->content, cont, size))
		{
			tmp = head->next;
			head->next = tmp->next;
			ft_lstdelone(tmp, free);
			return ;
		}
		head = head->next;
	}
}
