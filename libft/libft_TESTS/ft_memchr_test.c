#include <stdio.h>

void   *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const unsigned char *str;

    i = 0;
    str = s;
    while (i < n)
    {
        if (str[i] == (unsigned char)c)
            return ((void *)&str[i]);
        i++;
    }
    return (0);
}

int main(void)
{
    const void *s;
    int c;
    char *result;

    s = "Hello World!";
    c = 'o';
    printf("Before ft_memchr: %s \n", s);
    result = ft_memchr(s, c, 13);
    printf("After ft_memchr: %s \n", result);
    return (0);
}
