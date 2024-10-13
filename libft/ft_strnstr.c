#include <libft.h>

char   *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (needle[0] == '\0') //si needle est une chaine vide
            return (haystack);
    while ((i < len) && (haystack[i] =! '\0'))
    {
        j = 0;
        while ((haystack[i + j] == needle[j]) && ((i + j) < len))
        {
            if (needle[j] == '\0')
                return ((char *)&haystack[i - j]);
            j++;
        }
        i++;
    }
    return (NULL); //si needle n'est pas trouve dans haystack
}
