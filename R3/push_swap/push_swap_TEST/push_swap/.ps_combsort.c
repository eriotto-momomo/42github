#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

void	comb_sort(int *stack, int size);
int	new_gap(int gap);
void	rotate_combsort(int *stack, int size, int n, int rev);

void	rotate_combsort(int *stack, int size, int n, int rev)
{
	int	rotations;

	rotations = 0;
	if (rev == 0)
	{
		while (rotations < n)
		{
			call_instruction(2, stack, size, 'a');
			rotations++;
		}
	}
	else if (rev == 1)
	{
		while (rotations < n)
		{
			call_instruction(3, stack, size, 'a');
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
				call_instruction(1, stack, size, 'a');
				swapped = 1;
			}
			rotate_combsort(stack, size, size - gap, 0);
			call_instruction(2, stack, size, 'a');
		}	// Faire avancer la pile pour la prochaine comparaison
		rotate_combsort(stack, size, size - 1, 1);
	}	// Revenir à la position initiale après une passe complète
	call_instruction(2, stack, size, 'a');
}
