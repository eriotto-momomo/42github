#include <stdio.h>
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;
	unsigned char	cc;

	i = 0;
	res = 0;
	cc = (unsigned char)c;
	while (s[i])
	{
		if ((unsigned char)s[i] == cc)
			res = ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == cc)
		res = ((char *)&s[i]);
	return (res);
}

int main(void)
{
    const char *result;

    result = ft_strrchr("teste", 1024);
    printf("ft_strrchr: %p \n", result);
    return (0);
}
