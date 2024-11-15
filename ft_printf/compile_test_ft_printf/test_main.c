#include "ft_printf.h"
#include <stdio.h>

int main(void)
{   
    ft_printf("FT_PRINTF: Hello %s!\n", "World");
    printf("---PRINTF: Hello %s!\n", "World");

    ft_printf("\nFT_PRINTF: Ceci est un test!\n");
    printf("---PRINTF: Ceci est un test!\n");

    int printed_chars_printf = printf("\nHello %s, number: %d\n", "World", 42);
    printf("printf a imprimé %d caractères.\n", printed_chars_printf);

    int printed_chars_ftprintf = ft_printf("\nHello %s, number: %d\n", "World", 42);
    printf("printf a imprimé %d caractères.\n", printed_chars_ftprintf);
    
    return (0);
}