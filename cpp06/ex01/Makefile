# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 15:47:07 by chhoflac          #+#    #+#              #
#    Updated: 2025/05/21 17:23:50 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScalarConverter

SOURCES = Serializer.cpp \
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