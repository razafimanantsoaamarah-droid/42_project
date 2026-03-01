NAME= libftprintf.a
CC= cc
FLAGS= -Wall -Werror -Wextra
INCLUDE_DIR= ft_printf.h
SRCS= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_hexa.c
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

test: $(NAME)
	cc $(FLAGS) -o test_prog test_ft_printf.c $(NAME)
	./test_prog

.PHONY: all clean fclean re test