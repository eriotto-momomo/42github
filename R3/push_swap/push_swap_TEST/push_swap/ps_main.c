#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

void	comb_sort(int *stack, int size);
void	rotate_combsort(int *stack, int size, int n, int rev);
int	new_gap(int gap);
int	main(int argc, char *argv[]);

void	rotate_combsort(int *stack, int size, int n, int rev)
{
	int	rotations;

	rotations = 0;
	if (rev == 0)
	{
		while (rotations < n)
		{
			rotate(stack, size);
			rotations++;
		}
	}
	else if (rev == 1)
	{
		while (rotations < n)
		{
			reverse_rotate(stack, size);
			rotations++;
		}
	}
}

int	new_gap(int gap)
{
	gap = (gap * 10) / 13;
	if (gap == 9 || gap == 10)
		gap = 11;
	if (gap < 1)
		gap = 1;
	return (gap);
}

void	comb_sort(int *stack, int size)
{
	int	gap;
	int	swapped;
	int	i;

	gap = size;
	swapped = 1;
	while (gap > 1 || swapped)
	{
		gap = new_gap(gap);
		swapped = 0;
		i = 0;
		while (i++ < size - gap)
		{	// Amener les deux éléments à comparer en tête
			rotate_combsort(stack, size, gap, 0);
			if (stack[0] > stack[1])
			{
				swap(stack);
				swapped = 1;
			}
			rotate_combsort(stack, size, size - gap, 0);
			rotate(stack, size);
		}	// Faire avancer la pile pour la prochaine comparaison
		rotate_combsort(stack, size, size - 1, 1);
	}	// Revenir à la position initiale après une passe complète
	rotate(stack, size);
}

// Used to determine if the stack is almost sorted
// by checking the number of inversions.
int	check_disorder(int *stack, int size)
{
	int	i;
	int	j;
	int	inversions;

	i = 0;
	j = 1;
	inversions = 0;
	while (i < size && j < size)
	{
		if (stack[i] > stack[j])
			inversions++;
		i++;
		j++;
	}
	return (inversions);
}

int	main(int argc, char *argv[])
{
	int	i = 0;
	int	*a_stack;
	int	size;
	int	disorder;

	a_stack = check_and_convert(argc, argv, &size);
	if (a_stack == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	else if (size == 2 && a_stack[0] > a_stack[1])
		swap(a_stack);
	disorder = check_disorder(a_stack, size);
	ft_printf("disorder indice is: %d\n", disorder);
	//if (size < 10 || ((size >= 10 && size <= 100) && disorder <= (size / 3)))
	if (disorder < 1)
	{
		printf("////// CCCCCCCOMB_SORT! //////\n");
		comb_sort(a_stack, size);
	}
	else
		push_swap(a_stack, &size);
	while (i < size)
	{
		printf("SORTED a_stack[%i] is: %d\n", i, a_stack[i]);
		i++;
	}
	printf("------------------------------\n");
	return (0);
}
