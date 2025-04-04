
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (s1 == 0)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s1) + 1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_s;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!new_s)
		return (0);
	ft_memcpy(new_s, s1, s1_len);
	ft_memcpy((new_s + s1_len), s2, s2_len);
	new_s[s1_len + s2_len] = '\0';
	free(s1);
	return (new_s);
}

char	*read_and_store_fd(int fd, char *line, int buff_size)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * buff_size + 1);
	if (buffer == NULL)
	{
		printf("Error! Memory allocation failed.\n");
		exit(1);
	}
	///////////////////////////////////////
	line = NULL;
	printf("%s", line);
	while (bytes_read > 0)
	{
		/*printf("read_and_store_fd | buff_size: %d | bytes_read: %d | fd:
			%d\n",
			buff_size, bytes_read, fd);*/
		bytes_read = read(fd, buffer, bytes_read);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (buffer[0] == '\0' || buffer[0] == '\n')
		{
			printf("read_and_store_fd | read-loop-stopper / buffer: %s\n",
				buffer);
			break ;
		}
		printf("read_and_store_fd | read-loop / buffer: %s\n", buffer);
	}
	printf("read_and_store_fd | buff_size: %d | bytes_read: %d | fd: %d\n",
		buff_size, bytes_read, fd);
	///////////////////////////////////////
	if (bytes_read < 0)
	{
		printf("Error! Reading file.\n");
		free(buffer);
		exit(1);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int			buff_size;

	if (line == NULL)
		line = ft_strdup("");
	buff_size = 10;
	line = read_and_store_fd(fd, line, buff_size);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	// int		i;
	line = NULL;
	fd = open("sample.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error! Opening file.\n");
		exit(1);
	}
	else
		printf("main | fd: %d\n", fd);
	line = get_next_line(fd);
	printf("Line[%d]: %s\n", 1, line);
	/*i = 1;
	while (line)
	{
		line = get_next_line(fd);
		printf("Line[%d]: %s\n", i, line);
		free(line);
		line = NULL;
		i++;
	}*/
	close(fd);
	if (line != NULL)
		free(line);
	return (0);
}
