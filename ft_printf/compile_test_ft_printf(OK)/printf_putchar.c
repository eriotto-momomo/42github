
#include "ft_printf.h"

void	printf_putchar(char c, size_t *cnt) // *cnt = counter
{
	write(1, &c, 1);
	(*cnt)++;
}
