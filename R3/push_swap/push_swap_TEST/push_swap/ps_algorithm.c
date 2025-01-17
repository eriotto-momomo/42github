#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <limits.h>

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

int	is_sorted(int size, int *stack);
int	get_average_median(int size, int *stack, int *min, int *max);
int	get_closest_median(int size, int *stack, int *min, int *max);
void quicksort(int *a_stack, int *b_stack, int *b_size, int *a_size);
void	*push_swap(int *a_stack, int *size);

int	is_sorted(int size, int *stack)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// Find minimal and maximal values in stack and return
// the approximative median value. Complexity O(1), great
// and sufficient for balanced or partially sorted stack.
int	get_average_median(int size, int *stack, int *min, int *max)
{
	int	i;
	int	median;
	i = 0;
	while (i < size)
	{
		if (stack[i] > *max)
			*max = stack[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (stack[i] < *min)
			*min = stack[i];
		i++;
	}
	median = (*min + *max) / 2;
	return (median);
}

int	get_closest_median(int size, int *stack, int *min, int *max)
{
	int	i;
	int closest_to_median;
	int median_value;
	int closest_diff;
	int diff;

	i = 0;
	closest_to_median = 0;
	median_value = get_average_median(size, stack, min, max);
	closest_diff = INT_MAX;
	diff = 0;
	while (i < size)
	{
		diff = stack[i] - median_value;
		if (diff < 0)
			diff = -diff;
		if (diff < closest_diff)
		{
			closest_diff = diff;
			closest_to_median = stack[i];
		}
		i++;
	}
	return closest_to_median;
}

void quicksort(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	i;
	int pivot;
	int min;
	int max;

	min = INT_MAX;
	max = INT_MIN;
	i = 0;
	pivot = get_closest_median(*a_size, a_stack, &min, &max);
	printf("med = %d\n", pivot);
	printf("min = %d\n", min);
	printf("max = %d\n", max);
	return ;
	while ((!is_sorted(*a_size, a_stack)) && b_size != 0)
	{
		while (i < *a_size)
		{
			if (a_stack[0] >= pivot)
			{
				push(a_stack, b_stack, a_size, b_size); //pb
				printf("pb\n");
			}
			else
			{
				rotate(a_stack, *a_size); //ra
				printf("ra\n");
			}
			i++;
		}
		if (*b_size > 1 && b_stack[0] < b_stack[1])
		{
			swap(b_stack); //sb
			printf("pa\n");
		}
		while (*b_size > 0)
		{
			push(b_stack, a_stack, b_size, a_size); //pa
			printf("pa\n");
		}
	}
}

void	*push_swap(int *a_stack, int *size)
{
	int	*b_stack;
	int a_size;
	int	b_size;

	a_size = *size;
	b_size = 0;
	b_stack = malloc(sizeof(int *) * *size);
	if (b_stack == NULL)
		return (0);
	quicksort(a_stack, b_stack, &a_size, &b_size);
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
