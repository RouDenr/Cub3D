/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:26:14 by decordel          #+#    #+#             */
/*   Updated: 2022/04/30 21:04:22 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *newl)
{
	t_list	*head;

	if (!newl)
		return ;
	head = *lst;
	if (!head)
	{
		*lst = newl;
		return ;
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = newl;
}
