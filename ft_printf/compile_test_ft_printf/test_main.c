#include "ft_printf.h"
#include <stdio.h>

int main(void)
{   
    char    *s1;
    char    c;

    int     nb1;
    int     nb2;
    int     nb3;
    int     nb4;

    unsigned int   unb1; 

    void    *ptr;
    ptr = &c;

    printf("\n********PUTSTR********\n");
    s1 = "World";
    ft_printf("FT_PRINTF: Hello %s!\n", s1);
    printf("---PRINTF: Hello %s!\n", s1);


    printf("\n********PUTNBR********\n");
    nb1 = 42;
    nb2 = -42;
    nb3 = 1234567890;
    nb4 = 0;
    ft_printf("FT_PRINTF: The value of the following ints are:\nnb1 = %d\nnb2 = %d\nnb4 = %d\nnb3 = %d\n", nb1, nb2, nb3, nb4);
    printf("---PRINTF: The value of the following ints are:\nnb1 = %d\nnb2 = %d\nnb4 = %d\nnb3 = %d\n", nb1, nb2, nb3, nb4);


    printf("\n********PERCENT*******\n");
    ft_printf("FT_PRINTF: un %, puis %%, puis %%%, puis %%%%, puis %%%%%, puis %%%%%% \n");
    printf("---PRINTF: un %, puis %%, puis %%%, puis %%%%, puis %%%%%, puis %%%%%% \n");
    ft_printf("\nFT_PRINTF: %z %y %w %123 %456 %.// \n");
    printf("---PRINTF: %z %y %w %123 %456 %.//  \n");
    ft_printf("\nFT_PRINTF: A%Zz%%fstt%1224%55%%%476 %yu6%.;%#$@%&)_@&!*(^#%%*&^@#(*&(_%$))) \n");
    printf("---PRINTF: A%Zz%%fstt%1224%55%%%476 %yu6%.;%#$@%&)_@&!*(^#%%*&^@#(*&(_%$))) \n");


    printf("\n****ALL & CNT OUTPUT***\n");
    c = 'x';
    unb1 = 123;
    int printed_chars_printf =      printf("\n---PRINTF:\nCHAR: %c\nSTR: Hello %s\nPTR: %p\nUNSIGNED NBR: %u\nNBR: %d\nLOWERHEX: %x\nUPPERHEX: %X\nPERCENT: %% \n", c, s1, ptr, unb1, nb1, nb2, nb2);
    printf("printf a imprimé %d caractères.\n", printed_chars_printf);
    int printed_chars_ftprintf =    ft_printf("\nFT_PRINTF:\nCHAR: %c\nSTR: Hello %s\nPTR: %p\nUNSIGNED NBR: %u\nNBR: %d\nLOWERHEX: %x\nUPPERHEX: %X\nPERCENT: %% \n", c, s1, ptr, unb1, nb1, nb2, nb2);
    printf("ft_printf a imprimé %d caractères.\n", printed_chars_ftprintf);

    printf("\n******DEC TO HEX******\n");
    ft_printf("FT_PRINTF:\nNegative decimal:%X\nPositive decimal; %X\n", nb2, nb1);
    printf("---PRINTF:\nNegative decimal:%X\nPositive decimal; %X\n", nb2, nb1);
    return (0);
}