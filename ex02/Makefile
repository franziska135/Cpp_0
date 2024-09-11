# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:52:51 by fmarggra          #+#    #+#              #
#    Updated: 2023/11/20 11:53:31 by fmarggra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	account
INC		= 	Account.hpp
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -g -std=c++98

AR		=	ar rc
RM		=	rm -f

SRC		=	Account.cpp tests.cpp

OBJS	=	$(SRC:.cpp=.o)

.PHONY:		all clean fclean re bonus

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

%.o: %.c 	$(INC)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			clean all