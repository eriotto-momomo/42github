/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:15:09 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/16 20:12:30 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int		to_sort(int *stack, int size);
int		left_to_sort(int *stack, int size, int pivot, int mode);
int		perfect_location(int *stack, int size, int target);
int		locate(int *stack, int size, int target);

int	locate(int *stack, int size, int target)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == target)
			break ;
		i++;
	}
	return (i);
}

int	perfect_location(int *stack, int size, int target)
{
	int	i;

	i = 0;
	if (size == 2 && (stack[0] > target && stack[1] < target))
		return (stack[1]);
	while (i + 1 < size)
	{
		if (stack[i] > target && stack[i + 1] < target)
			break ;
		i++;
	}
	return (stack[i + 1]);
}

// mode = 's': smaller values to sort
// mode = 'l': larger values to sort
int	left_to_sort(int *stack, int size, int pivot, int mode)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	if (mode == 's')
	{
		while (i < size)
		{
			if (stack[i] <= pivot)
				cnt++;
			i++;
		}
	}
	else if (mode == 'l')
	{
		while (i < size)
		{
			if (stack[i] > pivot)
				cnt++;
			i++;
		}
	}
	return (cnt);
}

int	to_sort(int *stack, int size)
{
	int	i;

	i = 0;
	if (size >= 2 && stack[0] > stack[1])
		return (1);
	while (i + 1 < size)
	{
		if (stack[i] > stack[i + 1])
			break ;
		i++;
	}
	if (i == size - 1)
		return (0);
	else
		return (i);
}
