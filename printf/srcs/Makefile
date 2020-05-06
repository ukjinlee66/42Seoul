# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/15 21:15:20 by youlee            #+#    #+#              #
#    Updated: 2020/04/28 19:15:03 by youlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

NAMEL = libft.a

HEADERP = ft_printf.h

HEADERL = libft.h

SRCS = ./srcs/

SRCSL = ./srcs/Libft/

SRC = ft_flag.c \
	  ft_format.c \
	  ft_init.c \
	  ft_parse_format.c \
	  ft_percent.c \
	  ft_pointer.c \
	  ft_precision.c \
	  ft_print_c.c \
	  ft_print_d.c \
	  ft_print_s.c \
	  ft_print_str.c \
	  ft_printf.c \
	  ft_put_left.c \
	  ft_put_right.c \
	  ft_str_function.c \
	  ft_unsigned.c \
	  ft_unsigned2.c \
	  ft_utoa.c \
	  ft_width.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		cd $(SRCSL); make bonus
		cd $(SRCSL); cp $(NAMEL) ../../$(NAME)
		$(CC) $(CFLAGS) -c $(addprefix srcs/, $(SRC)) -I $(INCLUDES)
		ar rcs $(NAME) $(OBJ)
clean:
		cd $(SRCSL); make clean
		/bin/rm -f $(OBJ)

fclean: clean
		cd $(SRCSL); make fclean
		/bin/rm -f $(NAME)

re: fclean all
	cd $(SRCSL); make re
