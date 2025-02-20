/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simultaneous_instructions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:24:59 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/15 23:45:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rrr(t_stack *stack, t_size size);
void	rr(t_stack *stack, t_size size);
void	ss(t_stack *stack, t_size size);

void	ss(t_stack *stack, t_size size)
{
	swap(stack->a, size.a, 'a', 0);
	swap(stack->b, size.b, 'b', 0);
	ft_printf("ss\n");
}

void	rr(t_stack *stack, t_size size)
{
	rotate(stack->a, size.a, 'a', 0);
	rotate(stack->b, size.b, 'b', 0);
	ft_printf("rr\n");
}

void	rrr(t_stack *stack, t_size size)
{
	reverse_rotate(stack->a, size.a, 'a', 0);
	reverse_rotate(stack->b, size.b, 'b', 0);
	ft_printf("rrr\n");
}
