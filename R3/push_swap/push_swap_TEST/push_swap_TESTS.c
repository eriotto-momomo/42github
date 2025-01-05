#include "push_swap.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!

char *push_swap(int argc, char *argv[]);
int	check_arguments(char *array[], int	i);
int str_arr_to_int_arr(int argc, char *str_array[argc], int int_array[argc - 1]);
int check_duplicates(int argc, int int_array[argc - 1]);
int	argv_is_valid(int argc, char **array, int a_stack[argc - 1]);

int	argv_is_valid(int argc, char **array, int *a_stack)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (-1);
	else if (argc == 2 && check_arguments(array, 1) < 2)
		return (-1);
	else if (str_arr_to_int_arr(argc, array, a_stack) == -1)
		return (-1);
	else
		while (i < argc && array[i] != NULL)
		{
			if (check_arguments(array, i) == -1)
				return (-1);
			i++;
		}
		return (1);
}

int check_duplicates(int argc, int *int_array)
{
	int	i;
	int j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (int_array[i] == int_array[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int str_arr_to_int_arr(int size, char **str_array, int *int_array)
{
	int		i;
	int		error;

	i = 0;
	error = 0;
	while (i < size)
	{
		int_array[i] = ft_safe_atoi(str_array[i], &error);
		i++;
	}
	if (check_duplicates(size, int_array) == -1)
		return (-1);
	if (error == -1)
			return (-1);
	return (1);
}

int	check_arguments(char **array, int i)
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
		else if (array[i][j] >= '0' && array[i][j] <= '9')
		{
			count++;
			while (array[i][j] >= '0' && array[i][j] <= '9')
				j++;
		}
		else
			j++;
	}
	if (count > 0)
		return (count);
	else
		return (0);
}

// 0. argv ne doit traiter que des entiers!
// 1. argc doit contenir au minimum deux arguments:
// le nom du programme et une chaîne d'entiers,
// chaîne qui doit contenir au minimum 2 entiers.
// 2. si argc ne contient que deux arguments et que
// argv[1] est une chaîne d'entier ne contenant pas
// de caractere alphabetique > ft_split
char	*push_swap(int argc, char *argv[])
{
	char	**temp_stack;
	int		*a_stack;
	int		stack_size;
	int		i;

	temp_stack = NULL;
	i = 0;
	if (argc == 2 && argv_is_valid(argc, argv, a_stack) != -1)
	{
		temp_stack = ft_split(argv[1], ' ');
		stack_size = check_arguments(argv, 1);
		if (temp_stack == NULL || temp_stack[0] == NULL)
		{
			printf("Error\n");
			exit(1);
		}
	}
	if (temp_stack != NULL)
	{
		a_stack = malloc(sizeof(int) * stack_size);
		if (a_stack == NULL)
			return (NULL);
		while (i < stack_size)
		{
			if (str_arr_to_int_arr(stack_size, temp_stack, a_stack) != -1)
				printf("array[%i] = %i\n", i, a_stack[i]);
			else {
				printf("Error\n");
				exit (1);
			}
			i++;
		}
	}
	else if (temp_stack == NULL && argv_is_valid(argc, argv, a_stack) != -1)
	{
		while (i < argc - 1)
		{
			str_arr_to_int_arr(argc, argv, a_stack);
			printf("array[%i] = %i\n", i, a_stack[i]);
			i++;
		}
	}
	else
	{
		printf("Error\n");
		exit(1);
	}
	if (argc == 2)
		free(temp_stack);
	free(a_stack);
	return (0);
}
