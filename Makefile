# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 21:18:07 by decordel          #+#    #+#              #
#    Updated: 2022/06/30 06:00:45 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S		=	srcs/
O		=	objs
I		=	incs/
D		=	deps

NAME	=	cub3D

SRCS	=	main.c		\
			mlx_init.c	\
			player.c	\
			draw.c		\
			raycast.c	\
			game.c

# SRCS	+=	main_opt.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -g
# CFLAGS	=	-Wall -Wextra -Werror

SRCS	:=	$(foreach file,$(SRCS),$S$(file))

OBJS	=	$(SRCS:$S%.c=$O/%.o)
DEPS	=	$(SRCS:$S%.c=$D/%.d)

MLX_DIR		:=	minilibx
MLX_AR		:=	$(MLX_DIR)/libmlx.a
MLX_FLAGS	:= -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit

PARS_DIR	:=	parser
PARS_AR		:=	$(PARS_DIR)/parser.a

LIB_DIR	:=	libft
LIB_AR	:=	$(LIB_DIR)/libft.a
LIB_FLAGS := -L${LIB_DIR} -lft

AR		=	ar rcs

RM		=	rm -rf

PREFIX	:=	$(MAKELEVEL)>>

.PHONY: all clean fclean re pack binary libft parser

all			: $(DEPS) $(NAME)

$(NAME)	: $(OBJS) ${LIB_AR} ${MLX_AR} ${PARS_AR}
	@echo "\n$(PREFIX) Building binary "
	@$(CC) $(CFLAGS) ${LIB_FLAGS} ${MLX_FLAGS} $^ -o $@
	@echo "$(PREFIX) Done! \n"
#-------------

# Building objective files (*.o)
$O:
	@mkdir $@

$O/%.o		: $S%.c $(LIB_AR) | $O
	@$(CC) $(CFLAGS) -c $< -o $@
#-------------

# Building dependency files (*.d)
$D:
	@mkdir $@

$D/%.d		: $S%.c	| $D
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<
#-------------

# Standart rules for cleanup
clean:
	@echo "\n$(PREFIX) Cleaning libft "
	@make clean -C $(LIB_DIR) -s
	@make clean -C $(PARS_DIR) -s
	@echo "$(PREFIX) Done! \n"
	@echo "\n$(PREFIX) Cleaning *.o files "
	@$(RM) $O
	@echo "$(PREFIX) Done! \n"

fclean		: clean
	@echo "\n$(PREFIX) Cleaning binary and archive "
	@$(RM) $(NAME) $(NAME_BIN)
	@echo "$(PREFIX) Done! \n"
	@echo "\n$(PREFIX) Cleaning *.d files "
	@$(RM) $D
	@echo "$(PREFIX) Done! \n"

re			: fclean all
#-------------

# Building parser archive for minishell binary
binary		: $(NAME_BIN) $(DEPS)

$(NAME_BIN)	: $(OBJS)
	@echo "\n$(PREFIX) Building parser binary "
	@$(CC) $(CFLAGS) -Llibft -lft $^ -o $@
	@echo "$(PREFIX) Done! \n"
#-------------

# Building libft
$(LIB_AR)	: libft ;

libft:
	@echo "\n$(PREFIX) Invoking libft makefile"
	@$(MAKE) -C $(LIB_DIR)
	@echo "$(PREFIX) Done! \n"
#-------------

# Building parser
$(PARS_AR)	: parser ;

parser	:
	@echo "\n$(PREFIX) Invoking parser makefile"
	@$(MAKE) -C $(PARS_DIR)
	@echo "$(PREFIX) Done! \n"
#-------------

# Building mlx
$(MLX_AR)	: mlx ;

mlx:
	@echo "\n$(PREFIX) Invoking mlx makefile"
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(PREFIX) Done! \n"
#-------------


#! debug ---------------------------------
MESS	= 

ARGS	= maps/map1.cub

git		:
	git add .
	git commit -m "$(MESS)"

do		:
	make all -s
	./$(NAME) $(ARGS)

leaks	:
	make all
	leaks -atExit -- ./$(NAME) $(ARGS)

debug	:
	make all
	lldb -- ./$(NAME) $(ARGS)

norm	:
	clear
	norminette | grep Er

#! debug ---------------------------------

ifeq ($(MAKECMDGOALS),fclean)
else ifeq ($(MAKECMDGOALS),clean)
else
-include $(DEPS)
endif
