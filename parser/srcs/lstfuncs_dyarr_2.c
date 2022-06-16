/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfuncs_dyarr_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:17:41 by vseel             #+#    #+#             */
/*   Updated: 2022/05/15 16:08:41 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incs/parser.h"

void	ft_lstiter_dyarr(t_dyarr *lst, void (*f)(void *))
{
	t_dyarr	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}

t_dyarr	*ft_lstlast_dyarr(t_dyarr *lst)
{
	t_dyarr	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_dyarr	*ft_lstmap_dyarr(t_dyarr *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dyarr	*lst_begin;
	t_dyarr	*new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew_dyarr(f(lst));
	if (!new_lst)
	{
		free (new_lst);
		return (0);
	}
	lst_begin = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst = ft_lstnew_dyarr(f(lst));
		if (!new_lst)
		{
			ft_lstclear_dyarr(&lst_begin, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back_dyarr(&lst_begin, new_lst);
	}
	return (lst_begin);
}

int	ft_lstsize_dyarr(t_dyarr *lst)
{
	int		i;
	t_dyarr	*tmp;

	if (!lst)
		return (0);
	i = 1;
	tmp = lst->next;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
