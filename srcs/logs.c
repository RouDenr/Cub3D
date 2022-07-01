/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:37:06 by decordel          #+#    #+#             */
/*   Updated: 2022/07/01 04:00:54 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	print_log_ray(int keycode, t_ray *ray)
{
	if (keycode != 49)
		return (0);
	system("clean");
	printf("ray ---\n");
	// printf("x - %d y - %d\n");
	return (0);
}

// int	print_log_ray(int keycode, t_ray *map)
// {
// 	if (keycode != 49)
// 		return (0);
// 	system("clean");
// 	printf("ray ---\n");
// 	printf("x - %d y - %d\n");
// 	return (0);
// }

// void	log_in_file(char *)
// {

// }
