/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:55:04 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/16 22:17:38 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int		tmp_size;
	t_stack	stack;
	t_size	size;

	handle_arg(argc, argv);
	stack.a = check_and_convert(argc, argv, &tmp_size);
	if (stack.a == NULL)
		error_and_exit();
	size.a = tmp_size;
	size.b = 0;
	stack.b = malloc(sizeof(int) * tmp_size);
	if (stack.b == NULL)
	{
		free(stack.a);
		error_and_exit();
	}
	if (size.a <= 6)
		sort_smallstack(&stack, &size);
	else if (size.a > 6)
		sort_largestack(&stack, &size);
	free(stack.a);
	free(stack.b);
	return (0);
}
