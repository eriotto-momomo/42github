#include <libft.h>

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
	    		hexa_nbr[i] = tmp + 'A' - 10; // upper case
		    i++;
		    decimal_nbr /= 16;
	    }
    }
    hexa_nbr[i] = '\0';
    reverse_string(hexa_nbr, i);
    return (hexa_nbr);
}

int dec_to_upperhex(int decimal_nbr) // decimal to [UPPER]case hexadecimal
{
    char    *hexa_nbr;
    int     i;

    hexa_nbr = hexa_conversion(decimal_nbr);
    i = 0;
    while (hexa_nbr[i] != 0)
    {
        write(1, &hexa_nbr[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return(0);
}