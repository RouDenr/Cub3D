# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 15:41:45 by vseel             #+#    #+#              #
#    Updated: 2022/06/19 17:27:13 by vseel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c ft_itoa.c ft_split.c ft_bzero.c ft_calloc.c	\
			ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c		\
			ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c		\
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c		\
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c		\
			ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c		\
			ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c		\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c			\
			ft_putnbr_fd.c ft_strtrim.c								\
			get_next_line.c get_next_line_utils.c ft_lstfind.c
BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c				\
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c			\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

BON		=	$(BONUS:.c=.o)
OBJS	=	$(SRCS:.c=.o)

HEAD	=	libft.h
GNLHEAD	=	get_next_line.h

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g

ARLIB	=	ar rcs
RM		=	rm -f

.PHONY:	all clean fclean re bonus

all		: $(NAME)

%.o 	: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	@$(ARLIB) $@ $^

$(OBJS)	: $(HEAD) $(GNLHEAD)


clean	:
	@$(RM) $(OBJS) $(BON)

fclean	: clean
	@$(RM) $(NAME)

re		: fclean all

bonus	: $(OBJS) $(BON) $(HEAD)
	@$(ARLIB) $(NAME) $(OBJS) $(BON)
