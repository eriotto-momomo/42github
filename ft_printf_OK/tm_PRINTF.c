#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{

	char    c = 'x';

    char    *s1 = "World";
    char    *s2 = "12345";
    char    *s3 = "%!ayg";
    char    *s4 = "  '0";
	char	*s5 = "hey%";
	char	*s6 = "%";

    int     nb1 = 42;
    int     nb2 = -42;
    int     nb3 = 1234567890;
    int     nb4 = 0;
	int		nb5 = INT_MAX;
	int 	nb6 = INT_MIN;

    unsigned int	unb1 = 123;

    void	*ptr = &c;
	void	*ptr2 = &s5;
	void	*ptr3 = &s6;

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
    ft_printf("FT_PRINTF: The value of the following ints are:\nnb1 = %d\nnb2 = %d\nnb3 = %d\nnb4 = %d\nnb5 = %d\nnb6 = %d\n", nb1, nb2, nb3, nb4, nb5, nb6);
	ft_printf("-------------------------\n");
       printf("---PRINTF: The value of the following ints are:\nnb1 = %d\nnb2 = %d\nnb3 = %d\nnb4 = %d\nnb5 = %d\nnb6 = %d\n", nb1, nb2, nb3, nb4, nb5, nb6);
	ft_printf("-------------------------\n");
    ft_printf("FT_PRINTF: The value of (nb5 + 1) is: %d\n", nb5 + 1);
       printf("---PRINTF: The value of (nb5 + 1) is: %d\n", nb5 + 1);
	ft_printf("FT_PRINTF: The value of (nb6 - 1) is: %d\n", nb6 - 1);
       printf("---PRINTF: The value of (nb6 - 1) is: %d\n", nb6 - 1);


    printf("\n********PERCENT*******\n");
    ft_printf("FT_PRINTF: un %, puis %%, puis %%%, puis %%%%, puis %%%%%, puis %%%%%% \n");
       printf("---PRINTF: un %, puis %%, puis %%%, puis %%%%, puis %%%%%, puis %%%%%% \n");

    printf("\n****ALL & CNT OUTPUT***\n");
    int printed_chars_printf =      printf("---PRINTF:\nCHAR: %c\nSTR: Hello %s\nPTR: %p\nUNSIGNED NBR: %u\nNBR: %d\nLOWERHEX: %x\nUPPERHEX: %X\nPERCENT: %% \n", c, s1, ptr, unb1, nb1, nb2, nb2);
    ft_printf("-------------------------\n");
	int printed_chars_ftprintf = ft_printf("FT_PRINTF:\nCHAR: %c\nSTR: Hello %s\nPTR: %p\nUNSIGNED NBR: %u\nNBR: %d\nLOWERHEX: %x\nUPPERHEX: %X\nPERCENT: %% \n", c, s1, ptr, unb1, nb1, nb2, nb2);
    ft_printf("-------------------------\n");
	printf("---printf a imprimé %d caractères.\n", printed_chars_printf);
	printf("ft_printf a imprimé %d caractères.\n", printed_chars_ftprintf);


    printf("\n******DEC TO HEX******\n");
    ft_printf("FT_PRINTF:\nNegative decimal: %X\nPositive decimal; %X\n", nb2, nb1);
       printf("---PRINTF:\nNegative decimal: %X\nPositive decimal; %X\n", nb2, nb1);

     printf("\n*********PTR*********\n");
    ft_printf("FT_PRINTF: %p %p\n", 0, 0);
       printf("---PRINTF: %p %p\n", 0, 0);
	ft_printf("-------------------------\n");
	ft_printf("FT_PRINTF: %p\n", ptr2);
       printf("---PRINTF: %p\n", ptr2);
	ft_printf("-------------------------\n");
	ft_printf("FT_PRINTF: %p\n", ptr3);
       printf("---PRINTF: %p\n", ptr3);


 	printf("\n********..44..********\n");
    ft_printf("FT_PRINTF: %d\n", 0);
       printf("---PRINTF: %d\n", 0);


	printf("\n********..47..********\n");
    ft_printf("FT_PRINTF: %d%d%d%d\n", 10, 20, 30, 5);
       printf("---PRINTF: %d%d%d%d\n", 10, 20, 30, 5);

	printf("\n**** PERCENT ALONE****\n");
    ft_printf("FT_PRINTF: %s\n", s5);
       printf("---PRINTF: %s\n", s5);
	ft_printf("FT_PRINTF: %s\n", s6);
       printf("---PRINTF: %s\n", s6);

    return (0);
}
