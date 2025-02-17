/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_l_insertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:37:25 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/17 22:59:51 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	init_binp_and_sinp(t_stack *stack, t_size *size, t_chunk *c);
void	update_binp_and_sinp(t_stack *stack, t_size *size, t_chunk *c);
void	place_in_between(t_stack *stack, t_size *size);
void	go_to_next_chunk_part(t_stack *stack, t_size *size, t_chunk *c);
void	go_to_binp(t_stack *stack, t_size *size, t_chunk *c);

void	go_to_binp(t_stack *stack, t_size *size, t_chunk *c)
{
	int	target;

	target = get_closest_chunk_part(stack->a, size->a, (c->chunk[c->i] + 1));
	if (locate(stack->b, size->b, c->binp) <= ((size->b + 1) / 2)
	&& stack->a[0] != target && stack->b[0] != c->binp)
		rr(stack, *size);
	else if (locate(stack->b, size->b, c->binp) > ((size->b + 1) / 2)
	&& stack->a[0] != target && stack->b[0] != c->binp)
		rrr(stack, *size);
	else
		optimize_rotation(stack, size, c->binp, 'b');
}

void	go_to_next_chunk_part(t_stack *stack, t_size *size, t_chunk *c)
{
	int	target;
	int	perf_loc;

	target = get_next_chunk_part(stack->a, size->a, c->chunk[c->i]);
	perf_loc = perfect_location(stack->b, size->b, target);
	if (locate(stack->b, size->b, perf_loc) <= ((size->b + 1) / 2)
	&& stack->a[0] != target && stack->b[0] != perf_loc)
		rr(stack, *size);
	else
		rotate(stack->a, size->a, 'a', 1);
}

//ft_printf("[perf_loc] for stack->a[0][%d] is: %d\n", stack->a[0], perf_loc);
//// PAS OPTIMIZABLE ////
// Dès qu'un élément du chunk à trier est trouvé, stack->b est
// repositionné pour l'accueillir.
void	place_in_between(t_stack *stack, t_size *size)
{
	int	perf_loc;

	if (stack->a[0] > stack->b[0] && stack->a[0] < stack->b[size->b - 1])
		push(stack->a, stack->b, size, 'b');
	else
	{
		perf_loc = perfect_location(stack->b, size->b, stack->a[0]);
		while (stack->b[0] != perf_loc)
			optimize_rotation(stack, size, perf_loc, 'b');
		push(stack->a, stack->b, size, 'b');
	}
}

//ft_printf("[update_sinp_and_binp]\nBINP[%d] SINP[%d]\n", c->binp, c->sinp);
//// PAS OPTIMIZABLE ////
// Dès qu'un élément plus grand que binp ou plus petit que sinp est
// trouvé, stack->b est repositionné pour l'accueillir.
void	update_binp_and_sinp(t_stack *stack, t_size *size, t_chunk *c)
{
	if (stack->a[0] > c->binp)
	{
		while (stack->b[0] != c->binp)
			optimize_rotation(stack, size, c->binp, 'b');
		c->binp = stack->a[0];
	}
	else if (stack->a[0] < c->sinp)
	{
		if ((c->i - 1) > 0)
		{
			while (stack->b[0] != c->chunk[c->i - 1])
				optimize_rotation(stack, size, c->chunk[c->i - 1], 'b');
		}
		else
		{
			while (stack->b[0] != c->sinp)
				optimize_rotation(stack, size, c->sinp, 'b');
			rotate(stack->b, size->b, 'b', 1);
		}
		c->sinp = stack->a[0];
	}
	push(stack->a, stack->b, size, 'b');
}

//printf("[init_binp_and_sinp]\nBINP[%d] SINP[%d]\n", c->binp, c->sinp);
//printf("c->chunk[%d][%d]\nleft_to_sort = %d\n", c->i, c->chunk[c->i], left_to_sort(stack->a, size->a, c->chunk[c->i], 's'));
//// PAS OPTIMIZABLE ////
// Push dans stack->b les deux premiers éléments trouvées inférieurs à la
// chunk actuelle, binp est initialisé avec le plus grand et sinp le petit.
void	init_binp_and_sinp(t_stack *stack, t_size *size, t_chunk *c)
{
	int	cnt;
	int	target;

	cnt = 0;
	while (cnt != 2 && left_to_sort(stack->a, size->a, c->chunk[c->i], 's'))
	{
		if (stack->a[0] <= c->chunk[c->i])
		{
			push(stack->a, stack->b, size, 'b');
			cnt++;
		}
		else
		{
			target = get_closest_chunk_part(stack->a, size->a, c->chunk[c->i]);
			optimize_rotation(stack, size, target, 'a');
		}
		//else
		//	rotate(stack->a, size->a, 'a', 1);
	}
	if (stack->b[0] < stack->b[1] && stack->a[0] > stack->a[1]) // ATTENTION
		ss(stack, *size);										// ATTENTION
	else if (stack->b[0] < stack->b[1] && stack->a[0] < stack->a[1])
		swap(stack->b, size->b, 'b', 1);
	c->binp = stack->b[0];
	c->sinp = stack->b[1];
}
