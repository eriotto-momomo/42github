#include <stdio.h>
#include <stdlib.h>
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dst;
    size_t i;

    i = 0;
    if (s == 0)
        return (NULL);
	if (start > ft_strlen(s))
        return (ft_strdup(""));
    dst = (char *)malloc((len + 1) * sizeof(char));
    if (dst == 0)
        return (NULL);
    if (s != 0)
    {
        while (i < len)
        {
            dst[i] = s[start + i];
            i++;
        }
    }
    dst[i] = '\0';
    return (dst);
}

int main(void)
{
    char *result;
    char *s;

    s = "Hello World!";
    printf("Before ft_substr: %s\n", s);
    result = ft_substr(s, 3, 5);
    printf("After ft_substr: %s\n", result);

    return (0);
}
