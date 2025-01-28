#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

int	main(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int	*a_stack;
	int	*b_stack;
	int	size;
	int	a_size;
	int	b_size;
	//int	disorder;

	a_stack = check_and_convert(argc, argv, &size);
	a_size = size;
	///////////////////////////////////////////////////////////////
	print_array(a_stack, a_size, 'a');
	///////////////////////////////////////////////////////////////
	//disorder = check_disorder(a_stack, a_size);
	b_stack = malloc(sizeof(int) * size);
	if (b_stack == NULL)
		return (0);
	b_size = 0;
	if (a_size <= 6)
		sort_case_s(a_stack, b_stack, &a_size, &b_size);
	else if (a_size > 6)
		sort_large_stack(a_stack, b_stack, &a_size, &b_size);
	if (is_sorted(a_stack, a_size))
	{
		print_array(a_stack, a_size, 'a');
		printf("YAY! IT'S SORTED!\n");
		free(b_stack);
		return (0);
	}
	else if (!is_sorted(a_stack, a_size))
	{
		print_array(a_stack, a_size, 'a');
		printf("ERROR! ARRAY IS NOT SORTED :((\n");
		free(b_stack);
		return (0);
	}
	return (0);
}
