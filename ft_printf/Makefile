SRCS		=	ft_printf.c		ft_printf_utils.c	ft_printf_utils2.c

HEADERS		=	ft_printf.h

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o : %.c	${HEADERS}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} ${HEADERS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
