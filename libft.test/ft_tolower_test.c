#include <stdio.h>

int    ft_tolower(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c);
    else if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}

int main(void)
{
    int c;
    int result;

    c = 'Z';
    printf("Before ft_tolower: %c \n", c);
    result = ft_tolower(c);
    printf("After ft_tolower: %c \n", result);
    return (0);
}  
