#include "ft_printf.h"

int ptr_to_hex(void *ptr, size_t *cnt) // ptr to [lower]case hexadecimal
{ 
    unsigned long long  castptr;
    char                *hexa_ptr;
    char                *str;
    int                 i;

    castptr = (unsigned long long)ptr;
    hexa_ptr = hexa_conversion(castptr);
    str = "0x";
    i = 0;
    printf_putstr(str, cnt);
    while (hexa_ptr[i] != 0)
    {
        printf_putstr(hexa_ptr, cnt);
    }
    return(0);
}