HEADER	=	get_next_line.h
SRC		=	get_next_line.c \
			get_next_line_utils.c
OBJS	=	$(SRC:.c=.o)

NAME	= get_next_line.a
CC		= gcc
FLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) -c $(FLAG) -I ./ $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
