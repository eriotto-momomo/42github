#include <libft.h>

int strncmp(const char *s1, const char *s2, size_t n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while ((s1[i]) && (s2[j]) && (i <= n) && (j <= n))
    {
        i++;
        j++;
    }
    return (i);
}
