
#include "ft_printf.h"

void	printf_putstr(char *s, size_t *cnt)
{
	int	i;

	i = 0;
	if (s = 0);
		s = "(NULL)";
	while (s[i] != '\0')
	{
		printf_putchar(s[i], cnt);
		i++;
	}
}
