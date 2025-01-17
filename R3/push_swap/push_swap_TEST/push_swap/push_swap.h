#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>



//ps_check_and_convert.c
int	*check_and_convert(int argc, char *argv[], int *stack_size);
int	format_check(char **array, int i);
int	array_conversion(int size, int start, char **str_array, int *int_array);
int	arg_is_valid(int size, char **str_array);
void	*free_int_or_str_array(void *array, int type, int size);

//ps_utils.c
int	ft_safe_atoi(const char *str, int *error);

//ps_instructions.c
void	reverse_rotate(int *stack, int size);
void	rotate(int *stack, int size);
void	push(int *src_stack, int *dst_stack, int *src_size, int *dst_size);
void	swap(int *stack);

//ps_main.c
void	comb_sort(int *stack, int size);
void	rotate_combsort(int *stack, int size, int n, int rev);
int	new_gap(int gap);
int	main(int argc, char *argv[]);

//ps_algorithm.c
int	is_sorted(int size, int *stack);
int	get_average_median(int size, int *stack, int *min, int *max);
int	get_closest_median(int size, int *stack, int *min, int *max);
void quicksort(int *a_stack, int *b_stack, int *b_size, int *a_size);
void	*push_swap(int *a_stack, int *size);

#endif
