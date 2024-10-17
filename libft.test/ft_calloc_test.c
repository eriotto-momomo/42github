#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void   *ft_calloc(size_t count, size_t size)
{
    unsigned char *tmp;
    size_t i;

    tmp = malloc(count * size);
    i = 0;
    if (tmp == 0)
        return (NULL);
    while (i < count * size)
    {
        tmp[i] = 0;
        i++;
    }
    return (tmp);
}

#define INT_NUMBER 12

int main(void)
{
    int i;

    i = 0;
    int * ptr = (int *) ft_calloc(INT_NUMBER, sizeof(int));

    assert( ptr != NULL );
    
    for (i = 0; i < INT_NUMBER-1; i++ )
    {
        ptr[i] = i;
    }

    for (i = 0; i < INT_NUMBER; i++ )
    {
        printf("%d", ptr[i]);
    }
    printf("\n");

    free (ptr);
    return (0);
}
/* calloc alloue continuellement assez d'espace pour
 * 'count' objets, qui sont chacun de 'size' bytes de
 * memoire chacun et retourne un *ptr a la memoire
 * allouee. La memoire allouee est remplie de bytes
 * de valeur zero.
 */
/*
 *
 */
