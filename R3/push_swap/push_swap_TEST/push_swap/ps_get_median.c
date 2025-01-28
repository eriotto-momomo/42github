
#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	get_exact_median(int size, int *stack);
int	get_average_median(int size, int *stack);
void	get_min_max(int size, int *stack, int *min, int *max);
int	calculate_median(int size, int *stack, int *min, int *max);
void	count_elements(int *stack, int *med, int *lower_count, int *equal_count);

void	count_elements(int *stack, int *med, int *lower_count, int *equal_count)
{
	int	i;
	int	size;

	i = 0;
	while (stack[i])
	{
		size = i;
		i++;
	}
	i = 0;
	while (i < size) // Compter les éléments
		{
			if (stack[i] < *med)
				(*lower_count)++;
			else if (stack[i] == *med)
				(*equal_count)++;
			i++;
		}
}

int	calculate_median(int size, int *stack, int *min, int *max)
{
	int	med;
	int	lower_count;
	int	equal_count;

	while (*min < *max)
	{
		med = (*min + *max) / 2; // Recalculer la médiane à chaque itération
		lower_count = 0;
		equal_count = 0;
		count_elements(stack, &med, &lower_count, &equal_count);
		if (lower_count <= size / 2 && lower_count + equal_count > size / 2) // Vérifier si `med` est la médiane
			return med;
		if (lower_count > size / 2) // Rétrécir les bornes
			*max = med - 1;
		else
			*min = med + 1;
	}
	return *min; // Retourner la valeur médiane exacte
}

// Find minimal and maximal values in stack.
void	get_min_max(int size, int *stack, int *min, int *max)
{
	int	i;

	*min = INT_MAX;
	*max = INT_MIN;
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
}

// Takes minimal and maximal values in stack and return
// the approximative median value. Complexity O(1), great
// and sufficient for balanced or partially sorted stack.
int	get_average_median(int size, int *stack)
{
	int	min;
	int	max;
	int	average_median;

	get_min_max(size, stack, &min, &max);
	average_median = (min + max) / 2;
	return(average_median);
}


// Find the exact median value in stack.
int	get_exact_median(int size, int *stack)
{
	int	min;
	int	max;
	int	median;

	get_min_max(size, stack, &min, &max);
	median = calculate_median(size, stack, &min, &max);
	return (median);
}