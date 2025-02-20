/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_single_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:43:08 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/16 20:15:28 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	reverse_rotate(int *stack, int size, char stack_name, int mode);
void	rotate(int *stack, int size, char stack_name, int mode);
void	push(int *src_stack, int *dst_stack, t_size *size, char stack_name);
void	swap(int *stack, int size, char stack_name, int mode);

void	swap(int *stack, int size, char stack_name, int mode)
{
	int	tmp_stack;

	if (stack == NULL || size < 2)
		return ;
	tmp_stack = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp_stack;
	if (mode == 1)
		ft_printf("s%c\n", stack_name);
}

// Takes first element in src_stack and place it on
// top of dst_stack.
// Every other elements in dst_stack go down.
// "go down" means(horizontally speaking): that
// elements are going from left to right in the string.
// 'DOWN' = '->' = '--'
// Every other elements in src_stack go up.
// "go up" means (horizontally speaking): that
// elements are going from right to left in the string.
// 'UP' = '<-' = '++'
// pa = push b to a / pb = push a to b
void	push(int *src_stack, int *dst_stack, t_size *size, char stack_name)
{
	int	i;
	int	*src_size;
	int	*dst_size;
	int	*logical_switch[2];

	logical_switch[0] = &(size->b);
	logical_switch[1] = &(size->a);
	src_size = logical_switch[stack_name != 'a'];
	dst_size = logical_switch[stack_name == 'a'];
	i = (*dst_size)++;
	while (i > 0)
	{
		dst_stack[i] = dst_stack[i - 1];
		i--;
	}
	dst_stack[0] = src_stack[0];
	i = 0;
	while (i < *src_size - 1)
	{
		src_stack[i] = src_stack[i + 1];
		i++;
	}
	src_stack[*src_size - 1] = 0;
	(*src_size)--;
	ft_printf("p%c\n", stack_name);
}

// Every elements go up in the stack, the first
// element becomes the last. "go up" means
// (horizontally speaking): that elements
// are going from right to left in the string.
// 'UP' = '<-' = '++'
void	rotate(int *stack, int size, char stack_name, int mode)
{
	int	tmp_stack;
	int	i;

	if (stack == NULL || size < 2)
		return ;
	tmp_stack = stack[0];
	i = 0;
	while (i < (size - 1))
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp_stack;
	if (mode == 1)
		ft_printf("r%c\n", stack_name);
}

// Every elements go down in the stack, the last
// element becomes the first. "go down" means
// (horizontally speaking): that elements
// are going from left to right in the string.
// 'DOWN' = '->' = '--'
void	reverse_rotate(int *stack, int size, char stack_name, int mode)
{
	int	tmp_stack;
	int	i;

	if (stack == NULL || size < 2)
		return ;
	tmp_stack = stack[size - 1];
	i = (size - 1);
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp_stack;
	if (mode == 1)
		ft_printf("rr%c\n", stack_name);
}
