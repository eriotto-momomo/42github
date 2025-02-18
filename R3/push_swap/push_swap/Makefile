# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
HEADER	=	push_swap.h
SRCS	=	ps_checks.c \
			ps_conversion.c \
			ps_main.c \
			ps_median_calculation.c \
			ps_simultaneous_instructions.c \
			ps_single_instructions.c \
			ps_sort_l_insertion.c \
			ps_sort_largestack.c \
			ps_sort_smallstack.c \
			ps_utils.c

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

FT_PRINTF_DIR	=	./ft_printf
FT_PRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a

OBJS	= $(SRCS:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #
NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #
all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)
	@echo "Successfully COMPILED $(NAME)$(RESET)"

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) $< -o $@

clean:
	rm -rf $(OBJS) $(TEST_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run
