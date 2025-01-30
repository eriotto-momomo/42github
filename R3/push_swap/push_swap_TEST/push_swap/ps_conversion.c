#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

int	array_conversion(int size, int start, char **str_array, int *int_array);
void	*free_int_or_str_array(void *array, int type, int size);

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
				error_and_exit();
			}
			j++;
		}
		i++;
	}
	return (1);
}
