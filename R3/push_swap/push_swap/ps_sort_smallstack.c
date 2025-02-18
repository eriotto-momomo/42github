/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_smallstack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:11:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/15 23:50:21 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sort_s_ascending(int *stack, int size, char c);
void	sort_smallstack(t_stack *stack, t_size *size);
void	sort_small(t_stack *stack, t_size *size);
int		get_smallest(int *stack, int size);

int	get_smallest(int *stack, int size)
{
	int	i;
	int	min;

	min = stack[0];
	i = 0;
	while (i < size)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

void	sort_small(t_stack *stack, t_size *size)
{
	int	smallest_int;

	while (size->a > 3)
	{
		smallest_int = get_smallest(stack->a, size->a);
		while (stack->a[0] != smallest_int)
		{
			if (smallest_int == stack->a[1] || smallest_int == stack->a[2])
				rotate(stack->a, size->a, 'a', 1);
			else
				reverse_rotate(stack->a, size->a, 'a', 1);
		}
		push(stack->a, stack->b, size, 'b');
	}
	sort_s_ascending(stack->a, size->a, 'a');
	while (size->b > 0)
		push(stack->b, stack->a, size, 'a');
}

void	sort_smallstack(t_stack *stack, t_size *size)
{
	if ((size->a == 2) && (stack->a[0] > stack->a[1]))
		swap(stack->a, size->a, 'a', 1);
	else if (size->a <= 3)
		sort_s_ascending(stack->a, size->a, 'a');
	else if (size->a > 3 && size->a <= 6)
		sort_small(stack, size);
	else
		return ;
}

// Sort in ascending order the following cases:
// [2, 1] -> s
// [2, 1, 3] -> s
// [3, 1, 2] -> r
// [2, 3, 1] -> rr
// [1, 3, 2] -> rr/s
// [3, 2, 1] -> s/rr
void	sort_s_ascending(int *stack, int size, char c)
{
	if (size == 3)
	{
		if (stack[0] > stack[1] && stack[0] < stack[2] && stack[1] < stack[2])
			swap(stack, size, c, 1);
		else if (stack[0] > stack[1] && stack[0] > stack[2]
			&& stack[1] < stack[2])
			rotate(stack, size, c, 1);
		else if (stack[0] < stack[1] && stack[0] > stack[2]
			&& stack[1] > stack[2])
			reverse_rotate(stack, size, c, 1);
		else if (stack[0] > stack[1] && stack[0] > stack[2]
			&& stack[1] > stack[2])
		{
			swap(stack, size, c, 1);
			reverse_rotate(stack, size, c, 1);
		}
		else if (stack[0] < stack[1] && stack[0] < stack[2]
			&& stack[1] > stack[2])
		{
			reverse_rotate(stack, size, c, 1);
			swap(stack, size, c, 1);
		}
	}
}
