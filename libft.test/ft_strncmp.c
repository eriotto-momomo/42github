#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;
    int j;
    const char *us1;
    const char *us2;

    i = 0;
    j = 0;
    us1 = s1;
    us2 = s2;
    while ((us1[i]) && (us2[j]) && (n-- > 0))
    {
        if (us1 != us2)
            return (us1 - us2);
        if (us1 == '\0')
            return (0);
        i++;
        j++;
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
    printf("La difference entre s1 et s2 est de: %d\n", result);
    return (0);
}
