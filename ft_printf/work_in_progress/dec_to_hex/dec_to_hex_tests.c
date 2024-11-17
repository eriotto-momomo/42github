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

void reverse_string(char *str, int len)
{
    int start = 0;
    int end = len - 1;
    char tmp;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}

char	*hexa_conversion(int decimal_nbr)
{
	int		    tmp;
	int		    i;
	static char hexa_nbr[100];

	i = 0;

    if (decimal_nbr == 0)
        hexa_nbr[i] = '0';
    else
    {
	    while (decimal_nbr != 0)
        {
		    tmp = decimal_nbr % 16;
		    if (tmp < 10)
			    hexa_nbr[i] = tmp + '0';
    		else
	    		hexa_nbr[i] = tmp + 'A' - 10; 
		    i++;
		    decimal_nbr /= 16;
	    }
    }
    hexa_nbr[i] = '\0';
    reverse_string(hexa_nbr, i);
    return (hexa_nbr);
}

int dec_to_hex(int decimal_nbr)
{
    char    *hexa_nbr;
    hexa_nbr = hexa_conversion(decimal_nbr);

    printf_putstr(hexa_nbr);
    return(0);
}

int main(void)
{
    int decimal_nbr;
    decimal_nbr = 123456789;

    dec_to_hex(decimal_nbr);
    return (0);
}


// conversion dec to hexadec
// 1453/16 = 90,8125
// You take the number before the comma and you have 0,8125. 0,8125 * 16 = 13. So the remainder is 13