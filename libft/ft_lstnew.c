/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:37:35 by decordel          #+#    #+#             */
/*   Updated: 2022/05/10 17:22:00 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new;

	new = NULL;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(lst->content)));
		lst = lst->next;
	}
	return (new);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof (new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
