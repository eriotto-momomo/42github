#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS
/*int get_stack_size(int *stack)
{
	int	size

	size = 0;
	while (stack[size])
		size++;
	return size;
}*/

int is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] > stack[i + 1])
		{
			printf("stack[%i] is sorted!\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

// Find minimal and maximal values in array and return
// the approximative median value. Complexity O(1), great
// and sufficient for balanced or partially sorted array.
int	get_min_med_max(int size, int *array, int *min, int *max)
{
	int	i;
	//int	min;
	int	median;
	//int	max;

	i = 0;
	while (i < size)
	{
		if (array[i] > *max)
			*max = array[i];
		i++;
	}
	while (i > 0)
	{
		if (array[i] < *min)
			*min = array[i];
		i--;
	}
	median = (*min + *max) / 2;
	return (median);
}

int	get_closest_median(int size, int *array, int *min, int *max)
{
	int	i;
	int closest_to_median;
	int median_value;
	int closest_diff;
	int diff;

	i = 0;
	median_value = get_min_med_max(size, array, min, max);
	closest_diff = INT_MAX;
	while (i < size)
	{
		diff = array[i] - median_value;
		if (diff < 0)
			diff = -diff;
		if (diff < closest_diff)
		{
			closest_diff = diff;
			closest_to_median = array[i];
		}
		i++;
	}
    return closest_to_median;
}

void quicksort(int *a_stack, int *b_stack, int *b_size, int *a_size, int pivot)
{
	int	i;
	int min;
	int max;

	i = 0;
	pivot = get_min_med_max(*a_size, a_stack, &min, &max);
	while (a_size > 0)
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
		//if (b_size == 0 && is_sorted(a_stack, a_size) && a_size == size)
		//	break;
	}
}

void	*push_swap(int *a_stack, int *size)
{
	int	*b_stack;
	//int	min_value;
	//int	max_value;
	//int median;
	int a_size;
	int	b_size;
	//int	i;

	a_size = *size;
	b_size = 0;
	b_stack = malloc(sizeof(int *) * *size);
	if (b_stack == NULL)
		return (0);
	//median = get_min_med_max(*size, a_stack, &min_value, &max_value);
	//quicksort(*size, a_stack, b_stack, &min_value, &max_value, median);
	quicksort(a_stack, b_stack, &a_size, &b_size, 0);
	//reinitialise b_stack to zero & free
	/*i = 0;
	while (i < *size)
	{
		printf("SORTED a_stack[%i] is: %d\n", i, a_stack[i]);
		i++;
	}
	printf("------------------------------\n");
	i = 0;
	while (i < *size)
	{
		printf("SORTED b_stack[%i] is: %d\n", i, b_stack[i]);
		i++;
	}
	free(b_stack);*/
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
