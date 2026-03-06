NAME= libftprintf.a
CC= cc
FLAGS= -Wall -Werror -Wextra
INCLUDE_DIR= ft_printf.h
SRCS= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_print_hexa.c ft_print_pointer.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re