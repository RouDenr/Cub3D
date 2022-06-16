/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:05:15 by vseel             #+#    #+#             */
/*   Updated: 2022/06/16 23:28:22 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

char	*get_next_line(int fd);

// int		ft_strlen_s(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strdup_free(const char *s1, char tofree);
char	*ft_substr_free(char const *s, unsigned int start, size_t len, char fr);

int		ft_error_message(int errnum);

#endif /*GET_NEXT_LINE_H*/
