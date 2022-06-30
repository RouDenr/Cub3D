# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 21:34:46 by vseel             #+#    #+#              #
#    Updated: 2022/06/30 21:52:25 by vseel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S		=	srcs/
O		=	objs
I		=	incs/
D		=	deps

NAME	=	parser.a
NAME_BIN=	parser

SRCS	=	parser.c					\
			parser_debug_utils.c		\
			parser_exit_utils.c			\
			parser_map_validation.c		\
			parser_file_utils.c			\
			lstfuncs_dyarr_1.c			\
			lstfuncs_dyarr_2.c

SRCS	+=	main_opt.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -g
# CFLAGS	=	-Wall -Wextra -Werror

SRCS	:=	$(foreach file,$(SRCS),$S$(file))

OBJS	=	$(SRCS:$S%.c=$O/%.o)
DEPS	=	$(SRCS:$S%.c=$D/%.d)

LIB_DIR	:=	libft
LIB_AR	:=	$(LIB_DIR)/libft.a

AR		=	ar rcs

RM		=	rm -rf

PREFIX	:=	$(MAKELEVEL)>>

.PHONY: all clean fclean re pack binary libft

# Building parser archive for minishell binary
all			: $(DEPS) $(NAME)

$(NAME)		: $(OBJS) $(LIB_AR)
	@echo "\n$(PREFIX) Building parser archive "
	@$(AR) $(NAME) $(filter-out $O/main_opt.o,$(OBJS)) $(LIB_AR)
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
	@echo "\n$(PREFIX) Cleaning parcer libft "
	@make clean -C $(LIB_DIR) -s
	@echo "$(PREFIX) Done! \n"
	@echo "\n$(PREFIX) Cleaning parcer *.o files "
	@$(RM) $O
	@echo "$(PREFIX) Done! \n"

fclean		: clean
	@echo "\n$(PREFIX) Cleaning parcer binary and archive "
	@$(RM) $(NAME) $(NAME_BIN)
	@echo "$(PREFIX) Done! \n"
	@echo "\n$(PREFIX) Cleaning parcer *.d files "
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

# Building parser libft
$(LIB_AR)	: libft ;

libft:
	@echo "\n$(PREFIX) Invoking parser libft makefile"
	@$(MAKE) -C $(LIB_DIR)
	@echo "$(PREFIX) Done! \n"
#-------------

ifeq ($(MAKECMDGOALS),fclean)
else ifeq ($(MAKECMDGOALS),clean)
else
-include $(DEPS)
endif
