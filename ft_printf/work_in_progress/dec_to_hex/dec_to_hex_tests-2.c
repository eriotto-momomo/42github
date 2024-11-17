#include <unistd.h>

void	printf_putchar(char c) // *cnt = counter
{
    write(1, &c, 1);
}

void	printf_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		printf_putchar(s[i]);
		i++;
	}
}

void	dec_to_hex(int n, char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n > 15)
		dec_to_hex(n / 16, c);
	printf_putchar(hex[n % 16]);
}

int main(void)
{
    char c;
    int decimal_nbr;

    c = 'x';
    decimal_nbr = -123456789;

    dec_to_hex(decimal_nbr, c);
    return (0);
}


// conversion dec to hexadec
// 1453/16 = 90,8125
// You take the number before the comma and you have 0,8125. 0,8125 * 16 = 13. So the remainder is 13