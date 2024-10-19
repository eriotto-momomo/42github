#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t 	src_len;

	src_len = strlen(src);

	if (src_len + 1 < dstsize)
		memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}

int	main(void)
{
	char dst[50] = ("OOOOOOOOOOOOO");
	char src[50] = ("UUUUUUUUUUUUUU");
	printf("\nBefore ft_strlcpy(): %s\n", dst);

	ft_strlcpy(dst, "aaa", 3);

	printf("After ft_strlcpy(): %s", dst);
	return (0);
}
