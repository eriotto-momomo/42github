#include "ft_printf.h"

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
	    		hexa_nbr[i] = tmp + 'a' - 10; // lower case
		    i++;
		    decimal_nbr /= 16;
	    }
    }
    hexa_nbr[i] = '\0';
    reverse_string(hexa_nbr, i);
    return (hexa_nbr);
}