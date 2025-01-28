#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sort_case_l(int *a_stack, int *b_stack, int *a_size, int *b_size);
void	sort_ascending(int *stack, int *size);
void	sort_descending(int *stack, int *size);

void	sort_case_l(int *a_stack, int *b_stack, int *a_size, int *b_size)
{
	/*if ((((*a_size >= 2) && (*b_size == 2)) && ((a_stack[0] > a_stack[1]) &&
	(b_stack[0] < b_stack[1]))) || (((*a_size >= 3) && (*b_size == 3)) &&
	(((a_stack[0] > a_stack[1] && a_stack[1] > a_stack[2]) &&
	(b_stack[0] < b_stack[1] && b_stack[1] < b_stack[2])) ||
	((a_stack[0] > a_stack[2] && a_stack[2] > a_stack[1]) &&
	(b_stack[0] < b_stack[2] && b_stack[2] < b_stack[1])) ||
	((a_stack[1] > a_stack[0] && a_stack[0] > a_stack[2]) &&
	(b_stack[1] < b_stack[0] && b_stack[0] < b_stack[2])) ||
	((a_stack[0] > a_stack[1] && a_stack[2] > a_stack[1] &&
	a_stack[2] > a_stack[0]) && (b_stack[0] < b_stack[1] &&
	b_stack[2] < b_stack[1] && b_stack[2] < b_stack[0])) ||
	((a_stack[0] < a_stack[2] && a_stack[2] < a_stack[1]) &&
	(b_stack[0] > b_stack[2] && b_stack[2] > b_stack[1])))))
		sort_simultaneously(a_stack, b_stack, a_size, b_size);*/
	if (*a_size >= 3 && *a_size <= 6) // Si la pile A a 3 ou moins éléments, on peut trier directement par ordre ascendant
		sort_small_stack(a_stack, b_stack, a_size, b_size);
	else if (*a_size >= 1 && *b_size <= 3) // Si la pile A est vide, on trie la pile B dans l'ordre descendant
		sort_descending(b_stack, b_size);
	else
		return;
}

//void	sort_l_simultaneously
	//if (((*a_size >= 2) && (*b_size == 2)) && ((a_stack[0] > a_stack[1]) && (b_stack[0] < b_stack[1])))
			//ss(a_stack, b_stack);

// Sort in ascending order
// Used for small arrays in A and simultaneously sorting both stacks
void	sort_ascending(int *stack, int *size)
{
	printf("sort_ascending\n");
	if (*size == 1) 											// Only one int = considered sorted
		return;
	if ((*size == 2) && (stack[0] > stack[1]))					// Only two int
		call_instruction(1, stack, *size, 'a');					// swap
	else if (*size == 3)
	{
		if (stack[0] > stack[1] && stack[1] > stack[2])
		{														// [3, 2, 1]
			call_instruction(1, stack, *size, 'a');				// swap
			call_instruction(3, stack, *size, 'a');				// reverse_rotate
		}
		else if (stack[0] > stack[2] && stack[2] > stack[1])	// [3, 1, 2]
			call_instruction(2, stack, *size, 'a');				// rotate
		 else if (stack[1] > stack[0] && stack[0] > stack[2])	// [2, 3, 1]
			call_instruction(3, stack, *size, 'a');				// reverse_rotate
		else if (stack[0] > stack[1] && stack[2] > stack[1] && stack[2] > stack[0]) // [2, 1, 3]
			call_instruction(1, stack, *size, 'a');				// swap
		else if (stack[0] < stack[2] && stack[2] < stack[1])
		{														// [1, 3, 2]
			call_instruction(3, stack, *size, 'a');				// reverse_rotate
			call_instruction(1, stack, *size, 'a');				// swap
		}
	}
}

// Sort in descending order
// Used for big arrays in B
void	sort_descending(int *stack, int *size)
{
	printf("sort_descending\n");
	if (*size == 1) 											//Only one int = considered sorted
		return;
	else if ((*size == 2) && (stack[0] < stack[1])) 			//Only two int
		call_instruction(1, stack, *size, 'b');					//swap
	else if (*size == 3)
	{
		if (stack[0] < stack[1] && stack[1] < stack[2])
		{														// [1, 2, 3]
			call_instruction(1, stack, *size, 'b');				//swap
			call_instruction(3, stack, *size, 'b');				//reverse_rotate
		}
		else if (stack[0] < stack[2] && stack[2] < stack[1])	// [1, 3, 2]
			call_instruction(2, stack, *size, 'b');				//rotate
		else if (stack[1] < stack[0] && stack[0] < stack[2])	// [2, 1, 3]
			call_instruction(3, stack, *size, 'b');				//reverse_rotate
		else if (stack[0] < stack[1] && stack[2] < stack[1] && stack[2] < stack[0]) // [2, 3, 1]
			call_instruction(1, stack, *size, 'b');									//swap
		else if (stack[0] > stack[2] && stack[2] > stack[1])
		{														// [3, 1, 2]
			call_instruction(3, stack, *size, 'b');				//reverse_rotate
			call_instruction(1, stack, *size, 'b');				//swap
		}
	}
}
