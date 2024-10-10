#include <stdio.h>
#include <string.h>

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n -- > 0)
		*ptr++ = 0;
	return (s);
}

int	main(void)
{
	char s[50] = ("GeeksForGeeks is for programming geeks.");
	printf("\nBefore ft_bzero(): %s\n", s);

	ft_bzero(s + 13, 8*sizeof(char));

	printf("After ft_bzero(): %s", s);
	return (0);
}
