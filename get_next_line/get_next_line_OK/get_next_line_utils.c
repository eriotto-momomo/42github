#include "get_next_line.h"

size_t	ft_checkc(char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

size_t	ft_checkc(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (s1 == 0)
		return (NULL);
	dst = (char *) malloc(ft_strlen(s1) + 1);
	if (dst == 0)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	char		*new_s;

	s1_len = ft_strlen (s1);
	s2_len = ft_strlen (s2);
	new_s = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!new_s)
		return (0);
	ft_memcpy(new_s, s1, s1_len);
	ft_memcpy((new_s + s1_len), s2, s2_len);
	new_s[s1_len + s2_len] = '\0';
	free(s1);
	return (new_s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (0);
	if (src == dst)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
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
