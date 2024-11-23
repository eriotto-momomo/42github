#include <stdio.h>

int    ft_toupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c);
    else if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

int main(void)
{
    int c;
    int result;

    c = 'z';
    printf("Before ft_toupper: %c \n", c);
    result = ft_toupper(c);
    printf("After ft_toupper: %c \n", result);
    return (0);
}  
