#include <stdio.h>
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while ((n > 0) && (s1[i] != '\0') && (s1[i] == s2[j]))
    {
        i++;
        j++;
        n--;
    }
    if (n == 0)
        return (0);
    else
        return (s1[i] - s2[j]);
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
    
    s1 = "abc";
    s2 = "abcd";
    result = ft_strncmp(s1, s2, 4);
    printf("4. La difference entre s1 et s2 est de: %d\n", result);
    
    s1 = "ab";
    s2 = "abcd";
    result = ft_strncmp(s1, s2, 4);
    printf("5. La difference entre s1 et s2 est de: %d\n", result);
    return (0);
}
