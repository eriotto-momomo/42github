#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

//void	sort(int *stack, int *size);
int	sort_and_pushback(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	get_smallest(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_large_stack(int *a_stack, int *b_stack, int *a_size, int *b_size);
// À delete!
void print_array(int *array, int size, char c);

int	sort_and_pushback(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	cnt;

	sort_case_l(a_stack, b_stack, a_size, b_size);
	//sort_descending(b_stack, b_size);
	cnt = 0;
	while (*b_size > 0)
	{
		push(b_stack, a_stack, b_size, a_size);// pa
		ft_printf("pa\n");
		cnt++;
	}
	return (cnt);
}

void	get_smallest(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int b_pivot;
	int	i;

	while (*b_size > 3 && !is_sorted(b_stack, *b_size))
	{
		b_pivot = get_exact_median(*b_size, b_stack);
		i = 0;
		while (b_stack[i]) //push to A (pa) everything that's smaller than pivot
		{
			while (b_stack[0] < b_pivot)
			{
				push(b_stack, a_stack, b_size, a_size);
				ft_printf("pa\n");
				if (a_stack[0] < a_stack[1])
					call_instruction(2, a_stack, *a_size, 'a'); //ra
			}
			call_instruction(2, b_stack, *b_size, 'b');
			i++;
		}
	}
}

void sort_large_stack(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	i;
	int	j;
	int	a_pivot;
	int	cnt;

	cnt = 0;
	while (!is_sorted(a_stack, *a_size))
	{
		a_pivot = get_average_median((*a_size - cnt), a_stack);
		i = 0;
		while (i < (*a_size - cnt))
		{//push to B (pb) everything that's bigger than pivot
			if (a_stack[0] >= a_pivot)
			{
				push(a_stack, b_stack, a_size, b_size);
				ft_printf("pb\n");
			}
			else if (a_stack[0] < a_pivot)
			{
				call_instruction(2, a_stack, *a_size, 'a');
				i++;
			}
		}
		get_smallest(a_stack, b_stack, a_size, b_size);
		cnt += sort_and_pushback(a_stack, b_stack, a_size, b_size);
		j = 0;
		while ((cnt != 0 && j++ < cnt) && (!is_sorted(a_stack, *a_size)))
		{
			call_instruction(2, a_stack, *a_size, 'a'); // ra
			//print_array(a_stack, *a_size, 'a');
			//print_array(b_stack, *b_size, 'b');
		}
	}
}

	//print_array(a_stack, *a_size, 'a');
	//print_array(b_stack, *b_size, 'b');

void print_array(int *array, int size, char c)
{
	int i = 0;

	printf("------------------------------\n");
	while (i < size)
	{
		printf("%c_stack[%i] is: %d\n", c, i, array[i]);
		i++;
	}
	printf("------------------------------\n");
}
