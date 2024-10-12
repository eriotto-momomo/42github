#include <stdio.h>

char    *ft_strrchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    while (i >= 0)
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i--;
    }
    return (0);
}

int main(void)
{
    const char *s;
    int c;
    char *result;

    s = "Hello World!";
    c = 'H';
    printf("Before ft_strrchr: %s \n", s);
    result = ft_strrchr(s, c);
    printf("After ft_strrchr: %d \n", result);
    return (0);
}
