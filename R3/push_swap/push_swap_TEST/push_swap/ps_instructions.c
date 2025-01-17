#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

// All the following functions are instructions
// that takes a_stack or b_stack as argument,
// in order to execute the sorting algorithm.

//void	compare_two_elements(int *stack, int size);
void	reverse_rotate(int *stack, int size);
void	rotate(int *stack, int size);
void	push(int *src_stack, int *dst_stack, int *src_size, int *dst_size);
void	swap(int *stack);

// Interverts the first two elements in a stack.
void	swap(int *stack)
{
	int	tmp_stack;

	if (stack == NULL)
		return;
	tmp_stack = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp_stack;
}

// Takes first element in src_stack and place it on
// top of dst_stack.
// Every other elements in dst_stack go down.
// "go down" means(horizontally speaking): that
// elements are going from left to right in the string.
// 'DOWN' = '->' = '--'
// Every other elements in src_stack go up.
// "go up" means (horizontally speaking): that
// elements are going from right to left in the string.
// 'UP' = '<-' = '++'
void	push(int *src_stack, int *dst_stack, int *src_size, int *dst_size)
{
	int	i;

	if (src_stack == NULL || dst_stack == NULL || *src_size <= 0)
		return;
	i = *dst_size;
	while (i > 0)
	{
		dst_stack[i] = dst_stack[i - 1];
		i--;
	}
	dst_stack[0] = src_stack[0];
	i = 0;
	while (i < *src_size - 1)
	{
		src_stack[i] = src_stack[i + 1];
		i++;
	}
	(*src_size)--;
	(*dst_size)++;
}

// Every elements go up in the stack, the first
// element becomes the last. "go up" means
// (horizontally speaking): that elements
// are going from right to left in the string.
// 'UP' = '<-' = '++'
void	rotate(int *stack, int size)
{
	int	tmp_stack;
	int	i;

	if (stack == NULL || size < 2)
		return;
	tmp_stack = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp_stack;
}

// Every elements go down in the stack, the last
// element becomes the first. "go down" means
// (horizontally speaking): that elements
// are going from left to right in the string.
// 'DOWN' = '->' = '--'
void	reverse_rotate(int *stack, int size)
{
	int	tmp_stack;
	int	i;

	if (stack == NULL || size < 2)
		return;
	tmp_stack = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp_stack;
}
