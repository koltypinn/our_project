# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flyte <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 17:17:24 by flyte             #+#    #+#              #
#    Updated: 2021/09/27 17:17:26 by flyte            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

FLAG = -Wall -Wextra -Werror

CC = clang++

RM = rm -f

RMD = rm -d

SRC = ./make_phonebook.cpp ./Contact.class.cpp ./Phonebook.class.cpp

INC = ./includes

OBJDIR = obj

O_FILES = $(SRC:%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.cpp 
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

$(NAME): $(O_FILES) Makefile $(INC)/*.hpp
	$(CC) $(FLAG) obj/*.o -I$(INC) -o $(NAME)
	
clean:
	$(RM) $(O_FILES)
	$(RMD) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re all

