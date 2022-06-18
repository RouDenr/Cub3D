/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:10 by vseel             #+#    #+#             */
/*   Updated: 2022/06/18 19:21:00 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parser.h"
#include "../libft/libft.h"

int	throw_error(char *msg, int exit_code, char mode)
{
	ft_putendl_fd("Error", 2);
	if (mode == 'm' && msg)
		ft_putendl_fd(msg, 2);
	if (mode == 'p' && msg)
		perror(msg);
	return (exit_code);
}
