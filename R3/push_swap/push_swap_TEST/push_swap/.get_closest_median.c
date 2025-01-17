#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <limits.h>

int	get_closest_median(int size, int *array);
int	get_min_med_max(int size, int *array);

int	get_min_med_max(int size, int *array)
{
	int	i;
	int	min;
	int	median;
	int	max;

	i = 0;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	while (i > 0)
	{
		if (array[i] < min)
			min = array[i];
		i--;
	}
	median = (min + max) / 2;
	return (median);
}

int	get_closest_median(int size, int *array)
{
	int	i;
	int closest_to_median;
	int median_value;
	int closest_diff;
	int diff;

	i = 0;
	median_value = get_min_med_max(size, array);
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
