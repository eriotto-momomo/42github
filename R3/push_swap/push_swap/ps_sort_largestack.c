/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_largestack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:57:50 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/17 23:03:18 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sort_largestack(t_stack *stack, t_size *size);
void	push_chunks(t_stack *stack, t_size *size, t_chunk *c);
void	optimize_rotation(t_stack *stack, t_size *size, int target, char s_nme);
int		get_closest_chunk_part(int *stack, int size, int chunk);
int		get_next_chunk_part(int *stack, int size, int chunk);

int	get_next_chunk_part(int *stack, int size, int chunk)
{
	int		i;

	i = 1;
	while (i < size)
	{
		if (stack[i] <= chunk)
			break ;
		i++;
	}
	return (stack[i]);
}

int	get_closest_chunk_part(int *stack, int size, int chunk)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (stack[i] <= chunk)
			break ;
		i++;
	}
	j = size - 1;
	while (j >= 0)
	{
		if (stack[j] <= chunk)
			break ;
		j--;
	}
	if (i < ((size - 1) - j))
		return (stack[i]);
	else if (i > ((size - 1) - j))
		return (stack[j]);
	return (stack[i]);
}

void	optimize_rotation(t_stack *stack, t_size *size, int target, char s_nme)
{
	if (s_nme == 'a')
	{
		if (locate(stack->a, size->a, target) <= ((size->a + 1) / 2))
			rotate(stack->a, size->a, s_nme, 1);
		else if (locate(stack->a, size->a, target) > ((size->a + 1) / 2))
			reverse_rotate(stack->a, size->a, s_nme, 1);
	}
	else if (s_nme == 'b')
	{
		if (locate(stack->b, size->b, target) <= ((size->b + 1) / 2))
			rotate(stack->b, size->b, s_nme, 1);
		else if (locate(stack->b, size->b, target) > ((size->b + 1) / 2))
			reverse_rotate(stack->b, size->b, s_nme, 1);
	}
}

void	push_chunks(t_stack *stack, t_size *size, t_chunk *c)
{
	init_binp_and_sinp(stack, size, c);
	while (left_to_sort(stack->a, size->a, c->chunk[c->i], 's'))
	{
		if (stack->a[0] <= c->chunk[c->i] && (stack->a[0] < c->sinp
				|| stack->a[0] > c->binp))
			update_binp_and_sinp(stack, size, c);
		else if (stack->a[0] > c->sinp && stack->a[0] < c->binp)
			place_in_between(stack, size);
		else
			go_to_next_chunk_part(stack, size, c);
	}
	if (!left_to_sort(stack->a, size->a, c->chunk[c->i], 's'))
	{
		while (stack->b[0] != c->binp)
			go_to_binp(stack, size, c);
	}
}

void	sort_largestack(t_stack *stack, t_size *size)
{
	int		n_chunk;
	t_chunk	c;

	n_chunk = 0;
	if (size->a < 40)
		n_chunk = 1;
	else if (size->a <= 40)
		n_chunk = 2;
	else if (size->a <= 150)
		n_chunk = 6;
	else if (size->a > 150)
		n_chunk = 14;
	c.i = 0;
	get_chunks(stack, size->a, &c, n_chunk);
	c.i = 0;
	while (c.i < n_chunk)
	{
		push_chunks(stack, size, &c);
		c.i++;
	}
	while (size->b > 0)
		push(stack->b, stack->a, size, 'a');
	free(c.chunk);
}
