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
void	arg_is_valid(int size, char **str_array, int *stack_size, int **a_stack);
void	error_and_exit(void);

void error_and_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

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

void	arg_is_valid(int argc, char **argv, int *stack_size, int **a_stack)
{
	int	i;
	int	error_check;

	i = 1;
	error_check = 0;
	if (argv == NULL || argv[0] == NULL || argc < 2 ||
	(argc == 2 && validate_and_count(argc, argv, 1, 0) < 2))
		error_check = -1;
	while (error_check != -1 && argv[i] && i < argc)
	{
		error_check = validate_and_count(argc, argv, i, 0);
		i++;
	}
	if (error_check == -1)
		error_and_exit();
	else
	{
		*stack_size = validate_and_count(argc, argv, 1, 0);
		*a_stack = malloc(sizeof(int) * (*stack_size));
		if (!*a_stack)
			error_and_exit();
	}
}

int	*check_and_convert(int argc, char *argv[], int *stack_size)
{
	char	**tmp_stack;
	int		*a_stack;
	int		i;
	int		count;
	int		tmp_count;

	a_stack = NULL;
	arg_is_valid(argc, argv, stack_size, &a_stack);
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
