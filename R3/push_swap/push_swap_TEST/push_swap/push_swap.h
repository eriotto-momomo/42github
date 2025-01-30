#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>



//ps_check_and_convert.c
//int	*check_and_convert(int argc, char *argv[], int *stack_size);
//int	validate_and_count(int size, char **array, int i, int j);
//int	array_conversion(int size, int start, char **str_array, int *int_array);
//int	arg_is_valid(int size, char **str_array);
//void	*free_int_or_str_array(void *array, int type, int size);

//ps_checks.c
int	*check_and_convert(int argc, char *argv[], int *stack_size);
int	validate_and_count(int size, char **array, int i, int j);
void	arg_is_valid(int size, char **str_array, int *stack_size, int **a_stack);
void	error_and_exit();

//ps_conversion.c
int	array_conversion(int size, int start, char **str_array, int *int_array);
void	*free_int_or_str_array(void *array, int type, int size);

//ps_combsort.c
//void	comb_sort(int *stack, int size);
//int	new_gap(int gap);
//void	rotate_combsort(int *stack, int size, int n, int rev);

//ps_sort_smallstack.c
void	sort_case_s(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_small_stack(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	adjust_sort_s(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_six_int(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_push_s(int *a_stack, int *b_stack, int *a_size, int *b_size);

//ps_sort_largestack.c
int	sort_and_pushback(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	get_smallest(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_large_stack(int *a_stack, int *b_stack, int *a_size, int *b_size);

//ps_sort_case.c
void	sort_case_l(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_ascending(int *stack, int *size);
void	sort_descending(int *stack, int *size);

//ps_get_median.c
int	get_exact_median(int size, int *stack);
int	get_average_median(int size, int *stack);
int	calculate_median(int size, int *stack, int *min, int *max);
void	get_min_max(int size, int *stack, int *min, int *max);
void	count_elements(int *stack, int *med, int *lower_count, int *equal_count);

//ps_utils.c
int	ft_safe_atoi(const char *str, int *error);
int	check_disorder(int *stack, int size);
int	is_sorted(int *stack, int size);
int	locate_int(int *stack, int n);
int calculate_rot_dir(int *stack, int size, int pivot);

//ps_single_stack_instructions.c
void	call_instruction(int instruction, int *stack, int size, char c);
void	reverse_rotate(int *stack, int size);
void	rotate(int *stack, int size);
void	push(int *src_stack, int *dst_stack, int *src_size, int *dst_size);
void	swap(int *stack);

//ps_simultaneous_instructions.c
void	rrr(int *a_stack, int *b_stack, int a_size, int b_size);
void	rr(int *a_stack, int *b_stack, int a_size, int b_size);
void	ss(int *a_stack, int *b_stack);

//ps_main.c
int	main(int argc, char *argv[]);

// À delete!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void	print_array(int *array, int size, char c);
// À delete!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


#endif
