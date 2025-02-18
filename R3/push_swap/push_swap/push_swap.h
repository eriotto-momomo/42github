/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:16:45 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/17 22:59:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_size
{
	int	a;
	int	b;
}	t_size;

typedef struct s_stack
{
	int	*a;
	int	*b;
}	t_stack;

typedef struct s_chunk
{
	int	*chunk;
	int	i;
	int	sinp;
	int	binp;
}	t_chunk;

// ps_checks.c
int		*check_and_convert(int argc, char *argv[], int *stack_size);
int		validate_and_count(int size, char **array, int i);
int		check_dupplicates(int *int_array, int size);
int		check_conditions(char **array, int *i, int *j);
void	arg_is_valid(int argc, char **argv, int *stack_size, int **stack);

// ps_conversion.c
int		array_conversion(int argc, char **argv, int *int_array);
int		conversion(int size, char **char_array, int *int_array);
void	*free_int_or_char_array(void *array, int size, int mode);
void	handle_arg(int argc, char *argv[]);
void	error_and_exit(void);

// ps_main.c
int		main(int argc, char *argv[]);

//ps_median_calculation.c
int		ft_quickselect(int *stack, int left, int right, int k);
int		ft_quickselect_partition(int *stack, int left, int right);
void	ft_quickselect_swap(int *a, int *b);
void	get_chunks(t_stack *stack, int size, t_chunk *c, int n_chunk);

// ps_simultaneous_instructions.c
void	rrr(t_stack *stack, t_size size);
void	rr(t_stack *stack, t_size size);
void	ss(t_stack *stack, t_size size);

// ps_single_instructions.c
void	rotate(int *stack, int size, char stack_name, int mode);
void	reverse_rotate(int *stack, int size, char stack_name, int mode);
void	push(int *src_stack, int *dst_stack, t_size *size, char stack_name);
void	swap(int *stack, int size, char stack_name, int mode);

//ps_sort_l_insertion.c
void	init_binp_and_sinp(t_stack *stack, t_size *size, t_chunk *c);
void	update_binp_and_sinp(t_stack *stack, t_size *size, t_chunk *c);
void	place_in_between(t_stack *stack, t_size *size);
void	go_to_next_chunk_part(t_stack *stack, t_size *size, t_chunk *c);
void	go_to_binp(t_stack *stack, t_size *size, t_chunk *c);

// ps_sort_largestack.c
void	sort_largestack(t_stack *stack, t_size *size);
void	push_chunks(t_stack *stack, t_size *size, t_chunk *c);
void	optimize_rotation(t_stack *stack, t_size *size, int target, char s_nme);
int		get_closest_chunk_part(int *stack, int size, int chunk);
int		get_next_chunk_part(int *stack, int size, int chunk);

// ps_sort_smallstack.c
void	sort_s_ascending(int *stack, int size, char c);
void	sort_smallstack(t_stack *stack, t_size *size);
void	sort_small(t_stack *stack, t_size *size);
int		get_smallest(int *stack, int size);

// ps_utils.c
int		to_sort(int *stack, int size);
int		left_to_sort(int *stack, int size, int pivot, int mode);
int		perfect_location(int *stack, int size, int target);
int		locate(int *stack, int size, int target);

#endif
