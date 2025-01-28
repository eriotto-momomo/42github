#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sort_case_s(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_small_stack(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	adjust_sort_s(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_six_int(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_push_s(int *a_stack, int *b_stack, int *a_size, int *b_size);
//void	sort_s_simultaneously(int *a_stack, int *b_stack, int *a_size, int *b_size);

// Sort simultaneously A and B: A sorted in ascending order and
// B sorted in descending order.
/*void	sort_s_simultaneously(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	printf("sort_s_simultaneously\n");
	else if ((a_stack[0] > a_stack[1] && a_stack[1] > a_stack[2]) &&
	(b_stack[0] < b_stack[1] && b_stack[1] < b_stack[2]))
	{														// [3, 2, 1] && [1, 2, 3]
		ss(a_stack, b_stack);								// swap
		rrr(a_stack, b_stack, *a_size, *b_size);			// reverse_rotate
	}
	else if ((a_stack[0] > a_stack[2] && a_stack[2] > a_stack[1]) &&
	(b_stack[0] < b_stack[2] && b_stack[2] < b_stack[1]))	// [3, 1, 2] && [1, 3, 2]
		rr(a_stack, b_stack, *a_size, *b_size);								// rotate
	else if ((a_stack[1] > a_stack[0] && a_stack[0] > a_stack[2]) &&
	(b_stack[1] < b_stack[0] && b_stack[0] < b_stack[2]))	// [2, 3, 1] && [2, 1, 3]
		rrr(a_stack, b_stack, *a_size, *b_size);								// reverse_rotate
	else if ((a_stack[0] > a_stack[1] && a_stack[2] > a_stack[1] &&
	a_stack[2] > a_stack[0]) && (b_stack[0] < b_stack[1] &&
	b_stack[2] < b_stack[1] && b_stack[2] < b_stack[0]))	// [2, 1, 3] && [2, 3, 1]
		ss(a_stack, b_stack);								// swap
	else if ((a_stack[0] < a_stack[2] && a_stack[2] < a_stack[1]) &&
	(b_stack[0] > b_stack[2] && b_stack[2] > b_stack[1]))
	{														// [1, 3, 2] && [3, 1, 2]
		rrr(a_stack, b_stack, *a_size, *b_size);								// reverse_rotate
		ss(a_stack, b_stack);								// swap
	}
}*/

void	sort_push_s(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	sort_ascending(a_stack, a_size);
	sort_descending(b_stack, b_size);
	while (*b_size > 0)
	{
		push(b_stack, a_stack, b_size, a_size);
		ft_printf("pa\n");
	}
}

void	sort_six_int(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	i;
	int	a_pivot;

	a_pivot = get_average_median(*a_size, a_stack);
	i = 0;
	while (i < *a_size)
	{//push to B (pb) everything that's bigger than pivot
		if (a_stack[0] <= a_pivot)
		{
			push(a_stack, b_stack, a_size, b_size);
			ft_printf("pb\n");
		}
		else if (a_stack[0] > a_pivot)
		{
			call_instruction(2, a_stack, *a_size, 'a');
			i++;
		}
	}
	sort_push_s(a_stack, b_stack, a_size, b_size);
}

void	adjust_sort_s(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	second_min;
	int max;

	push(a_stack, b_stack, a_size, b_size); // push first_min in B
	ft_printf("pb\n");
	get_min_max(*a_size, a_stack, &second_min, &max);
	if (locate_int(a_stack, second_min) < (*a_size / 2))
	{
		while (a_stack[0] != second_min)
			call_instruction(2, a_stack, *a_size, 'a');	// rotate
	}
	else if (locate_int(a_stack, second_min) >= (*a_size / 2))
	{
		while (a_stack[0] != second_min)
			call_instruction(3, a_stack, *a_size, 'a');	// reverse_rotate
	}
	push(a_stack, b_stack, a_size, b_size);
	ft_printf("pb\n");
	sort_ascending(a_stack, a_size);
	while (*b_size > 0)
	{
		push(b_stack, a_stack, b_size, a_size);
		ft_printf("pa\n");
	}
}

void	sort_small_stack(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	first_min;
	int max;

	get_min_max(*a_size, a_stack, &first_min, &max);
	if (locate_int(a_stack, first_min) < (*a_size / 2))
	{
		while (a_stack[0] != first_min)
			call_instruction(2, a_stack, *a_size, 'a');	// rotate
	}
	else if (locate_int(a_stack, first_min) >= (*a_size / 2))
	{
		while (a_stack[0] != first_min)
			call_instruction(3, a_stack, *a_size, 'a');	// reverse_rotate
	}
	if (!is_sorted(a_stack, *a_size))
		adjust_sort_s(a_stack, b_stack, a_size, b_size);
}

void	sort_case_s(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	printf("sort_small_stack\n");
	if (*a_size <= 3)
	{
		printf("a_size = %d\n", *a_size);
		sort_ascending(a_stack, a_size);
	}
	else if (*a_size == 4 || *a_size == 5)
	{
		printf("a_size = %d\n", *a_size);
		sort_small_stack(a_stack, b_stack, a_size, b_size);
	}
	else if (*a_size == 6)
	{
		printf("a_size = %d\n", *a_size);
		sort_six_int(a_stack, b_stack, a_size, b_size);
	}
}

