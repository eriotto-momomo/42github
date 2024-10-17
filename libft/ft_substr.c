#include <libft.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dst;
    size_t i;

    i = 0;
    if (!s)
        return (NULL); //OK
    if (start > ft_strlen(s)) || (start + len > ft_strlen(s)) //A corriger
        return (ft_strdup(""));
    while (s[i] <= start)
    {
        while ((s[i] > start) && (j < len))
        {
            dst[i] = s[i];
            i++;
            j++;
        }
        j = 0;
        i++;
    }
    return (dst);
}
