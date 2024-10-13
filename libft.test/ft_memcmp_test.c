#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const unsigned char *us1;
    const unsigned char *us2;

    i = 0;
    us1 = s1;
    us2 = s2;
    while ((i < n) && (us1[i] == us2[i]))
        i++;
    if (i == n)
        return (0); 
    return (us1[i] - us2[i]);
}

int main(void)
{
    const char *s1;
    const char *s2;
    int result;

    s1 = "abcd";
    s2 = "abcd";
    result = ft_memcmp(s1, s2, 4);
    printf("1. La difference entre s1 et s2 est de: %d\n", result);

    s1 = "abcd";
    s2 = "abci";
    result =  ft_memcmp(s1, s2, 4);
    printf("2. La difference entre s1 et s2 est de: %d\n", result);
    
    s1 = "abcd";
    s2 = "abc";
    result = ft_memcmp(s1, s2, 4);
    printf("3. La difference entre s1 et s2 est de: %d\n", result);
    
    s1 = "abc";
    s2 = "abcd";
    result =  ft_memcmp(s1, s2, 4);
    printf("4. La difference entre s1 et s2 est de: %d\n", result);
    
    s1 = "ab";
    s2 = "abcd";
    result =  ft_memcmp(s1, s2, 4);
    printf("5. La difference entre s1 et s2 est de: %d\n", result);
    return (0);
}
