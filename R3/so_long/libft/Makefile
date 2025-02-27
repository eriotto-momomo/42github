HEADER	= libft.h
NAME	= libft.a

LIBFT_DIR		= libft
LIBCUSTOM_DIR	= libcustom

SRCS_LIBFT	= \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	get_next_line.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_printf/ft_printf.c \
	ft_printf/printf_itoa_unsigned.c \
	ft_printf/printf_itoa.c \
	ft_printf/printf_put_ptr.c \
	ft_printf/printf_utils.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

SRCS_LIBCUSTOM	= \
	$(LIBCUSTOM_DIR)/ft_atoi_safe.c \
	$(LIBCUSTOM_DIR)/ft_free_array.c \
	$(LIBCUSTOM_DIR)/ft_free_gnl.c

OBJS_LIBFT		= $(SRCS_LIBFT:%.c=$(LIBFT_DIR)/%.o)
OBJS_LIBCUSTOM	= $(SRCS_LIBCUSTOM:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_LIBFT) $(OBJS_LIBCUSTOM)
	ar rc $(NAME) $(OBJS_LIBFT) $(OBJS_LIBCUSTOM)
	@echo "Successfully COMPILED $(NAME)"

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBCUSTOM_DIR)/%.o: $(LIBCUSTOM_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_LIBFT) $(OBJS_LIBCUSTOM)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
