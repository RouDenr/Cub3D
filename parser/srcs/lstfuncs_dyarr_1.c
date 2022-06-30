/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfuncs_dyarr_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:17:41 by vseel             #+#    #+#             */
/*   Updated: 2022/06/30 22:39:21 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incs/parser.h"

t_dyarr	*ft_lstnew_dyarr(char *content)
{
	t_dyarr	*node;

	node = (t_dyarr *)malloc(sizeof(t_dyarr));
	if (node == NULL)
		return (NULL);
	ft_memset(node, 0, sizeof(t_dyarr));
	node->line = content;
	return (node);
}

// void	ft_lstadd_back_dyarr(t_dyarr **lst, t_dyarr *new)
t_dyarr	*ft_lstadd_back_dyarr(t_dyarr **lst, t_dyarr *new)
{
	t_dyarr	*tmp;

	if (!new || !lst)
		return (NULL);
	if (!*lst)
	{
		*lst = new;
		return (new);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

void	ft_lstadd_front_dyarr(t_dyarr **lst, t_dyarr *new)
{
	t_dyarr	*p;

	p = *lst;
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = p;
	*lst = new;
}

void	ft_lstdelone_dyarr(t_dyarr *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst);
	free(lst);
}

void	ft_lstclear_dyarr(t_dyarr **lst, void (*del)(void *))
{
	t_dyarr	*p;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		*lst = (*lst)->next;
		ft_lstdelone_dyarr(p, del);
		p = *lst;
	}
	lst = NULL;
}
