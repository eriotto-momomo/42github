# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
HEADER 	= ft_printf.h
SRC	= ft_printf.c \
printf_itoa.c \
printf_itoa_unsigned.c \
printf_putchar.c \
printf_putstr.c \
puthex_dec.c \
puthex_ptr.c \

OBJS	= $(SRC:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #
NAME		= libftprintf.a
CC			= gcc
FLAG		= -Wall -Wextra -Werror

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #ßßß
all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	ar -rcs $(NAME) $(OBJS)
	@echo
	@echo "$.Successfully COMPILED libftprintf.a$(RESET)"
	@echo

%.o: %.c  $(HEADER)
	$(CC) -c $(CFLAGS) -I ./ $< -o $@

fclean: clean
	@rm -f $(NAME)
	@clear
	@echo
	@echo "$.    ┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

clean:
	@rm -rf *.o
	@clear
	@echo
	@echo "$.    ┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

re: fclean all

.PHONY: all clean fclean re
