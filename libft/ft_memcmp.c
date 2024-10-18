#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const unsigned char *us1;
    const unsigned char *us2;

    i = 0;
    us1 = s1;
    us2 = s2;
    while ((i < n) && (us1[i] == us2[i]))
        i++;
    if (i == n)
        return (0);
    return (us1[i] - us2[i]);
}
