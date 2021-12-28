NAME		=	so_long

SRCS		=	$(MAIN_SRC) 

MAIN_SRC	=	so_long.c

LIBFT_A		=	libft.a
LIBFT_DIR	=	libft/
LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_A))

GNL			=	get_next_line.c		get_next_line_utils.c
GNL_SRC		=	$(addprefix gnl/, $(GNL))

HEADERS		= libft.h

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o : %.c	${HEADERS} Makefile
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@make -C $(LIBFT_DIR)
			@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDE) -o $(NAME)

all:		${NAME}

bonus:		${OBJS} ${OBJS_BONUS} ${HEADERS}
			ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
