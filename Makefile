
CC := gcc

NAME := minishell

FLAGS := -Wall -Wextra -Werror

SOURCE := Sources/bilt1.c Sources/bilt2.c Sources/bilt3.c Sources/helper.c Sources/lib.c Sources/main.c Sources/parser.c Sources/lib1.c Sources/lib2.c

OBJECTS := $(SOURCE:.c=.o)

GREEN= \033[1;32m
RED= \033[1;31m

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) -lreadline -ledit
	@echo "$(GREEN)Project is successfully compiled"

$(OBJECTS): %.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJECTS)
	@echo "$(RED)Deleting objects files"

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(OBJECTS)
	@echo "$(RED)Deleting projects files"

re : fclean all

