#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // TO DELETE!!!
# include <fcntl.h> // TO DELETE!!!
# include <string.h> // TO DELETE!!!

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 1
#endif

#ifndef MAX_FD
# define MAX_FD 256
#endif

char 	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_checkc(char *s, int c);;
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
