/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:55:04 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/16 20:47:26 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

#include <stdio.h>

int	main(int argc, char *argv[]);
void	print_array(int *array, int size, char c);

void	print_array(int *array, int size, char c)
{
	int	i;

	i = 0;
	ft_printf("---------------------------\n");
	while (i < size)
	{
		printf("stack->%c[%d] | %d \n", c, i, array[i]);
		i++;
	}
	ft_printf("---------------------------\n");
}

int	main(int argc, char *argv[])
{
	int		tmp_size;
	t_stack	stack;
	t_size	size;

	if (argc == 1)
		exit(1);
	stack.a = check_and_convert(argc, argv, &tmp_size);
	if (stack.a == NULL)
		error_and_exit();
	size.a = tmp_size;
	size.b = 0;
	stack.b = malloc(sizeof(int) * tmp_size);
	print_array(stack.a, size.a, 'a');
	if (stack.b == NULL)
	{
		free(stack.a);
		error_and_exit();
	}
	if (size.a <= 6)
	{
		ft_printf("SORT SMALLSTACK\n");
		ft_printf("---------------------------\n");
		sort_smallstack(&stack, &size);
	}
	else if (size.a > 6)
	{
		ft_printf("SORT LARGESTACK\n");
		ft_printf("---------------------------\n");
		sort_largestack(&stack, &size);
	}
	print_array(stack.a, size.a, 'a');
	if (!to_sort(stack.a, size.a))
	{
		ft_printf("YAY! IT'S SORTED :))\n");
		ft_printf("---------------------------\n");
	}
	else if (to_sort(stack.a, size.a))
	{
		ft_printf("ERROR! ARRAY IS NOT SORTED :((\n");
		ft_printf("---------------------------\n");
	}
	free(stack.a);
	free(stack.b);
	return (0);
}
