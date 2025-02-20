# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
HEADER	=	so_long.h
SRCS	=	1.c

LIBFT		=	./libft/libft.a

OBJS	= $(SRCS:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #
NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L ./minilibx/ -lmlx -Ilmlx -lXext -lX11
# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #
all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			make clean -C libft
			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

run:		all
			./$(NAME) maps/map.ber

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re
