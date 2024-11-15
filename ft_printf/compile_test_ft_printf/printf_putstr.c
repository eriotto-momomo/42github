
#include "ft_printf.h"

void	printf_putstr(char *s, size_t *cnt)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		printf_putchar(s[i], cnt);
		i++;
	}
}
