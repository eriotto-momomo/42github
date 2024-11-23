#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int main(void)
{
    const char *s1;
    const char *s2;
    int result;

    s1 = "abcd";
    s2 = "abcd";
    result = ft_strncmp(s1, s2, 4);
    printf("1. La difference entre s1 et s2 est de: %d\n", result);

    s1 = "abcd";
    s2 = "abci";
    result = ft_strncmp(s1, s2, 4);
    printf("2. La difference entre s1 et s2 est de: %d\n", result);
    
    s1 = "abcd";
    s2 = "abc";
    result = ft_strncmp(s1, s2, 4);
    printf("3. La difference entre s1 et s2 est de: %d\n", result);
    
    s1 = "1234";
    s2 = "1234";
    result = ft_strncmp(s1, s2, 4);
    printf("4. La difference entre s1 et s2 est de: %d\n", result);
    
    s1 = "ab";
    s2 = "abcd";
    result = ft_strncmp(s1, s2, 4);
    printf("5. La difference entre s1 et s2 est de: %d\n", result);
    return (0);
}
