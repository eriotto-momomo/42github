/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:59:14 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/17 22:59:30 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int		array_conversion(int argc, char **argv, int *int_array);
int		conversion(int size, char **char_array, int *int_array);
void	*free_int_or_char_array(void *array, int size, int mode);
void	handle_arg(int argc, char *argv[]);
void	error_and_exit(void);

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	handle_arg(int argc, char *argv[])
{
	int	num;
	int	error_check;

	if (argv == NULL || argv[0] == NULL)
		error_and_exit();
	else if (argc == 1)
		exit(1);
	else if (argc == 2 && validate_and_count(argc, argv, 1) == 1)
	{
		num = ft_atoi_safe(argv[1], &error_check);
		if (error_check == -1)
			error_and_exit();
		else if (num)
			exit(1);
	}
	else
		return ;
}

void	*free_int_or_char_array(void *array, int size, int mode)

{
	int		i;
	int		*int_array;
	char	**char_array;

	i = 0;
	if (mode == 1)
	{
		int_array = (int *)array;
		free(int_array);
	}
	else if (mode == 2)
	{
		char_array = (char **)array;
		while (i < size)
		{
			if (char_array[i] != NULL)
			{
				free(char_array[i]);
				char_array[i] = NULL;
			}
			i++;
		}
		free(char_array);
	}
	return (NULL);
}

int	conversion(int size, char **char_array, int *int_array)
{
	int	i;
	int	j;
	int	error_check;

	error_check = 1;
	i = 0;
	j = 0;
	while (i < size)
	{
		int_array[i] = ft_atoi_safe(char_array[j], &error_check);
		i++;
		j++;
	}
	if (error_check == -1)
		return (-1);
	return (1);
}

int	array_conversion(int argc, char **argv, int *int_array)
{
	char	**char_array;
	int		tmp_size;
	int		count;
	int		i;

	tmp_size = 0;
	i = 1;
	while (i < argc)
	{
		char_array = ft_split(argv[i], ' ');
		if (!char_array)
			return (-1);
		count = 0;
		while (char_array[count])
			count++;
		if (conversion(count, char_array, &int_array[tmp_size]) == -1)
			return (-1);
		tmp_size += count;
		free_int_or_char_array(char_array, count, 2);
		i++;
	}
	char_array = NULL;
	return (1);
}
