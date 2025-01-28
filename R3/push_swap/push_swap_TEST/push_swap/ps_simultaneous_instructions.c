#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// NE PAS OUBLIER DE REMPLACER PRINTF PAR FT_PRINTF !!!!!!!
// NE PAS OUBLIER DE REMPLACER AUTRES FONCTIONS PAR FT_* !!
// NE PAS OUBLIER DE SUPPRIMER LIBRAIRIE INUTILES !!!!!!!!!
// FT_PRINTF CHAQUE INSTRUCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!
// UTILISER LIBFT ET SUPPRIMER FONCTIONS EN TROP DANS UTILS

void	rrr(int *a_stack, int *b_stack, int a_size, int b_size);
void	rr(int *a_stack, int *b_stack, int a_size, int b_size);
void	ss(int *a_stack, int *b_stack);

// 'swap' on A and B at the same time
void	ss(int *a_stack, int *b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_printf("ss\n");
}
// 'rotate' on A and B at the same time
void	rr(int *a_stack, int *b_stack, int a_size, int b_size)
{
	rotate(a_stack, a_size);
	rotate(b_stack, b_size);
	ft_printf("rr\n");
}
// 'reverse_rotate' on A and B at the same time
void	rrr(int *a_stack, int *b_stack, int a_size, int b_size)
{
	reverse_rotate(a_stack, a_size);
	reverse_rotate(b_stack, b_size);
	ft_printf("rrr\n");
}
