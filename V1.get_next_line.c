#include "get_next_line.h"

char *get_next_line(int fd);

char	*save_remainder(char *remainder)
{
	char	*str;
	int		i;
	int		j;

	i = check_for_next_line(remainder);
	//i = 0;
	j = 0;
	if (remainder[i] == NULL)
		{
			free(remainder);
			return (NULL);
		}
	str = malloc((ft_strlen(remainder) - i) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (remainder[j] != '\0')
	{
		str[j] = remainder[i + 1];
		i++;
		j++;
	}
	free(remainder);
	return (str);
}

char	*is_current_line(char *remainder)
{
	char	*current_line;
	int		i;
	int		j;

	i = check_for_next_line(remainder);
	//i = 0;
	//while (remainder[i] != '\0' && remainder[i] != '\n')
	//	i++;
	current_line = malloc(sizeof(char) * (i + 2));
	if (current_line == NULL)
		return (NULL);
	current_line[i + 1] = '\0';
	j = 0;
	while (j <= i)
	{
		current_line[j] = remainder[j];
		j++;
	}
	return (current_line);
}

int	check_for_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '\n')
			return (0);
		else
			return (i);
		i++;
	}
}

static char	*read_and_store_fd(int fd, char *remainder)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (bytes_read > 0 && check_for_next_line(remainder))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 && *remainder != NULL)
			break ;
		else if (bytes_read <= 0)
		{
			free(buffer);
			free(remainder);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

char *get_next_line(int fd)
{
	static char *remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (remainder == NULL)
		remainder = ft_strdup("");
	remainder = read_and_store_fd(fd, remainder);
	if (remainder == NULL)
		return (NULL);
	line = is_current_line(remainder);
	remainder = save_remainder(remainder);
	return (line);
}
