# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 13:56:09 by aucousin          #+#    #+#              #
#    Updated: 2022/04/26 15:26:51 by aucousin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c srcs/utils.c srcs/init.c srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c srcs/parsing.c srcs/solve_small.c

OBJ = $(SRC:.c=.o)
OBJSDIR	= objs/
OBJS = $(addprefix $(OBJSDIR), $(OBJ))

FLAGS = -Wall -Wextra -Werror
LINKS = libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: maker $(NAME)

$(OBJSDIR)%.o : %.c		hdrs/push_swap.h libft/libft.a Makefile
	@mkdir -p $(OBJSDIR)
	@mkdir -p $(OBJSDIR)srcs
	@gcc $(FLAGS) -c $< -o $@
	@echo $(CURSIVE)$(GRAY) "     - creating .o ..." $(NONE)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJS) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

maker:
		@make -C libft

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@make clean -C libft
	@rm -rf $(OBJ)
	@rm -rf $(OBJSDIR)
	
fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make fclean -C libft
	
re: fclean all

.PHONY: make re fclean clean maker all