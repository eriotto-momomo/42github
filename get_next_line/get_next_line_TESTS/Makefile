# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
HEADER 	= get_next_line.h
SRC	= get_next_line.c \
get_next_line_utils.c \

OBJS	= $(SRC:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #
NAME		= get_next_line.a
CC			= gcc
FLAG		= -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #ßßß
all: $(NAME)

$(NAME): $(OBJS) get_next_line.h
	ar -rcs $(NAME) $(OBJS)
	@echo
	@echo "$.Successfully COMPILED get_next_line.a$(RESET)"
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
