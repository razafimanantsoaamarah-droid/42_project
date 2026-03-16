#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maherraz <maherraz@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 10:00:00 by maherraz          #+#    #+#              #
#    Updated: 2026/03/16 10:00:00 by maherraz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libsoraty.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/soraty.c \
       src/soraty_putchar.c \
       src/soraty_putstr.c \
       src/soraty_putnbr.c \
       src/soraty_print_hexa.c \
       src/soraty_print_pointer.c \
	   src/soraty_template.c \
       src/soraty_value_handler.c \
       src/soraty_parser.c
OBJS = $(SRCS:.c=.o)
HEADER = inc/soraty.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
test: $(NAME)
	$(CC) $(CFLAGS) -o test_program main_test.c -L. -lsoraty
	./test_program

.PHONY: all clean fclean re test