
# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #

HEADER 	= ft_printf.h
SRC	= ft_printf.c \
dec_to_lowerhex.c \
dec_to_upperhex.c \
printf_itoa.c \
printf_putchar.c \
printf_putstr.c \
ptr_to_hex.c \
unsigned_itoa.c \

OBJS	= $(SRC:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME 	= libftprintf.a
CC		= gcc
FLAG	= -Wall -Wextra -Werror

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	ar -rcs $(NAME) $(OBJS)


%.o: %.c  $(HEADER)
	$(CC) -c $(CFLAGS) -I ./ $< -o $@  


fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)	

clean:
	rm -f $(OBJS)
	make -C $(LIB_PATH) clean

re: fclean all

.PHONY: all clean fclean re