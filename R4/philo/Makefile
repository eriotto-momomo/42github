# **************************************************************************** #
# DIRECTORIES
# **************************************************************************** #
HEADER	=	philo.h
SRCS	=	main.c \
			./init/init.c \
			./init/parse_input.c \
			./dinner/philos.c \
			./dinner/threads.c \
			./utils/clean_free.c \
			./utils/handlers.c \
			./utils/utils.c \
			./helpers.c

OBJS	=	$(SRCS:.c=.o)
# **************************************************************************** #
# VARIABLES
# **************************************************************************** #
NAME	=	philo
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
# **************************************************************************** #
# TARGETS
# **************************************************************************** #
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32mSuccessfully compiled: $(NAME)\033[0m"

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	rm -rf $(OBJS)
	@echo "\033[1;32mSuccessfully cleaned project\033[0m"

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: ./philo 5  10 5 5 5

.PHONY: all clean fclean re run
