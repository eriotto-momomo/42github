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
HEADER	=	push_swap.h
SRC		=	$(wildcard *.c)			# Tous les fichiers .c du répertoire

OBJS	= $(SRC:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME		= libpushswap.a
TEST_NAME	= PUSHSWAP_TEST.a
CC			= gcc
FLAG		= -Wall -Wextra -Werror

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

# Compilation de la bibliothèque
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Successfully COMPILED $(NAME)$(RESET)"

# Compilation et exécution du test
run: all $(TEST_NAME)
	@echo "$(YELLOW)/////START/////$(TEST_NAME)/////TEST/////$(RESET)"
	./$(TEST_NAME)
	@echo "$(YELLOW)/////END///////$(TEST_NAME)/////TEST/////$(RESET)"

# Compilation de l'exécutable de test
$(TEST_NAME): push_swap_TESTS.c
	$(CC) $(FLAGS) push_swap_TESTS.c -L. -lpushswap -o $(TEST_NAME)

# Compilation des fichiers objets
%.o: %.c $(HEADER)
	$(CC) -c $(FLAGS) -I ./ $< -o $@

# Nettoyage
clean:
	@rm -rf *.o *.a
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

fclean: clean
	@rm -f $(NAME) $(TEST_NAME)
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

re: fclean all

.SILENT:
.PHONY: all clean fclean re run
