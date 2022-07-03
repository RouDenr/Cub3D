# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 21:18:07 by decordel          #+#    #+#              #
#    Updated: 2022/07/03 21:19:49 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S		=	srcs/
O		=	objs
I		=	incs/
D		=	deps

NAME	=	cub3D

SRCS	=	main.c				\
			mlx_init.c			\
			player.c			\
			player_controller.c	\
			draw.c				\
			raycast.c			\
			logs.c				\
			game.c


CC		=	clang

CFLAGS	=	-Wall -Wextra -g
# CFLAGS	=	-Wall -Wextra -Werror

SRCS	:=	$(foreach file,$(SRCS),$S$(file))

OBJS	=	$(SRCS:$S%.c=$O/%.o)
DEPS	=	$(SRCS:$S%.c=$D/%.d)

LDFLAGS	:= -framework OpenGL -framework AppKit

MLX_DIR	:=	minilibx
# MLX_DIR	:=	minilibx_swift
# MLX_DIR	:=	minilibx_sources
MLX_AR	:=	$(MLX_DIR)/libmlx.a
# MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

PARS_DIR:=	parser
PARS_AR	:=	$(PARS_DIR)/parser.a

LIB_DIR	:=	libft
LIB_AR	:=	$(LIB_DIR)/libft.a
# LIB_FLAGS	:= -L$(LIB_DIR) -lft

AR		=	ar rcs

RM		=	rm -rf

PREFIX	:=	$(MAKELEVEL)>>

.PHONY: all clean fclean re pack binary libft parser do debug leaks norm git

all			: $(DEPS) $(NAME)

$(NAME)		: $(LIB_AR) $(MLX_AR) $(PARS_AR) $(OBJS)
	@echo "\n$(PREFIX) Building binary "
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
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
	@echo "\n$(PREFIX) Cleaning cub3d libs "
	@make clean -C $(LIB_DIR) -s
	@make clean -C $(PARS_DIR) -s
	@make clean -C $(MLX_DIR) -s
	@echo "$(PREFIX) Done! \n"
	@echo "\n$(PREFIX) Cleaning cub3d *.o files "
	@$(RM) $O
	@echo "$(PREFIX) Done! \n"

fclean		: clean
	@echo "\n$(PREFIX) Cleaning cub3d binary "
	@$(RM) $(NAME)
	@echo "$(PREFIX) Done! \n"
	@echo "\n$(PREFIX) Cleaning cub3d *.d files "
	@$(RM) $D
	@echo "$(PREFIX) Done! \n"
	@make fclean -C $(LIB_DIR) -s
	@make fclean -C $(PARS_DIR) -s
	@make clean -C $(MLX_DIR) -s

re			: fclean all
#-------------

# # Building parser archive for minishell binary
# binary		: $(NAME_BIN) $(DEPS)

# $(NAME_BIN)	: $(OBJS)
# 	@echo "\n$(PREFIX) Building parser binary "
# 	@$(CC) $(CFLAGS) -Llibft -lft $^ -o $@
# 	@echo "$(PREFIX) Done! \n"
# #-------------

# Building libft
$(LIB_AR)	: libft ;

libft:
	@echo "\n$(PREFIX) Invoking libft makefile"
	@$(MAKE) -C $(LIB_DIR) -j 4
	@echo "$(PREFIX) Done! \n"
#-------------

# Building parser
$(PARS_AR)	: parser ;

parser	:
	@echo "\n$(PREFIX) Invoking parser makefile"
	@$(MAKE) -C $(PARS_DIR) -j 4
	@echo "$(PREFIX) Done! \n"
#-------------

# Building mlx
$(MLX_AR)	: mlx ;

mlx:
	@echo "\n$(PREFIX) Invoking mlx makefile"
	# @$(MAKE) -C $(MLX_DIR) -j 4
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(PREFIX) Done! \n"
#-------------


#! debug ---------------------------------
MESS	=

ARGS	= maps/test.cub

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
	norminette srcs/ | grep Er

#! debug ---------------------------------

ifeq ($(MAKECMDGOALS),fclean)
else ifeq ($(MAKECMDGOALS),clean)
else
-include $(DEPS)
endif
