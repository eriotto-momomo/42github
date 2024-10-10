#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if (ptr_src <= ptr_dst)
	{
		while (len-- > 0)
			*ptr_dst++ = *ptr_src++;
	}
	else if (dst > src)
	{
		ptr_dst += len - 1;
		ptr_src += len - 1;
		while (len-- > 0)
			*ptr_dst-- = *ptr_src--;
	}
	return (dst);
}

int	main(void)
{
	char dst[50] = ("OOOOOOOOOOOOO");
	char src[50] = ("UUUUUUUUUUUUUU");
	printf("\nBefore ft_memmove(): %s\n", dst);

	ft_memmove(dst, src, 8*sizeof(char));

	printf("After ft_memmove(): %s", dst);
	return (0);
}
