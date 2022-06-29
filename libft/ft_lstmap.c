/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:00:22 by decordel          #+#    #+#             */
/*   Updated: 2022/05/10 18:11:04 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	do_malloc(t_list *node, t_list *lst, t_list *map, void (*del)(void *))
{
	if (!node)
	{
		ft_lstclear(&lst, del);
		ft_lstclear(&map, del);
		return (0);
	}
	return (1);
}

void	ft_lstsort(t_list *lst)
{
	t_list	*i;
	t_list	*j;
	void	*tmp;

	i = lst;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (ft_strncmp(i->content, j->content,
					ft_strlen(i->content) + 1) >= 0)
			{
				tmp = i->content;
				i->content = j->content;
				j->content = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void(*del)(void *))
{
	t_list	*map;
	t_list	*clst;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	map = ft_lstnew(f(lst->content));
	if (!do_malloc(map, lst, map, del))
		return (NULL);
	clst = lst->next;
	while (clst)
	{
		next = ft_lstnew(f(clst->content));
		if (!do_malloc(next, lst, map, del))
			return (NULL);
		ft_lstadd_back(&map, next);
		clst = clst->next;
	}
	return (map);
}
