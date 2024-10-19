#include <stdio.h>
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;
	char	cc;

	i = 0;
	res = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			res = ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		res = ((char *)&s[i]);
	return (res);
}

int main(void)
{
    const char *s;
    int c;
    char *result;

    s = "Hello World!";
    c = '!';
    printf("Before ft_strrchr: %s \n", s);
    result = ft_strrchr(s, c);
    printf("After ft_strrchr: %s \n", result);
    return (0);
}
