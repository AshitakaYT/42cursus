SRCS		=	ft_atoi.c		ft_isdigit.c	ft_memmove.c \
				ft_split.c		ft_strlcpy.c	ft_strstr.c \
				ft_bzero.c		ft_isprint.c	ft_memset.c \
				ft_strchr.c		ft_strlen.c		ft_strtrim.c \
				ft_calloc.c		ft_itoa.c		ft_putchar_fd.c \
				ft_strdup.c		ft_strmapi.c	ft_substr.c \
				ft_isalnum.c	ft_memchr.c		ft_putendl_fd.c \
				ft_striteri.c	ft_strncmp.c	ft_tolower.c \
				ft_isalpha.c	ft_memcmp.c		ft_putnbr_fd.c \
				ft_strjoin.c	ft_strnstr.c	ft_toupper.c \
				ft_isascii.c	ft_memcpy.c		ft_putstr_fd.c \
				ft_strlcat.c	ft_strrchr.c \

SRCS_BONUS	=	ft_lstadd_back.c	ft_lstclear.c	ft_lstiter.c \
				ft_lstmap.c			ft_lstsize.c	ft_lstadd_front.c \
				ft_lstdelone.c		ft_lstlast.c	ft_lstnew.c

HEADERS		= libft.h

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= libft.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o : %.c	${HEADERS} Makefile
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS}
			ar rc ${NAME} ${OBJS}


bonus:		${OBJS} ${OBJS_BONUS} ${HEADERS}
			ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
