#include "get_next_line.h"

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

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
