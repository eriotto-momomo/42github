#include "libft.h"

void   *ft_calloc(size_t count, size_t size)
{
    unsigned char *tmp;
    size_t i;

    tmp = malloc(count * size);
    i = 0;
    if (!tmp)
        return (NULL);
    while (i < count * size)
    {
        tmp[i] = 0;
        i++;
    }
    return (tmp);
}
