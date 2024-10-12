#include <stdio.h>

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i++;
    }
    if (c == '\0')
            return ((char *)&s[i]);

    return (0);
}

int main(void)
{
    const char *s;
    int c;
    char *result;

    s = "Hello World!";
    c = '\0';
    printf("Before ft_strchr: %s \n", s);
    result = ft_strchr(s, c);
    printf("After ft_strchr: %d \n", result);
    return (0);
}
