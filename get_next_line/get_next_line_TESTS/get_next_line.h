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

char 	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
