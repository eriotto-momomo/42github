#include <stdio.h>
#include <string.h>

/*#include <libft.h>*/

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

        while ((src[i]) && (dstlen + i < (dstsize - 1)))
        {
            dst[dstlen + i] = src[i];
            i++;
        }
        dst[dstlen + srclen] = '\0';
        return (strlen(src) + dstlen);
}

int	main(void)
{
	char dst[50] = ("1234");
	char src[50] = ("5678");
	printf("\nBefore ft_strlcat(): %s\n", dst);

	ft_strlcat(dst, src, 9);

	printf("After ft_strlcat(): %s", dst);
	return (0);
}
