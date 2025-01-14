#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

int	new_gap(int gap, )
{
	gap
}

void comb_sort(int *a_stack, int *b_stack, int *a_size, int *b_size)
{

}

/* void	sort(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
    // Vérifier que la pile a_stack contient 4 éléments
    if (*a_size != 4)
    {
        printf("Error: This function only handles stacks of size 4.\n");
        return;
    }

    // Étape 1 : Pousser les deux plus petits éléments dans b_stack
    for (int i = 0; i < 2; i++)
    {
        // Trouver le plus petit élément
        int min_index = 0;
        for (int j = 1; j < *a_size; j++)
        {
            if (a_stack[j] < a_stack[min_index])
                min_index = j;
        }

        // Placer le plus petit élément en haut de a_stack
        if (min_index <= *a_size / 2)
        {
            while (min_index > 0)
            {
                rotate(a_stack, *a_size);
                min_index--;
            }
        }
        else
        {
            while (min_index < *a_size)
            {
                reverse_rotate(a_stack, *a_size);
                min_index++;
            }
        }

        // Pousser l'élément le plus petit vers b_stack
        push(a_stack, b_stack, a_size, b_size);
    }

    // Étape 2 : Trier les deux éléments restants dans a_stack
    if (a_stack[0] > a_stack[1])
        swap(a_stack);

    // Étape 3 : Remettre les éléments de b_stack dans a_stack
    while (*b_size > 0)
    {
        push(b_stack, a_stack, b_size, a_size);
    }

    // Vérification finale
    printf("a_stack après tri : ");
    for (int i = 0; i < *a_size; i++)
    {
        printf("%d ", a_stack[i]);
    }
    printf("\n");
} */

void	*push_swap(int *a_stack, int *stack_size)
{
	int	*b_stack;
	int	a_size;
	int	b_size;
	int	i;

	b_stack = malloc(sizeof(int) * *stack_size);
	if (b_stack == NULL)
		return (0);
	a_size = *stack_size;
	b_size = *stack_size;
	printf("a_size[%d] / b_size[%d]\n", a_size, b_size);
	//sort(a_stack, b_stack, &a_size, &b_size);
	sort(a_stack, b_stack, &a_size, &b_size);
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
	return(0);
}
