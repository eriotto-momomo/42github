# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
HEADER	= push_swap.h
SRCS	=	ps_check_and_convert.c \
			ps_instructions.c \
			ps_main.c \
			ps_utils.c

TEST_SRCS = ps_check_and_convert.c \
			ps_instructions.c \
			ps_utils.c \
			test_main_push_swap.c

TEST_OBJS = $(TEST_SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT	= $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

OBJS	= $(SRCS:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #
NAME		= push_swap
TEST_NAME	= test_push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #
all: $(LIBFT) $(FT_PRINTF) $(NAME)

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build ft_printf
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Build push_swap executable
$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)
	@echo "Successfully COMPILED $(NAME)$(RESET)"

# Build and execute the test
run: $(NAME) $(TEST_NAME)
	@echo "|||| $(TEST_NAME) |START|"
	@./$(TEST_NAME)
	@echo "|||| $(TEST_NAME) ||END||"

# Compile the test executable
$(TEST_NAME): $(TEST_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(TEST_OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(TEST_NAME)

# Compile object files
%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) $< -o $@

# Cleaning
clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run
