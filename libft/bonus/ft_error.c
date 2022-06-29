/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:16:40 by decordel          #+#    #+#             */
/*   Updated: 2022/05/20 21:45:19 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_ret_err(char *str, int code)
{
	ft_putstr_fd(RED_ERR, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(DEF, 2);
	return (code);
}

void	ft_put_err(char *str)
{
	ft_putstr_fd(RED_ERR, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(DEF, 2);
	exit(1);
}

void	ft_debug_print(char *str)
{
	static int	n = 1;

	ft_putstr_fd("\033[1;31m", 2);
	ft_putnbr_fd(n++, 1);
	ft_putstr_fd(". ", 1);
	ft_putstr_fd(str, 1);
	read(0, NULL, 1);
	ft_putendl_fd(">", 1);
	ft_putstr_fd("\033[0;0m", 2);
}
