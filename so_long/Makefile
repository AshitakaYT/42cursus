# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 13:56:09 by aucousin          #+#    #+#              #
#    Updated: 2022/04/27 16:35:55 by aucousin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c srcs/window.c srcs/image.c srcs/hooks.c srcs/map_parsing.c srcs/map_parsing2.c srcs/read.c srcs/moves.c srcs/free.c

OBJ = $(SRC:.c=.o)
OBJSDIR	= objs/
OBJS = $(addprefix $(OBJSDIR), $(OBJ))

FLAGS = -Wall -Wextra -Werror
# -I /usr/X11/include -g
#LINKS = -L /usr/X11/lib -lmlx -Imlx -lXext -lX11 -lz -lm libft/libft.a -Lmlx
LINKS = ft_printf/libftprintf.a libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx -L./mlx

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: maker $(NAME)

$(OBJSDIR)%.o : %.c		srcs/so_long.h
	@mkdir -p $(OBJSDIR)
	@mkdir -p $(OBJSDIR)srcs
	@gcc $(FLAGS) -c $< -o $@
	@echo $(CURSIVE)$(GRAY) "     - creating .o ..." $(NONE)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJS) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
#	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

maker:
		@make -C libft
		@make -C ft_printf

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@make clean -C libft
	@make clean -C ft_printf
	@rm -rf $(OBJ)
	@rm -rf $(OBJSDIR)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@rm -rf libft/libft.a
	@rm -rf ft_printf/libftprintf.a

re: fclean all

