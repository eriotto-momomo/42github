#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

int	ft_safe_atoi(const char *str, int *error);
int	check_disorder(int *stack, int size);
int	is_sorted(int *stack, int size);
int	locate_int(int *stack, int n);
int calculate_rot_dir(int *stack, int size, int pivot);

// Calculate which direction is the shortest way to get to the next int
// greater than pivot.
int calculate_rot_dir(int *stack, int size, int pivot)
{
	int	forward;
	int	backward;

	forward = 0;
	backward = 0;
	while (forward < size && stack[forward] > pivot)
		forward++;
	backward = size - 1;
	while (backward >= 0 && stack[backward] > pivot)
		backward--;
	backward = size - backward;
	if (forward <= backward)
		return 1;
	else
		return -1;
}

int	locate_int(int *stack, int n)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == n)
			return (i);
		else
			i++;
	}
	return (0);
}

// Used in 'b_stack' to determine if it's sorted from highest
// to smallest by checking the number of inversions.
int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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

int	ft_safe_atoi(const char *str, int *error)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (((str[i]) >= 9 && (str[i]) <= 13) || (str[i]) == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + (str[i++] - '0');
		if ((num * sign) < -2147483648 || (num * sign) > 2147483647)
			*error = -1;
	}
	num *= sign;
	return (num);
}
