/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:05 by vseel             #+#    #+#             */
/*   Updated: 2022/06/18 21:22:02 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h> 
# include <limits.h>

# define VISUALIZE_MAP	1
# define DEBUG_MSG		"\n>>> To disable cmd debug output \
change define in \"parser.h\"\n\n"

typedef struct s_dyarr {
	char			*line;
	struct s_dyarr	*next;
}	t_dyarr;

/**
 * @param wall_no path to north texture file
 * @param wall_so path to south texture file
 * @param wall_we path to west texture file
 * @param wall_ea path to east texture file
 * @param map_arr_l tmp map dynamic list 
 * @param map_arr 2-axes map array
 */
typedef struct s_map {
	char	*wall_no;
	char	*wall_so;
	char	*wall_we;
	char	*wall_ea;

	int		color_floor;
	int		color_ceil;

	t_dyarr	*map_arr_l;
	char	**map_arr;
}	t_map;

typedef struct s_list	t_list;

/* parser */
t_map	*parse_main(char *str);

/* parser_exit_utils */
int		throw_error(char *msg, int exit_code, char mode);

/* parser_debug_utils */
void	showbits(unsigned int x);
void	visualize_dyarr(t_dyarr *arr);
void	visualize_map(t_map *map);

/* map functions */

/* dyarr list functions */
t_dyarr	*ft_lstnew_dyarr(char *content);
t_dyarr	*ft_lstadd_back_dyarr(t_dyarr **lst, t_dyarr *new);
void	ft_lstadd_front_dyarr(t_dyarr **lst, t_dyarr *new);
void	ft_lstdelone_dyarr(t_dyarr *lst, void (*del)(void *));
void	ft_lstclear_dyarr(t_dyarr **lst, void (*del)(void *));
void	ft_lstiter_dyarr(t_dyarr *lst, void (*f)(void *));
t_dyarr	*ft_lstlast_dyarr(t_dyarr *lst);
t_dyarr	*ft_lstmap_dyarr(t_dyarr *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize_dyarr(t_dyarr *lst);

#endif /*PARSER_H*/
