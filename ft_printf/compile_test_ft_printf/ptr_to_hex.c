#include "ft_printf.h"

void *hex_conversion(unsigned long long ptr, size_t *cnt)
{
	char		        *hex;

	hex = "0123456789abcdef";
	if (ptr > 15)
		hex_conversion(ptr/ 16, cnt);
	printf_putchar(hex[ptr % 16], cnt);
}

int ptr_to_hex(void *ptr, char spec, size_t *cnt) // ptr to [lower]case hexadecimal
{ 
    unsigned long long  castptr;
    
    castptr = (unsigned long long)ptr;
    printf_putstr("0x", cnt);
    hex_conversion(castptr, cnt);
    return(0);
}

/*
int ptr_to_hex(void *ptr, char spec, size_t *cnt) // ptr to [lower]case hexadecimal
{ 
    unsigned long long  castptr;
    
    castptr = (unsigned long long)ptr;
    printf_putstr("0x", cnt);
    hexa_ptr = hex_conversion(castptr, cnt);
    printf_putstr(hexa_ptr, cnt);
    return(0);
}
*/