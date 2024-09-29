#include<unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_alphabet(void)
{
    char letter;

    letter = '1';
    while (letter <= '9')
    {
        ft_putchar(letter);
        letter++;
    }
}


int main(void)
{
    ft_print_alphabet();
    return(0);
}
