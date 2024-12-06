#include <stdio.h>
#include <unistd.h>

void	printf_putchar(char c)
{
	write(1, &c, 1);
}

/*void	ft_puthex(unsigned int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		ft_puthex(n / 16);
	printf_putchar(hex[n % 16]);
}*/

void	puthex(unsigned int to_convert)
{
	char	*hex;;
	unsigned long long	conversion;

	conversion = to_convert;
	hex = "0123456789abcedf";
	if (conversion > 15)
		puthex(conversion / 16);
	printf_putchar(hex[conversion % 16]);
}

int main(void)
{
	int n;

	n = -2000;
	puthex(n);
	printf("\n");
	printf("The value of `n` converted by PRINTF is: %x\n", n);
	return (0);
}
