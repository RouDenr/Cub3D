/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:52:01 by decordel          #+#    #+#             */
/*   Updated: 2021/10/30 16:01:08 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*addbuf(char *str, char *buf, size_t size);
char	*bufstart(char *buf, size_t len);
size_t	ft_strlen(const char *s);

#endif
