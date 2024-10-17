#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *res;
    unsigned int i;

    res = malloc((ft_strlen(s) + 1) * sizeof(char));
    i = 0;
    if (res == 0)
        return (NULL);
    while (i < ft_strlen(s))
    {
        res[i] = (*f)(i, s[i]);
        i++;
    }
    res[i] = 0;

    return (res);
}
