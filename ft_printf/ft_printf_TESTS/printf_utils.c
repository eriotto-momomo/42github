#include "ft_printf.h"

void	printf_putchar(char c, size_t *cnt)
{
	write(1, &c, 1);
	(*cnt)++;
}

void	printf_putstr(char *s, size_t *cnt)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		printf_putstr("(null)", cnt);
		return ;
	}
	else
	{
		while (s[i] != '\0')
		{
			printf_putchar(s[i], cnt);
			i++;
		}
	}
}

void	puthex(unsigned int to_convert, char spec, size_t *cnt)
{
	char				*hex;
	unsigned long long	conversion;

	conversion = to_convert;
	if (spec == 'x' || spec == 'p')
		hex = "0123456789abcdef";
	else if (spec == 'X')
		hex = "0123456789ABCDEF";
	if (conversion > 15)
		puthex(conversion / 16, spec, cnt);
	printf_putchar(hex[conversion % 16], cnt);
}

static int	cntdigits(unsigned int nbr)
{
	size_t	digits;

	if (nbr == 0)
		return (1);
	digits = 0;
	while (nbr >= 1)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

char	*itoa(unsigned int n)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	digits;

	nbr = n;
	digits = cntdigits(nbr);
	str = (char *)malloc(digits + 1);
	if (str == 0)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[(digits - 1)] = (nbr % 10) + '0';
		nbr /= 10;
		digits--;
	}
	return (str);
}
