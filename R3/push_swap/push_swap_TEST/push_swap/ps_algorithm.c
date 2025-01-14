#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

int	newgap(int gap)
{

    gap = (gap * 10) / 13;
    if (gap == 9 || gap == 10)
        gap = 11;
    if (gap < 1)
        gap = 1;
    return gap;
}

void combsort(int *a, int *size)
{
    int gap = *size;
    int temp, i;

    for (;;)
    {
        gap = newgap(gap);
        int swapped = 0;

        for (i = 0; i < *size - gap; i++)
        {
            int j = i + gap;

            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                swapped  =  1;
            }
        }
        if (gap  ==  1 && !swapped)
            break;
    }
}

void	*push_swap(int *a_stack, int *stack_size)
{
	int	*b_stack;
	int	i;

	b_stack = malloc(sizeof(int *) * *stack_size);
	if (b_stack == NULL)
		return (0);
	combsort(a_stack, stack_size);
	//reinitialise b_stack to zero & free
	i = 0;
	while (i < *stack_size)
	{
		printf("SORTED a_stack[%i] is: %d\n", i, a_stack[i]);
		i++;
	}
	printf("------------------------------\n");
	i = 0;
	while (i < *stack_size)
	{
		printf("SORTED b_stack[%i] is: %d\n", i, b_stack[i]);
		i++;
	}
	free(b_stack);
	return(0);
}
