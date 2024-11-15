#include "ft_printf.h"

int dec_to_lowerhex(int decimal_nbr, size_t *cnt) // decimal to [lower]case hexadecimal
{
    char    *hexa_nbr;
    int     i;
    
    hexa_nbr = hexa_conversion(decimal_nbr);
    i = 0;
    while (hexa_nbr[i] != 0)
    {
        printf_putstr(hexa_nbr, cnt);
    }
    write(1, "\n", 1);
    return(0);
}