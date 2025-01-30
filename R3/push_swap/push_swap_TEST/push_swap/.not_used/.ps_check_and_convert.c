#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS



int	*check_and_convert(int argc, char *argv[], int *stack_size);
int	validate_and_count(int size, char **array, int i, int j);
//int	format_check(char **array, int i);
int	array_conversion(int size, int start, char **str_array, int *int_array);
int	arg_is_valid(int size, char **str_array);
void	*free_int_or_str_array(void *array, int type, int size);

#include <stdio.h>

// Check if arguments are nothing else except numbers.
// Also used to count numbers in strings.
int	validate_and_count(int size, char **array, int i, int j)
{
	int	count;

	count = 0;
	while (i < size)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (!((array[i][j] >= '0' && array[i][j] <= '9')
			|| array[i][j] == '-' || array[i][j] == '+' || array[i][j] == ' ')
			|| ((array[i][j] == '-' || array[i][j] == '+')
			&& !(array[i][j + 1] >= '0' && array[i][j + 1] <= '9')))
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

// Type 1 = int_array
// Type 2 = str_array
void	*free_int_or_str_array(void *array, int type, int size)
{
	int		i;
	int		*int_array;
	char	**str_array;

	i = 0;
	if (type == 1)
	{
		int_array = (int *)array;
		free(int_array);
	}
	else if(type == 2)
	{
		str_array = (char **)array;
		while (i < size)
		{
			if (str_array[i] != NULL)
			{
				free(str_array[i]);
				str_array[i] = NULL;
			}
			i++;
		}
		free(str_array);
	}
	return (NULL);
}

// Check if arguments are valid and will display "Error" if:
// - argument is NULL
// - arguments are not at least the prog. name + 1 valid string
// - str_array arguments are not numbers
int	arg_is_valid(int size, char **str_array)
{
	int	i;
	int	error_check;

	i = 1;
	error_check = 0;
	if (str_array == NULL || str_array[0] == NULL || size < 2 ||
	(size == 2 && validate_and_count(size, str_array, 1, 0) < 2))
		error_check = -1;
	while (error_check != -1 && str_array[i] && i < size)
	{
		error_check = validate_and_count(size, str_array, i, 0);
		i++;
	}
	if (error_check == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (1);
}

// Converts str_array to int_array and check if int_array:
// outpasses limits, contains duplicates or is NULL
int	array_conversion(int size, int start, char **str_array, int *int_array)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	while (i < size)
		int_array[i++] = ft_safe_atoi(str_array[start++], &error);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (int_array[i] == int_array[j] || error == -1 || int_array == NULL)
			{
				int_array = free_int_or_str_array(int_array, 1, size);
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// stack_size initialisé à l'aide d'un pointeur dans le main
////////////////////////////////////////////////////////////
// 1. If argc is at leat 2 elements and the second one is a valid
// string, argv[1] is split and converted into an int array.
// 2. If argc is more than 2 elements, each elements are converted
// into an int array starting from argv[1].
int	*check_and_convert(int argc, char *argv[], int *stack_size)
{
	char	**tmp_stack;
	int		*a_stack;
	int		i;
	int		count;
	int		tmp_count;

	if (argc < 2 || arg_is_valid(argc, argv) != 1)
		return (NULL);
	*stack_size = validate_and_count(argc, argv, 1, 0);
	a_stack = malloc(sizeof(int) * (*stack_size));
	if (!a_stack)
		return (NULL);
	i = 1;
	tmp_count = 0;
	while (i < argc)
	{
		tmp_stack = ft_split(argv[i], ' ');
		if (!tmp_stack)
			return (NULL);
		count = 0;
		while (tmp_stack[count])
			count++; // Compter les éléments de `tmp_stack`
		if (!array_conversion(count, 0, tmp_stack, &a_stack[tmp_count]))
			return (NULL); // Vérifie si array_conversion a échoué
		tmp_count += count;
		i++;
	}
	free_int_or_str_array(tmp_stack, 2, count);
	return (a_stack);
}
