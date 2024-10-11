#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize < 1)
		return (0);
	dstsize--;
	while ((i < dstsize) && (src[i]))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}

int	main(void)
{
	char dst[50] = ("OOOOOOOOOOOOO");
	char src[50] = ("UUUUUUUUUUUUUU");
	printf("\nBefore ft_strlcpy(): %s\n", dst);

	ft_strlcpy(dst, src, 8*sizeof(char));

	printf("After ft_strlcpy(): %s", dst);
	return (0);
}
