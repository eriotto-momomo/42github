#include "libft.h"

static int to_trim(char const *s1, char c)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (c == s1[i])
            return (1);
        i++;
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *res;
    size_t  start;
    size_t  end;
    size_t  i;

    start = 0;
    end = 0;
    i = 0;
    while (to_trim(set, s1[start]))
        start++;
    while (s1[end])
        end++;
    while (to_trim(set, s1[end - 1]))
        end--;
    res = (char *)malloc((end - start + 1) * sizeof(char));
    if (res == 0)
        return (NULL);
    while (start < end)
        res[i++] = s1[start++];
    res[i] = '\0';
    return (res);
}
