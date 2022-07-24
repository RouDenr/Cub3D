# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 21:18:07 by decordel          #+#    #+#              #
#    Updated: 2022/07/24 18:01:49 by vseel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S		=	srcs/
O		=	objs
I		=	incs/
D		=	deps

NAME		=	cub3D
NAME_BONUS	=	cub3D_bonus

SRCS	=	main.c				\
			mlx_init.c			\
			player.c			\
			player_controller.c	\
			player_move.c		\
			draw.c				\
			texture.c			\
			hooks.c				\
			raycast.c			\
			game.c

SRCS_BONUS	=	main.c					\
			mlx_init_bonus.c			\
			player.c					\
			player_controller_bonus.c	\
			player_move.c				\
			draw.c						\
			texture.c					\
			hooks_bonus.c				\
			raycast.c					\
			minimap.c					\
			game_bonus.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -g
# CFLAGS	=	-Wall -Wextra -Werror

SRCS	:=	$(foreach file,$(SRCS),$S$(file))
SRCS_BONUS	:=	$(foreach file,$(SRCS_BONUS),$S$(file))

OBJS		=	$(SRCS:$S%.c=$O/%.o)
OBJS_BONUS	=	$(SRCS_BONUS:$S%.c=$O/%.o)

DEPS		=	$(SRCS:$S%.c=$D/%.d)
DEPS_BONUS	=	$(SRCS_BONUS:$S%.c=$D/%.d)

LDFLAGS	:= -framework OpenGL -framework AppKit

MLX_DIR	:=	minilibx
MLX_AR	:=	$(MLX_DIR)/libmlx.a

PARS_DIR:=	parser
PARS_AR	:=	$(PARS_DIR)/parser.a
PARS_AR_BONUS	:=	$(PARS_DIR)/parser_bonus.a

ifeq ($(MAKECMDGOALS),bonus)
export BONUS=1
endif

LIB_DIR	:=	libft
LIB_AR	:=	$(LIB_DIR)/libft.a

AR		=	ar rcs

RM		=	rm -rf

PREFIX	:=	$(MAKELEVEL)>>

.PHONY: all clean fclean re pack binary libft parser parser_bonus do debug leaks norm git

all			: $(DEPS) $(NAME)

$(NAME)		: $(LIB_AR) $(MLX_AR) $(PARS_AR) $(OBJS)
	@echo "\n$(PREFIX) Building binary "
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	@echo "$(PREFIX) Done! \n"
#-------------

bonus		:	$(DEPS_BONUS) $(NAME_BONUS)
#-------------

$(NAME_BONUS)		: $(LIB_AR) $(MLX_AR) $(PARS_AR_BONUS) $(OBJS_BONUS)
	@echo "\n$(PREFIX) Building bonus binary "
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
	@$(RM) $(NAME_BONUS)
	@echo "$(PREFIX) Done! \n"
	@echo "\n$(PREFIX) Cleaning cub3d *.d files "
	@$(RM) $D
	@echo "$(PREFIX) Done! \n"
	@make fclean -C $(LIB_DIR) -s
	@make fclean -C $(PARS_DIR) -s
	@make clean -C $(MLX_DIR) -s

re			: fclean all
#-------------

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

# Building parser bonus
$(PARS_AR_BONUS)	: parser_bonus ;

parser_bonus	:
	@echo "\n$(PREFIX) Invoking parser bonus makefile"
	@$(MAKE) bonus -C $(PARS_DIR) -j 4
	@echo "$(PREFIX) Done! \n"
#-------------

# Building mlx
$(MLX_AR)	: mlx ;

mlx:
	@echo "\n$(PREFIX) Invoking mlx makefile"
	@$(MAKE) -C $(MLX_DIR) -j 4 -s
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
