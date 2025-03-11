# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #

HEADER		=	so_long.h
SRCS		=	src/main.c \
				src/handle_moves.c \
				src/init_map.c \
				src/inputs.c \
				src/parse_map.c \
				src/put_assets.c \
				src/utils.c

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_DIR		=	./minilibx-linux
MLX_LIB		=	$(MLX_DIR)/libmlx_Linux.a
OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX_LIB)
			$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(LIBFT):
			make -C $(LIBFT_DIR)

$(MLX_LIB):
			make -C $(MLX_DIR)

%.o: %.c
			$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

run:		all
			./$(NAME) maps/map_42.ber

clean:
			$(RM) $(OBJS)
			make clean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C $(LIBFT_DIR)

re:			fclean all

leaks:		all
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map_42.ber

.PHONY:		all clean fclean re run
