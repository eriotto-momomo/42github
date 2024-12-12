#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // TO DELETE!!!
# include <fcntl.h> // TO DELETE!!!
# include <string.h> // TO DELETE!!!

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
