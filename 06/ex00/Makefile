NAME		= convert

SRCS		= main.cpp\
			srcs/convert.cpp

CC 			= clang++

INC			= -Iincludes

HEADER		= includes/convert.hpp

FLAGS		= -std=c++98 -Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(SRCS) $(HEADER)
			$(CC) $(FLAGS) $(INC) $(SRCS) -o $(NAME)

clean:

fclean:
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
