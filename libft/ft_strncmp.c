#include <libft.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while ((n > 0) && (s1[i] != '\0') && (s1[i] == s2[j]))
    {
        i++;
        j++;
        n--;
    }
    if (n == 0)
        return (0);
    else
        return (s1[i] - s2[j]);
}
