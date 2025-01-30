#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

void swap(int *a, int *b);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int stack_a[], int startIndex, int endIndex) {
    // Sélectionner le dernier élément comme pivot
    int pivot = stack_a[endIndex];
    int pivotIndex = startIndex;

    for (int i = startIndex; i < endIndex; i++) {
        if (stack_a[i] <= pivot) {
            swap(&stack_a[i], &stack_a[pivotIndex]);
            pivotIndex++;
        }
    }

    // Placer le pivot à sa position correcte
    swap(&stack_a[pivotIndex], &stack_a[endIndex]);

    return pivotIndex;
}

void quicksort(int stack_a[], int n)
{
    // Implémentation manuelle d'une pile pour stocker les indices
    int stack[2 * n]; // Chaque entrée de la pile stockera une paire d'indices
    int top = -1;

    // Indices initiaux de la première plage
    stack[++top] = 0;        // Ajouter l'indice de début
    stack[++top] = n - 1;    // Ajouter l'indice de fin

    while (top >= 0) {
        // Extraire les indices de début et de fin de la pile
        int endIdx = stack[top--];
        int startIdx = stack[top--];

        // Partitionner les éléments autour du pivot
        int pivotIdx = partition(stack_a, startIdx, endIdx);

        // Si des éléments à gauche du pivot existent, ajouter leurs indices dans la pile
        if (pivotIdx - 1 > startIdx) {
            stack[++top] = startIdx;
            stack[++top] = pivotIdx - 1;
        }

        // Si des éléments à droite du pivot existent, ajouter leurs indices dans la pile
        if (pivotIdx + 1 < endIdx) {
            stack[++top] = pivotIdx + 1;
            stack[++top] = endIdx;
        }
    }
}

void	*push_swap(int *a_stack, int *stack_size)
{
	int	*b_stack;
	int	i;

	b_stack = malloc(sizeof(int *) * *stack_size);
	if (b_stack == NULL)
		return (0);
	//combsort(a_stack, stack_size);
	quicksort(a_stack, *stack_size);
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

///////////////////////////////////////////
/*int	newgap(int gap)
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
}*/
///////////////////////////////////////////
