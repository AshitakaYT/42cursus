NAME = philo

SRC = main.c srcs/philo.c srcs/utils.c srcs/init.c srcs/actions.c srcs/time.c srcs/end.c srcs/isbegfin.c

OBJ = $(SRC:.c=.o)
OBJSDIR	= objs/
OBJS = $(addprefix $(OBJSDIR), $(OBJ))

FLAGS = -Wall -Wextra -Werror

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME) Makefile

$(OBJSDIR)%.o : %.c		hdrs/philosophers.h
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

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@rm -rf $(OBJSDIR)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all

.phony: philo re fclean exe clean all
