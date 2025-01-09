#include "push_swap.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!

int *push_swap(int argc, char *argv[]);
int	format_check(char **array, int i);
int array_conversion(int size, int start, char **str_array, int *int_array);
int	arg_is_valid(int size, char **str_array);
void *free_int_or_str_array(void *array, int type, int size);

// Type 1 = int_array
// Type 2 = str_array
void *free_int_or_str_array(void *array, int type, int size)
{
	int		i;
	int 	*int_array;
	char 	**str_array;

	i = 0;
	if (type == 1)
	{
		int_array = (int *)array;
		while (int_array[i++] < size)
			int_array[i] = 0;
		free(int_array);
	}
	else if (type == 2)
	{
		str_array = (char **)array;
		while (i < size)
		{
			if (str_array[i] != NULL)
				free(str_array);
			i++;
		}
		free(str_array);
	}
	return (0);
}

// Check if arguments are valid and will display "Error" if:
// - argument is NULL
// - arguments are not at least the prog. name + 1 valid string
// - str_array arguments are not numbers
int	arg_is_valid(int size, char **str_array)
{
	int	i;
	int error_check;

	i = 1;
	error_check = 0;
	if (str_array == NULL || str_array[0] == NULL || size < 2 ||
	(size == 2 && format_check(str_array, 1) < 2))
		error_check = -1;
	while (error_check != -1 && str_array[i] && i < size)
	{
		error_check = format_check(str_array, i);
		if (size > 2 && error_check > 1)
		{
			error_check = -1;
			break;
		}
		i++;
	}
	if (error_check == -1)
	{
		//str_array = free_int_or_str_array(str_array, 2, size);
		printf("Error\n");
		//exit(1);
	}
	return (1);
}

// Converts str_array to int_array and check if int_array:
// - outpasses limits
// - contains duplicates
// - is NULL
int array_conversion(int size, int start, char **str_array, int *int_array)
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
				//int_array = free_int_or_str_array(int_array, 1, size);
				printf("Error\n");
				//exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Check if arguments are nothing else except numbers
// Also used to count numbers in strings
int	format_check(char **array, int i)
{
	int	j;
	int count;

	j = 0;
	count = 0;
	while (array[i][j] != '\0')
	{
		if (!(array[i][j] >= '0' && array[i][j] <= '9' ||
		array[i][j] == '-' || array[i][j] == '+' || array[i][j] == ' '))
			return (-1);
		if ((array[i][j] == '-' || array[i][j] == '+') &&
		!(array[i][j + 1] >= '0' && array[i][j + 1] <= '9'))
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
	return (count);
}

int	*push_swap(int argc, char *argv[])
{
	char	**temp_stack;
	int		*a_stack;
	int		stack_size;

	temp_stack = NULL;
	if ((argc == 2) && format_check(argv, 1) >= 2)
	{
		temp_stack = ft_split(argv[1], ' ');
		stack_size = format_check(argv, 1);
		a_stack = malloc(sizeof(int) * stack_size);
		array_conversion(stack_size, 0, temp_stack, a_stack);
		if (temp_stack != NULL)
			free(temp_stack);
		return (a_stack);
	}
	else if (temp_stack == NULL && arg_is_valid(argc, argv) == 1)
	{
		a_stack = malloc(sizeof(int) * (argc - 1));
		array_conversion((argc - 1), 1, argv, a_stack);
		return (a_stack);
	}
	return (0);
}
