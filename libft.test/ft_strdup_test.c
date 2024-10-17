#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *ft_strdup(const char *s1)
{
    unsigned char *tmp;
    size_t i;
    int j;

    i = 0;
    j = 0;

    while (s1[j] != 0)
        j++;

    j += 1;

    tmp = malloc(sizeof *tmp * j);
    if (!tmp)
        return (NULL);
    while (s1[i])
    {
        tmp[i] = s1[i];
        i++;
    }
    return ((char *)tmp);

}

int main(void)
{
    char *s1;
    char *cpy;
    char *ptr;

    s1 = "Hello World!";
    cpy = ft_strdup(s1);
    ptr = cpy;
    while (*ptr != 0)
    {
        *ptr = toupper(*ptr);
        ptr++;
    }
    printf("%s\n", cpy);
    
    free (cpy);

    return (EXIT_SUCCESS);
}
