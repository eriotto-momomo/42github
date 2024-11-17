#include "ft_printf.h"

void	printf_putstr(char *s, size_t *cnt)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		printf_putstr("(null)", cnt);
		return;
	}
	else
		while (s[i] != '\0')
		{
			printf_putchar(s[i], cnt);
			i++;
		}
}
