/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_largestack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:57:50 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/15 18:18:01 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sort_largestack(t_stack *stack, t_size *size);
void	push_chunks(t_stack *stack, t_size *size, t_chunk *c);
void	optimize_rotation(t_stack *stack, t_size *size, int target, char stack_name);
int		get_nrst_c_element(int *stack, int size, int chunk);

int		get_nrst_c_element(int *stack, int size, int chunk)
{
	int i;
	int	j;
	int	diff;

	i = 0;
	while (i < size - 1)
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
	diff = size - j;
	printf("stack[i] = %d\nstack[j] = %d\nsize - j = %d\ni = %d\n", stack[i], stack[j], ((size) - j), i);
	if (i < diff)
		return (stack[i]);
	else if (i > diff)
		return (stack[j]);
	return (stack[i]);
}

void	optimize_rotation(t_stack *stack, t_size *size, int target, char stack_name)
{
////////////////////// !!!!!!!!!!!!!! //////////////////
	if (stack_name == 'r' && target <= (size->b / 2))
	{
		rr(stack, *size);
		if (stack->a[0] > stack->a[1])
			swap(stack->a, size->a, 'a', 1);
		return ;
	}
	if (stack_name == 'a')
	{
		if (target <= (size->a / 2))
			rotate(stack->a, size->a, stack_name, 1);
		else if (target > size->a / 2)
			reverse_rotate(stack->a, size->a, stack_name, 1);
		//else
		//	rotate(stack->a, size->a, stack_name, 1);
	}
	else if (stack_name == 'b')
	{
		if (target <= (size->b / 2))
			rotate(stack->b, size->b, stack_name, 1);
		if (target > size->b / 2)
			reverse_rotate(stack->b, size->b, stack_name, 1);
		//else
		//	rotate(stack->b, size->b, stack_name, 1);
	}
}

void	push_chunks(t_stack *stack, t_size *size, t_chunk *c)
{
	int	nearest_chunk_element;

	init_binp_and_sinp(stack, size, c);
	while (left_to_sort(stack->a, size->a, c->chunk[c->i], 's'))
	{
		if (stack->a[0] <= c->chunk[c->i] && (stack->a[0] < c->sinp || stack->a[0] > c->binp))
		{
			update_binp_and_sinp(stack, size, c);
			//printf("c->chunk[%d][%d]\nleft_to_sort = %d\n", c->i, c->chunk[c->i], left_to_sort(stack->a, size->a, c->chunk[c->i], 's'));
		}
		else if (stack->a[0] > c->sinp && stack->a[0] < c->binp)
		{
			place_in_between(stack, size);
			//printf("c->chunk[%d][%d]\nleft_to_sort = %d\n", c->i, c->chunk[c->i], left_to_sort(stack->a, size->a, c->chunk[c->i], 's'));
		}
		else
		{
			nearest_chunk_element = get_nrst_c_element(stack->a, size->a, c->chunk[c->i]);
			printf("c->chunk[%d][%d]\nleft_to_sort = %d\n", c->i, c->chunk[c->i], left_to_sort(stack->a, size->a, c->chunk[c->i], 's'));
			printf("nearest_chunk_element = [%d]\nlocation is [%d]\n", nearest_chunk_element, locate(stack->a, size->a, nearest_chunk_element));
			print_array(stack->a, size->a, 'a');
			//optimize_rotation(stack, size, locate(stack->a, size->a, nearest_chunk_element), 'a');
			rotate(stack->a, size->a, 'a', 1);
			//printf("stack->a[0][%d]\nstack->b[0][%d]\n", stack->a[0], stack->b[0]);
		}
	}
}

//print_array(stack->b, size->b, 'b');
//int	cnt = 0;
//printf("SORT_AROUND_MEDIAN\n");
//sort_around_median(stack, size, cnt);
//printf("INSERTION_SORT\n");
//insertion_sort(stack, size);

void	sort_largestack(t_stack *stack, t_size *size)
{
	int		n_chunk;
	t_chunk	c;

	n_chunk = 11;
	c.i = 0;
	get_chunks(stack, size->a, &c, n_chunk);
	/*while (c.i < n_chunk)
	{
		printf("c.chunk[%d] = %d\n", c.i, c.chunk[c.i]);
		c.i++;
	}
	ft_printf("---------------------------\n");*/

	c.i = 0;
	while (c.i < n_chunk)
	{
		push_chunks(stack, size, &c);
		c.i++;
	}

	c.i = 0;
	//if (size->a <= 6)
	//	sort_smallstack(stack, size);
	while (size->b > 0)
		push(stack->b, stack->a, size, 'a');
	/*ft_printf("---------------------------\n");
	while (c.i < n_chunk)
	{
		printf("c.chunk[%d] = %d\n", c.i, c.chunk[c.i]);
		c.i++;
	}*/
	free(c.chunk);
	return;
}
