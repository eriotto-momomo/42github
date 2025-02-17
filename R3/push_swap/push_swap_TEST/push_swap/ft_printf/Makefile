HEADER	=	ft_printf.h
SRC		=	ft_printf.c \
			printf_itoa_unsigned.c \
			printf_itoa.c \
			printf_utils.c \
			put_ptr.c
OBJS	=	$(SRC:.c=.o)

NAME	= libftprintf.a
CC		= gcc
FLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) -c $(FLAG) -I ./ $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
