#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

int	main(int argc, char *argv[])
{
	//int	i = 0;
	int	*a_stack;
	int	size;

	a_stack = check_and_convert(argc, argv, &size);
	if (a_stack == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	push_swap(a_stack, &size);
	//while (a_stack[i])
	//{
	//	ft_printf("SORTED a_stack[%i] is: %d\n", i, a_stack[i]);
	//	i++;
	//}
	return (0);
}