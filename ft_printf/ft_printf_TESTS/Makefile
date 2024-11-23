# **************************************************************************** #
#                                COLOURS			                           #
# **************************************************************************** #
RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE = $(shell printf "\33[32;40m")
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
TEST_NAME 	= test_ft_printf
CC			= gcc
FLAG		= -Wall -Wextra -Werror

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	ar -rcs $(NAME) $(OBJS)
	@echo
	@echo "$(GREEN)Successfully COMPILED libftprintf.a$(RESET)"
	@echo

%.o: %.c  $(HEADER)
	$(CC) -c $(CFLAGS) -I ./ $< -o $@ 

test: $(NAME) test_main.c
	$(CC) $(CFLAGS) test_main.c -L. -lftprintf -o $(TEST_NAME)
	@@echo "$(YELLOW)/////START/////libftprintf.a/////TEST/////\n$(RESET)"
	./test_ft_printf
	@echo
	@echo "$(YELLOW)/////END//////libftprintf.a/////TEST/////$(RESET)"
	@echo

fclean: clean
	@rm -f $(NAME)
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

clean:
	@rm -rf *.o
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

re: fclean all

$(V).SILENT:
.PHONY: all clean fclean re