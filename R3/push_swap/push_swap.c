#include <stdlib.h>

int	argv_is_valid(int argc, char **array, int a_stack[argc - 1])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argc < 2 || check_arguments(array, 1) < 2 || check_arguments(array, i) == -1)
			return (-1);
		i++;
	}
	if (str_arr_to_int_arr(argc, array, int_array) == -1)
			return (-1);
	else
		return (1);
}

int check_duplicates(int argc, int int_array[argc - 1])
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

int	ft_safe_atoi(const char *str, int *error)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i]) == 9 || (str[i]) == 10 || (str[i]) == 11 ||
	(str[i]) == 12 || (str[i]) == 13 || (str[i]) == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i]) && (str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if ((num * sign) < -2147483648 || (num * sign) > 2147483647)
			*error = -1;
	num *= sign;
	return (num);
}

int str_arr_to_int_arr(int argc, char *str_array[argc], int int_array[argc - 1])
{
	int		i;
	int		j;
	int		error;

	i = 1;
	j = 0;
	error = 0;
	while (j < argc)
	{
		int_array[j] = 0;
		j++;
	}
	j = 0;
	while (i < argc)
	{
		int_array[j] = ft_safe_atoi(str_array[i], &error);
		if (error == -1)
			return (-1);
		i++;
		j++;
	}
	if (check_duplicates(argc, int_array) == -1)
		return (-1);
	return (1);
}

// check if argv[j] contains '-' and '+' signs and
// numbers also count and return the number of spaces
// if argv[1] is a string
int	check_arguments(char *array[], int	i)
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
	int		a_stack[argc - 1];
	int		i;

	if (argc == 2 && check_arguments(argv, 1) >= 2)
		temp_stack = ft_split(argv[1], ' ');
	if (argv_is_valid(argc, argv, a_stack) == -1 || argv_is_valid(argc, temp_stack, a_stack) == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (temp_stack != NULL)
	{
		str_arr_to_int_arr(argc, temp_stack, a_stack);
		return (a_stack);
	}
	else
	{
		str_arr_to_int_arr(argc, argv, a_stack);
		return (a_stack);
	}
	return (0);
}
