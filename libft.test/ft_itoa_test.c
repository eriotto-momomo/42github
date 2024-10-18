#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

static int count_size(int n)
{
    int i;

    i = 0;
    if (n < 0)
        n *= -1;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    char        *str;
    int         i;
    long int    nb;

    i = count_size(n);
    nb = n;
    str = malloc(i + 1 * sizeof(char));
    if (str == 0)
        return (NULL);
    str[i] = '\0';
    if (n < 0)
        nb *= -1;
    while (i >= 0)
    {
        str[i] = (nb % 10) + 48;
        nb /= 10;
        i--;
    }
    if (n < 0)
        str[0] = '-';
    return (str);
}

int main(void)
{
    int n;
    char *res;

    n = -2147483648;
    printf("The value of integer 'n' is: %d\n", n);
    res = ft_itoa(n);
    printf("Integer 'n' converted to a char is: %s\n", res);

    return (0);
}
