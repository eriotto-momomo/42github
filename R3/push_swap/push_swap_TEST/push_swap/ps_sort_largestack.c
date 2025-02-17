/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_largestack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:57:50 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/17 10:21:23 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sort_largestack(t_stack *stack, t_size *size);
void	push_chunks(t_stack *stack, t_size *size, t_chunk *c);
void	optimize_rotation(t_stack *stack, t_size *size, int target, char stack_name);
int		get_closest_chunk_part(int *stack, int size, int chunk);
int		get_next_chunk_part(int *stack, int size, int chunk);

int		get_next_chunk_part(int *stack, int size, int chunk)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (stack[i] <= chunk)
			break ;
		i++;
	}
	return (stack[i]);
}

//printf("stack[i] = %d\nstack[j] = %d\nsize - j = %d\ni = %d\n", stack[i], stack[j], ((size) - j), i);
int		get_closest_chunk_part(int *stack, int size, int chunk)
{
	int i;
	int	j;
	//int	dist;

	i = 0;
	while (i < size)
	{
		if (stack[i] <= chunk)
			break;
		i++;
	}
	j = size - 1;
	while (j >= 0 )
	{
		if (stack[j] <= chunk)
			break;
		j--;
	}
	//dist = size - j;
	//if (i < dist)
	//else if (i > dist)
	if (i < size - j)
		return (stack[i]);
	else if (i < size - j)
		return (stack[j]);
	return (stack[i]);
}

void	optimize_rotation(t_stack *stack, t_size *size, int target, char stack_name)
{
	if (stack_name == 'a')
	{
		if (locate(stack->a, size->a, target) <= ((size->a + 1)/ 2))
			rotate(stack->a, size->a, stack_name, 1);
		else if (locate(stack->a, size->a, target) > ((size->a + 1) / 2))
			reverse_rotate(stack->a, size->a, stack_name, 1);
	}
	else if (stack_name == 'b')
	{
		if (locate(stack->b, size->b, target) <= ((size->b + 1) / 2))
			rotate(stack->b, size->b, stack_name, 1);
		else if (locate(stack->b, size->b, target) > ((size->b + 1) / 2))
			reverse_rotate(stack->b, size->b, stack_name, 1);
	}
}

//printf("[binp_and_sinp] BINP[%d] SINP[%d]\n", c->binp, c->sinp);
//printf("BINP[%d] back at top!\n", c->binp);
//printf("c->chunk[%d][%d]\nleft_to_sort = %d\n", c->i, c->chunk[c->i], left_to_sort(stack->a, size->a, c->chunk[c->i], 's'));
void	push_chunks(t_stack *stack, t_size *size, t_chunk *c)
{
	int	target;

	init_binp_and_sinp(stack, size, c);
	while (left_to_sort(stack->a, size->a, c->chunk[c->i], 's'))
	{
		if (stack->a[0] <= c->chunk[c->i] && (stack->a[0] < c->sinp || stack->a[0] > c->binp))
			update_binp_and_sinp(stack, size, c);
		else if (stack->a[0] > c->sinp && stack->a[0] < c->binp)
			place_in_between(stack, size);
		else
			go_to_next_chunk_part(stack, size, c);
	}
	if (!left_to_sort(stack->a, size->a, c->chunk[c->i], 's'))
	{
		while (stack->b[0] != c->binp)
		{
			target = get_closest_chunk_part(stack->a, size->a, (c->chunk[c->i] + 1));
			if (locate(stack->b, size->b, c->binp) > ((size->b + 1) / 2)
			&& stack->a[0] != target && stack->b[0] != c->binp)
				rrr(stack, *size);
			else
				optimize_rotation(stack, size, c->binp, 'b');
		}
	}
	return ;
}

/// BACKUP V1 ///
/*void	push_chunks(t_stack *stack, t_size *size, t_chunk *c)
{
	int	target;
	int	perf_loc;

	init_binp_and_sinp(stack, size, c);
	while (left_to_sort(stack->a, size->a, c->chunk[c->i], 's'))
	{
		if (stack->a[0] <= c->chunk[c->i] && (stack->a[0] < c->sinp || stack->a[0] > c->binp))
			update_binp_and_sinp(stack, size, c);
		else if (stack->a[0] > c->sinp && stack->a[0] < c->binp)
			place_in_between(stack, size);
		else
		{
				target = get_next_chunk_part(stack->a, size->a, c->chunk[c->i]);
				perf_loc = perfect_location(stack->b, size->b, target);
				if (locate(stack->b, size->b, perf_loc) <= ((size->b + 1) / 2)
				&& stack->a[0] != target && stack->b[0] != perf_loc)
					rr(stack, *size);
				else
					rotate(stack->a, size->a, 'a', 1);
		}
	}
	if (!left_to_sort(stack->a, size->a, c->chunk[c->i], 's'))
	{
		while (stack->b[0] != c->binp)
		{
			target = get_closest_chunk_part(stack->a, size->a, (c->chunk[c->i] + 1));
			if (locate(stack->b, size->b, c->binp) > ((size->b + 1) / 2)
			&& stack->a[0] != target && stack->b[0] != c->binp)
				rrr(stack, *size);
			else
				optimize_rotation(stack, size, c->binp, 'b');
		}
	}
	return ;
}*/

//print_array(stack->b, size->b, 'b');
//print_array(stack->a, size->a, 'a');
//int	cnt = 0;
//printf("SORT_AROUND_MEDIAN\n");
//sort_around_median(stack, size, cnt);
//printf("INSERTION_SORT\n");
//insertion_sort(stack, size);

void	sort_largestack(t_stack *stack, t_size *size)
{
	int		n_chunk;
	t_chunk	c;

	n_chunk = 0;
	if (size->a <= 40)
		n_chunk = 2;
	else if (size->a <= 150)
		n_chunk = 6;
	else if (size->a > 150)
		n_chunk = 14;
	c.i = 0;
	get_chunks(stack, size->a, &c, n_chunk);

	/*while (c.i < n_chunk)
	{
		printf("c.chunk[%d] = %d\n", c.i, c.chunk[c.i]);
		c.i++;
	}
	ft_printf("---------------------------\n");*/
	//push_chunks(stack, size, &c);

	c.i = 0;
	while (c.i < n_chunk)
	{
		push_chunks(stack, size, &c);
		c.i++;
	}
	c.i = 0;
	while (size->b > 0)
		push(stack->b, stack->a, size, 'a');

	/*ft_printf("---------------------------\n");
	while (c.i < n_chunk)
	{
		printf("c.chunk[%d] = %d\n", c.i, c.chunk[c.i]);
		c.i++;
	}*/

	free(c.chunk);
	return ;
}
