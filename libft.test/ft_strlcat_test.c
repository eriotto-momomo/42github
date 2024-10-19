#include <stdio.h>
#include <string.h>

size_t  ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
        size_t dstlen;
        size_t srclen;
        size_t i;

        dstlen = strlen(dst);
        srclen = strlen(src);
        i = 0;
        if (dstsize <= dstlen)
            return (dstsize + srclen);
        while ((src[i]) && (i < dstsize - dstlen - 1))
        {
            dst[dstlen + i] = src[i];
            i++;
        }
        dst[dstlen + i] = '\0';
        return (srclen + dstlen);
}

int	main(void)
{
	char dst[50] = ("pqrs");
	char src[50] = ("abcdefghi");
	printf("\nBefore ft_strlcat(): %s\n", dst);

	ft_strlcat(dst, src, 10);

	printf("After ft_strlcat(): %s", dst);
	return (0);
}
