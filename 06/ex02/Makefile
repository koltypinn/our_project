NAME		= type

SRCS		= main.cpp\
			srcs/type.cpp

INC			= -Iincludes

HEADER		= includes/*

FLAGS		= -std=c++98 -Wall -Wextra -Werror

CC			= clang++

all:		$(NAME)

$(NAME):	$(SRCS) $(HEADER)
			$(CC) $(FLAGS) $(INC) $(SRCS) -o $(NAME)

clean:

fclean:
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all fclean clean re