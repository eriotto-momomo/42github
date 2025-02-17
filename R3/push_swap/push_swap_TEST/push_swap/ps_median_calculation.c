/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_median_calculation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:37:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/15 23:44:48 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	get_chunks(t_stack *stack, int size, t_chunk *c, int n_chunk);
int		ft_quickselect(int *stack, int left, int right, int k);
int		ft_quickselect_partition(int *stack, int left, int right);
void	ft_quickselect_swap(int *a, int *b);

void	ft_quickselect_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_quickselect_partition(int *stack, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = stack[right];
	i = left;
	j = left;
	while (j < right)
	{
		if (stack[j] < pivot)
		{
			ft_quickselect_swap(&stack[i], &stack[j]);
			i++;
		}
		j++;
	}
	ft_quickselect_swap(&stack[i], &stack[right]);
	return (i);
}

int	ft_quickselect(int *stack, int left, int right, int k)
{
	int	pivot_i;

	while (left <= right)
	{
		pivot_i = ft_quickselect_partition(stack, left, right);
		if (pivot_i == k)
			return (stack[pivot_i]);
		if (pivot_i > k)
			right = pivot_i - 1;
		else
			left = pivot_i + 1;
	}
	return (stack[k]);
}

void	get_chunks(t_stack *stack, int size, t_chunk *c, int n_chunk)
{
	int	i;
	int index;
	int	*tmp_stack;

	tmp_stack = malloc(sizeof(int) * size);
	c->chunk = malloc(sizeof(int) * n_chunk);
	if (tmp_stack == NULL || c->chunk == NULL)
	{
		free(c->chunk);
		free(stack->a);
		free(stack->b);
		error_and_exit();
	}
	ft_memcpy(tmp_stack, stack->a, size * sizeof(int));
	i = 0;
	while (i < n_chunk)
	{
		index = ((i + 1) * size + (n_chunk / 2)) / n_chunk;
		if (index >= size)
			index = size - 1;
		c->chunk[i] = ft_quickselect(tmp_stack, 0, size - 1, index);
		i++;
	}
	free(tmp_stack);
	tmp_stack = NULL;
}
