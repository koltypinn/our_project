# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flyte <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 17:17:12 by flyte             #+#    #+#              #
#    Updated: 2021/09/27 17:17:14 by flyte            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

FLAG = -Wall -Wextra -Werror

CC = clang++

RM = rm -f

RMD = rm -d

SRC = ./megaphone.cpp

OBJDIR = obj

O_FILES = $(SRC:%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.cpp
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

$(NAME): $(O_FILES) Makefile
	$(CC) $(FLAG) $(SRC) -o $(NAME)
	
clean:
	$(RM) $(O_FILES)
	$(RMD) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re all

