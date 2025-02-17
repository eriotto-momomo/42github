/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_l_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:02:08 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/13 12:14:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sort_l_descending(int *stack, int size, char c);
void	sort_l_ascending(int *stack, int size, char c);
void	sort_l_inverse(int *stack, int size, char c);
void	sort_case(t_stack *stack, t_size size);

void	sort_case(t_stack *stack, t_size size)
{
	if ((size.b > 1 && stack->b[0] < stack->b[1])
	&& (size.a > 1 && stack->a[0] > stack->a[1]))
		ss(stack, size);
	else if (size.b > 1 && stack->b[0] < stack->b[1])
		swap(stack->b, size.b, 'b', 1);
	else if (size.a > 1 && stack->a[0] > stack->a[1])
		swap(stack->a, size.a, 'a', 1);
	if (size.a <= 3)
		sort_s_ascending(stack->a, size.a, 'a');
	if (size.b <= 3)
		sort_s_descending(stack->b, size.b, 'b');
	else
		return ;
}

// [1, 2, 3] or [3, 2, 1] -> s/r/s/rr/s
void	sort_l_inverse(int *stack, int size, char c)
{
	swap(stack, size, c, 1);
	rotate(stack, size, c, 1);
	swap(stack, size, c, 1);
	reverse_rotate(stack, size, c, 1);
	swap(stack, size, c, 1);
}

// Sort in ascending order the following cases:
// [2, 1, 3] -> s
// [1, 3, 2] -> r/s/rr
// [3, 1, 2] -> s/r/s/rr
// [2, 3, 1] -> r/s/rr/s
// [3, 2, 1] -> s/r/s/rr/s
void	sort_l_ascending(int *stack, int size, char c)
{
	if (stack[0] > stack[1] && stack[0] < stack[2] && stack[1] < stack[2])
		swap(stack, size, c, 1);
	else if (stack[0] < stack[1] && stack[0] < stack[2] && stack[1] > stack[2])
	{
		rotate(stack, size, c, 1);
		swap(stack, size, c, 1);
		reverse_rotate(stack, size, c, 1);
	}
	else if (stack[0] > stack[1] && stack[0] > stack[2] && stack[1] < stack[2])
	{
		swap(stack, size, c, 1);
		rotate(stack, size, c, 1);
		swap(stack, size, c, 1);
		reverse_rotate(stack, size, c, 1);
	}
	else if (stack[0] < stack[1] && stack[0] > stack[2] && stack[1] > stack[2])
	{
		rotate(stack, size, c, 1);
		swap(stack, size, c, 1);
		reverse_rotate(stack, size, c, 1);
		swap(stack, size, c, 1);
	}
	else if (stack[0] > stack[1] && stack[0] > stack[2] && stack[1] > stack[2])
		sort_l_inverse(stack, size, c);
}

// Sort in descending order the following cases:
// [2, 3, 1] -> s
// [3, 1, 2] -> r/s/rr
// [1, 3, 2] -> s/r/s/rr
// [2, 1, 3] -> r/s/rr/s
// [1, 2, 3] -> s/r/s/rr/s
void	sort_l_descending(int *stack, int size, char c)
{
	if (stack[0] < stack[1] && stack[0] > stack[2] && stack[1] > stack[2])
		swap(stack, size, c, 1);
	else if (stack[0] > stack[1] && stack[0] > stack[2] && stack[1] < stack[2])
	{
		rotate(stack, size, c, 1);
		swap(stack, size, c, 1);
		reverse_rotate(stack, size, c, 1);
	}
	else if (stack[0] < stack[1] && stack[0] < stack[2] && stack[1] > stack[2])
	{
		swap(stack, size, c, 1);
		rotate(stack, size, c, 1);
		swap(stack, size, c, 1);
		reverse_rotate(stack, size, c, 1);
	}
	else if (stack[0] > stack[1] && stack[0] < stack[2] && stack[1] < stack[2])
	{
		rotate(stack, size, c, 1);
		swap(stack, size, c, 1);
		reverse_rotate(stack, size, c, 1);
		swap(stack, size, c, 1);
	}
	else if (stack[0] < stack[1] && stack[0] < stack[2] && stack[1] < stack[2])
		sort_l_inverse(stack, size, c);
}
