#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    char    *s1;
    s1 = "World";
    char    *s2;
    s2 = "12345";
    char    *s3;
    s3 = "%!ayg";
    char    *s4;
    s4 = "  '0";

    char    c;
    c = 'x';

    int     nb1;
    int     nb2;
    int     nb3;
    int     nb4;
    nb1 = 42;
    nb2 = -42;
    nb3 = 1234567890;
    nb4 = 0;

    unsigned int   unb1;
    unb1 = 123;

    void    *ptr;
    ptr = &c;

    printf("\n********PUTSTR********\n");
    ft_printf("CHAR STR s1 is: %s\n", s1);
    ft_printf("FT_PRINTF: Hello %s!\n", s1);
    printf("---PRINTF: Hello %s!\n", s1);

    ft_printf("\nCHAR STR s2 is: %s\n", s2);
    ft_printf("FT_PRINTF: %s\n", s2);
    printf("---PRINTF: %s\n", s2);

    ft_printf("\nCHAR STR s3 is: %s\n", s3);
    ft_printf("FT_PRINTF: %s\n", s3);
    printf("---PRINTF: %s\n", s3);

    ft_printf("\nCHAR STR s4 is: %s\n", s4);
    ft_printf("FT_PRINTF: %s\n", s4);
    printf("---PRINTF: %s\n", s4);



    printf("\n********PUTNBR********\n");
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
    int printed_chars_printf =      printf("\n---PRINTF:\nCHAR: %c\nSTR: Hello %s\nPTR: %p\nUNSIGNED NBR: %u\nNBR: %d\nLOWERHEX: %x\nUPPERHEX: %X\nPERCENT: %% \n", c, s1, ptr, unb1, nb1, nb2, nb2);
    printf("printf a imprimé %d caractères.\n", printed_chars_printf);
    int printed_chars_ftprintf =    ft_printf("\nFT_PRINTF:\nCHAR: %c\nSTR: Hello %s\nPTR: %p\nUNSIGNED NBR: %u\nNBR: %d\nLOWERHEX: %x\nUPPERHEX: %X\nPERCENT: %% \n", c, s1, ptr, unb1, nb1, nb2, nb2);
    printf("ft_printf a imprimé %d caractères.\n", printed_chars_ftprintf);


    printf("\n******DEC TO HEX******\n");
    ft_printf("FT_PRINTF:\nNegative decimal:%X\nPositive decimal; %X\n", nb2, nb1);
    printf("---PRINTF:\nNegative decimal:%X\nPositive decimal; %X\n", nb2, nb1);

     printf("\n*********PTR*********\n");
    ft_printf("FT_PRINTF: %p %p\n", 0, 0);
    printf("---PRINTF: %p %p\n", 0, 0);


 	printf("\n*********..44..*********\n");
    ft_printf("FT_PRINTF: %d\n", 0);
    printf("---PRINTF: %d\n", 0);


	printf("\n*********..47..*********\n");
    ft_printf("FT_PRINTF: %d%d%d%d\n", 10, 20, 30, 5);
    printf("---PRINTF: %d%d%d%d\n", 10, 20, 30, 5);

    return (0);
}
