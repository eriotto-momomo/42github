#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int	*check_and_convert(int argc, char *argv[], int *stack_size);
//int	*check_and_convert(int argc, char *argv[]);
int	format_check(char **array, int i);
int	array_conversion(int size, int start, char **str_array, int *int_array);
int	arg_is_valid(int size, char **str_array);
void	*free_int_or_str_array(void *array, int type, int size);
int	ft_safe_atoi(const char *str, int *error);

void	compare_two_elements(int *stack, int stack_size);
void	reverse_rotate(int *stack, int stack_size);
void	rotate(int *stack, int stack_size);
void	push(int *src_stack, int *dst_stack, int *src_size, int *dst_size);
void	swap(int *stack);

void	*push_swap(int *a_stack, int *stack_size);
void	sort(int *a_stack, int *b_stack, int *a_size, int *b_size);

#endif
