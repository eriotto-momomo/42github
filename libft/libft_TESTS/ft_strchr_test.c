#include <stdio.h>

char    *ft_strchr(const char *s, int c)
{
    int i;
	char cc;

    i = 0;
	cc = (char) c;
    while (s[i])
    {
        if (s[i] == cc)
            return ((char *)&s[i]);
        i++;
    }
    if (s[i] == cc)
            return ((char *)&s[i]);
    return (0);
}

int main(void)
{
    const char *s;
    int c;
    char *result;

    s = "Hello World!";
    c = '!';
    printf("Before ft_strchr: %s \n", s);
    result = ft_strchr(s, c);
    printf("After ft_strchr: %s \n", result);
    return (0);
}
