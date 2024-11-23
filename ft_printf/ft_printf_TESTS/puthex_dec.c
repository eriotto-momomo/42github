#include <unistd.h>

void	printf_putchar(char hex, size_t *cnt);

void	puthex_dec(int decimal_nbr, char spec, size_t *cnt)
{
	char			*hex;
	unsigned int	num;

	hex = "0123456789abcdef";
	num = (unsigned int)decimal_nbr;
	if (spec == 'X')
		hex = "0123456789ABCDEF";
	if (num > 15)
		puthex_dec(num / 16, spec, cnt);
	printf_putchar(hex[num % 16], cnt);
}
