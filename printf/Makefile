# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/15 21:15:20 by youlee            #+#    #+#              #
#    Updated: 2020/04/03 19:21:03 by youlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

NAMEL = libft.a

SRCS = ./printf/

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -c -I $(SRCS) $(SRC)
		ar rc $(NAME) $(OBJ)
clean:
		/bin/rm -f $(OBJ)
fclean: clean
		/bin/rm -f $(NAME)
bonus:
		$(CC) $(CFLAGS) -c -I $(SRCS) $(SRC2)
		ar rc $(NAME) $(OBJ2)
re: fclean all
