#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

void	sort(int *stack, int *size);
//int	pushback_and_rotate(int *a_stack, int *b_stack, int *a_size, int *b_size);
int	sort_and_pushback(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	get_smallest(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	push_swap_sort(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	*push_swap(int *a_stack, int *size);

// À delete!
void print_array(int size, int *array, char c);



void	sort(int *stack, int *size)
{
	if (*size == 1) 								//Only one int = considered sorted
		return;
	else if ((*size == 2) && (stack[0] < stack[1])) //Only two int
		call_instruction(1, stack, *size, 'b');		//swap
	else if (*size == 3)
	{
		if (stack[0] < stack[1] && stack[1] < stack[2]) // [1, 2, 3]
		{
			call_instruction(1, stack, *size, 'b');	//swap
			call_instruction(3, stack, *size, 'b');	//reverse_rotate
		}
		else if (stack[0] < stack[2] && stack[2] < stack[1]) // [1, 3, 2]
			call_instruction(2, stack, *size, 'b');	//rotate
		else if (stack[1] < stack[0] && stack[0] < stack[2]) // [2, 1, 3]
			call_instruction(3, stack, *size, 'b');	//reverse_rotate
		else if (stack[0] < stack[1] && stack[2] < stack[1] && stack[2] < stack[0]) // [2, 3, 1]
			call_instruction(1, stack, *size, 'b');	//swap
		else if (stack[0] > stack[2] && stack[2] > stack[1]) // [3, 1, 2]
		{
			call_instruction(3, stack, *size, 'b');	//reverse_rotate
			call_instruction(1, stack, *size, 'b');	//swap
		}
	}
}

int	sort_and_pushback(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	cnt;

	sort(b_stack, b_size);
	cnt = 0;
	while (*b_size > 0)
	{
		push(b_stack, a_stack, b_size, a_size);// pa
		ft_printf("pa\n");
		cnt++;
	}
	return (cnt);
}

/*int	pushback_and_rotate(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	cnt;
	int	tmp;

	sort(b_stack, b_size);
	cnt = 0;
	while (*b_size > 0)
	{
		push(b_stack, a_stack, b_size, a_size);// pa
		ft_printf("pa\n");
		cnt++;
	}
	tmp = cnt;
	while (cnt > 0)
	{
		call_instruction(2, a_stack, *a_size, 'a');
		cnt--;
	}
	return (tmp);
}*/

void	get_smallest(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	i;
	int b_pivot;

	while (*b_size > 3) //|| !is_sorted(b_stack, *b_size))
	{
		b_pivot = get_exact_median(*b_size, b_stack);
		i = 0;
		while (b_stack[i]) //push to A (pa) everything that's bigger than pivot
		{
			while (b_stack[0] >= b_pivot)
			{
				push(b_stack, a_stack, b_size, a_size);
				ft_printf("pa\n");
			}
			call_instruction(2, b_stack, *b_size, 'b');
			i++;
		}
	}
}

void push_swap_sort(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	i;
	int j;
	int	a_pivot;
	int	cnt;

	cnt = 0;
	if(is_sorted(a_stack, *a_size))
		return;
	a_pivot = get_exact_median((*a_size - cnt), a_stack);
	printf ("a_pivot before #1 sort = %d\n", a_pivot);
	i = 0;
	while (i < (*a_size - cnt))
	{//push to B (pb) everything that's smaller than pivot
		printf("a_stack[%i] = %d\n", i, a_stack[i]);
		if (a_stack[0] <= a_pivot)
		{
			printf("IS SMALLER!\n");
			push(a_stack, b_stack, a_size, b_size);
			ft_printf("pb\n");
		}
		else if (a_stack[0] > a_pivot)
		{
			printf("IS BIGGER!\n");
			//printf("a_stack[%i] = %d IS BIGGER!\n", i, a_stack[i]);
			call_instruction(2, a_stack, *a_size, 'a');
			i++;
		}
		//if (a_stack[0] > a_pivot)
			//i++;
	}
	j = 0;
	print_array(*a_size, a_stack, 'a');
	print_array(*b_size, b_stack, 'b');
	get_smallest(a_stack, b_stack, a_size, b_size);
	cnt += sort_and_pushback(a_stack, b_stack, a_size, b_size);
	while ((cnt != 0) && (j++ < cnt))
		call_instruction(2, a_stack, *a_size, 'a'); // ra
	printf ("cnt after #1 sort = %d\n", cnt);
	print_array(*a_size, a_stack, 'a');

	///////// 2 //////////

	a_pivot = get_exact_median((*a_size - cnt), a_stack);
	printf ("a_pivot before #1 sort = %d\n", a_pivot);
	i = 0;
	while (i < (*a_size - cnt))
	{//push to B (pb) everything that's smaller than pivot
		printf("a_stack[%i] = %d\n", i, a_stack[i]);
		if (a_stack[0] <= a_pivot)
		{
			printf("IS SMALLER!\n");
			push(a_stack, b_stack, a_size, b_size);
			ft_printf("pb\n");
		}
		else if (a_stack[0] > a_pivot)
		{
			printf("IS BIGGER!\n");
			//printf("a_stack[%i] = %d IS BIGGER!\n", i, a_stack[i]);
			call_instruction(2, a_stack, *a_size, 'a');
			i++;
		}
		//if (a_stack[0] > a_pivot)
			//i++;
	}
	j = 0;
	print_array(*a_size, a_stack, 'a');
	print_array(*b_size, b_stack, 'b');
	get_smallest(a_stack, b_stack, a_size, b_size);
	cnt += sort_and_pushback(a_stack, b_stack, a_size, b_size);
	while ((cnt != 0) && (j++ < cnt))
		call_instruction(2, a_stack, *a_size, 'a'); // ra
	printf ("cnt after #1 sort = %d\n", cnt);
	print_array(*a_size, a_stack, 'a');
}

//// BACKUP ////
/*void push_swap_sort(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	int	i;
	int original_size;
	int	a_pivot;
	int	cnt;

	original_size = *a_size;
	cnt = 0;
	if(is_sorted(a_stack, *a_size))
		return;
	a_pivot = get_exact_median((*a_size - cnt), a_stack);
	i = 0;
	while (i < original_size)
	{//push to B (pb) everything that's smaller than pivot
		if (a_stack[0] < a_pivot)
		{
			push(a_stack, b_stack, a_size, b_size);
			ft_printf("pb\n");
		}
		else
			call_instruction(2, a_stack, *a_size, 'a');
		i++;
	}
	print_array(*a_size, a_stack, 'a');
	print_array(*b_size, b_stack, 'b');
	get_smallest(a_stack, b_stack, a_size, b_size);
	cnt += pushback_and_rotate(a_stack, b_stack, a_size, b_size);
}*/

void	*push_swap(int *a_stack, int *size)
{
	//int i = 0;
	int	*b_stack;
	int a_size;
	int	b_size;

	a_size = *size;
	b_size = 0;
	b_stack = malloc(sizeof(int) * *size);
	if (b_stack == NULL)
		return (0);
	push_swap_sort(a_stack, b_stack, &a_size, &b_size);
	//print_array(a_size, a_stack, 'a');
	//print_array(b_size, b_stack, 'b');
	free(b_stack);
	return(0);
}

void print_array(int size, int *array, char c)
{
	int i = 0;

	while (i < size)
	{
		printf("%c_stack[%i] is: %d\n", c, i, array[i]);
		i++;
	}
	printf("------------------------------\n");
}
