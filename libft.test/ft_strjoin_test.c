#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
    char *cat;
    int i;
    int j;

    i = 0;
    j = 0;
    cat = (char *)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
    if (cat == 0)
        return (NULL);
    while (s1[i])
        cat[j++] = s1[i++];
    i = 0;
    while (s2[i])
        cat[j++] = s2[i++];
    cat[j] = '\0';
    return (cat);
}

int main(void)
{
    char *s1;
    char *s2;
    char *result;

    s1 = "Hello ";
    s2 = "World!";
    printf("The first string is: %s\n", s1);
    printf("The second string is: %s\n", s2);
    result = ft_strjoin(s1, s2);
    printf("The result after ft_strjoin is: %s\n", result);

    return (0);
}
