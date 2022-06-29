/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:48:48 by decordel          #+#    #+#             */
/*   Updated: 2022/04/25 21:31:25 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *newl)
{
	t_list	*tmp;

	tmp = *lst;
	if (!newl || !lst)
		return ;
	if (!*lst)
	{
		*lst = newl;
		return ;
	}
	newl->next = tmp;
	*lst = newl;
}
