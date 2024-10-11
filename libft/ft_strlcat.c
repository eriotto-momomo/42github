#include <libft.h>

size_t  ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
    size_t dstlen;
    size_t srclen;
    size_t i;

    dstlen = ft_strlen(dst);
    srclen = ft_strlen(src);
    i = 0;

    if (dstsize <= dstlen)
        return (dstsize + srclen);

    while ((src[i]) && (dstlen + i < (dstsize - 1)))
    {
        dst[dstlen + i] = src[i];
        i++;
    }
    dst[dstlen + srclen] = '\0';
    return (ft_strlen(src) + dstlen);
}
