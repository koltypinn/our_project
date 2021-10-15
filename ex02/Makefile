# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flyte <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 17:16:02 by flyte             #+#    #+#              #
#    Updated: 2021/09/27 17:16:05 by flyte            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_account

FLAG = -Wall -Wextra -Werror

CC = clang++

RM = rm -f

RMD = rm -d

SRC = ./Account.cpp ./test.cpp

OBJDIR = obj

O_FILES = $(SRC:%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.cpp
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

$(NAME): $(O_FILES) Makefile ./*.hpp
	$(CC) $(FLAG) $(SRC) -I*.hpp -o $(NAME)
	
clean:
	$(RM) $(O_FILES)
	$(RMD) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re all
