/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:59:55 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/15 23:31:46 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int		*check_and_convert(int argc, char *argv[], int *stack_size);
int		validate_and_count(int size, char **array, int i);
int		check_dupplicates(int *int_array, int size);
int		check_conditions(char **array, int *i, int *j);
void	arg_is_valid(int argc, char **argv, int *stack_size, int **stack);

int	check_conditions(char **array, int *i, int *j)
{
	if (!((array[*i][*j] >= '0' && array[*i][*j] <= '9') || array[*i][*j] == '-'
	|| array[*i][*j] == '+' || array[*i][*j] == ' ' || array[*i][*j] == '-'))
		return (-1);
	else if ((array[*i][*j] == '-' || array[*i][*j] == '+')
	&& !(array[*i][*j + 1] >= '0' && array[*i][*j + 1] <= '9'))
		return (-1);
	else if ((array[*i][*j] == '-' || array[*i][*j] == '+')
	&& (!(array[*i][*j + 1] >= '0' && array[*i][*j + 1] <= '9')
	|| (*j > 0 && array[*i][*j - 1] >= '0' && array[*i][*j - 1] <= '9')))
		return (-1);
	else
		return (1);
}

int	check_dupplicates(int *int_array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (int_array == NULL)
		return (-1);
	while (i < size)
	{
		while (j < size)
		{
			if (int_array[i] == int_array[j])
				return (-1);
			j++;
		}
		i++;
		if (j == size)
			j = i + 1;
	}
	return (1);
}

int	validate_and_count(int size, char **array, int i)
{
	int	count;
	int	j;

	count = 0;
	while (i < size)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (check_conditions(array, &i, &j) == -1)
				return (-1);
			if (array[i][j] >= '0' && array[i][j] <= '9')
			{
				count++;
				while (array[i][j] >= '0' && array[i][j] <= '9')
					j++;
			}
			else
				j++;
		}
		i++;
	}
	return (count);
}

void	arg_is_valid(int argc, char **argv, int *stack_size, int **stack)
{
	int	i;
	int	error_check;

	error_check = 1;
	i = 1;
	while (error_check == 1)
	{
		if (argv == NULL || argv[0] == NULL || argc < 2
			|| (argc == 2 && validate_and_count(argc, argv, 1) < 2))
			error_check = -1;
		while (error_check == 1 && argv[i] && i < argc)
		{
			error_check = validate_and_count(argc, argv, i);
			i++;
		}
		*stack_size = validate_and_count(argc, argv, 1);
		*stack = malloc(sizeof(int) * (*stack_size));
		if (!*stack)
			error_and_exit();
	}
	if (error_check == -1)
		error_and_exit();
}

int	*check_and_convert(int argc, char *argv[], int *stack_size)
{
	int	*stack;

	stack = NULL;
	arg_is_valid(argc, argv, stack_size, &stack);
	if (array_conversion(argc, argv, stack) == -1)
	{
		free(stack);
		error_and_exit();
	}
	if (check_dupplicates(stack, *stack_size) == -1)
	{
		free(stack);
		error_and_exit();
	}
	if (!to_sort(stack, *stack_size))
	{
		free(stack);
		exit(1);
	}
	return (stack);
}
