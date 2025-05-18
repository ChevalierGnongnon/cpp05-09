# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 13:48:30 by chhoflac          #+#    #+#              #
#    Updated: 2025/05/18 14:15:58 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScalarConverter

SOURCES = ScalarConverter.cpp \
		main.cpp

OBJS = $(SOURCES:.cpp=.o)

RM = rm -rf

CC = c++

FLAGS = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re