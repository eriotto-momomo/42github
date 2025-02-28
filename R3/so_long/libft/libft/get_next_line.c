/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:29 by emonacho          #+#    #+#             */
/*   Updated: 2025/02/28 18:34:04 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>


// GNL - 2
/*char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	char	*s3;
	char	*p3;
	char	*p1;

	s3 = malloc (sizeof (*s3) * (ft_strlen (s1) + ft_strlen (s2) + 1));
	if (!s3)
	{
		free (s1);
		return (NULL);
	}
	p3 = s3;
	p1 = s1;
	while (*p1)
		*p3++ = *p1++;
	while (*s2)
		*p3++ = *s2++;
	*p3 = 0;
	free (s1);
	return (s3);
}

static char	*ft_next(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr (*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr (ptr, 0, ft_strlen (ptr));
	free (*temp);
	*temp = ptr;
	return (line);
}

static char	*ft_read(char *temp, int fd, char *buf, int buff_size)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr (temp, '\n'))
	{
		r = read (fd, buf, buff_size);
		if (r == -1)
		{
			free (buf);
			free (temp);
			return (NULL);
		}
		buf[r] = 0;
		temp = ft_strjoin_free_s1 (temp, buf);
		if (!temp)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[FOPEN_MAX];
	char		*buf;
	int			buff_size;

	buff_size = 100;
	if (fd == -1 || buff_size < 1)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	if (!temp[fd])
		return (NULL);
	buf = malloc (sizeof (*buf) * (buff_size + 1));
	if (!buf)
	{
		free (temp[fd]);
		return (NULL);
	}
	temp[fd] = ft_read (temp[fd], fd, buf, buff_size);
	if (!temp[fd])
		return (NULL);
	if (!*temp[fd])
	{
		free (temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&temp[fd]));
}*/

// GNL - 1
/*char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// delete line find
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

// take line for return
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// if no line return NULL
	if (!buffer[i])
		return (NULL);
	// go to the eol
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// malloc to eol
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if eol is \0 or \n, replace eol by \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res, int buff_size)
{
	char	*buffer;
	int		byte_read;

	// malloc if res dont exist
	if (!res)
		res = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(buff_size + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not eof read
		byte_read = read(fd, buffer, buff_size);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[byte_read] = 0;
		// join and free
		res = ft_free(res, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			buff_size;

	buff_size = 100;
	// error handling
	if (fd < 0 || buff_size <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer, buff_size);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}*/


// BACKUP V2
int	check_for_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

// Difference between 'remainder' and 'leftovers':
// - remainder: contains all the 'read' calls stored in the buffer
// until a full new 'line'('\n' or '\0' -terminated) is found.
// - leftovers: contains the remaining 'bytes' after truncating a full new
// 'line' from 'remainder'.
char	*save_leftovers(char *remainder)
{
	char	*leftovers;
	int		i;
	int		j;

	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	j = ft_strlen(remainder) - i;
	if (j <= 1 || remainder[i] == 0)
	{
		free(remainder);
		return (NULL);
	}
	leftovers = malloc((ft_strlen(remainder) - i) * sizeof(char));
	if (leftovers == 0)
		return (NULL);
	j = 0;
	while (remainder[i] != '\0')
	{
		leftovers[j] = remainder[i + 1];
		i++;
		j++;
	}
	free(remainder);
	return (leftovers);
}

char	*is_current_line(char *remainder)
{
	char	*current_line;
	int		i;

	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	current_line = malloc(sizeof(char) * (i + 2));
	if (current_line == 0)
		return (NULL);
	current_line[i + 1] = '\0';
	while (i >= 0)
	{
		current_line[i] = remainder[i];
		i--;
	}
	return (current_line);
}

static char	*read_and_store_fd(int fd, char *remainder, int buf_size, char *buffer)
{
	int		bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc((buf_size + 1) * sizeof(char));
	if (buffer == 0)
		return (NULL);
	while (bytes_read > 0 && check_for_next_line(remainder))
	{
		bytes_read = read(fd, buffer, buf_size);
		if (bytes_read == 0 && *remainder != 0)
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

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			buf_size;
	static char	*buffer;

	buf_size = 100;
	if (fd < 0 || buf_size <= 0)
		return (NULL);
	if (remainder == 0)
		remainder = ft_strdup("");
	remainder = read_and_store_fd(fd, remainder, buf_size, buffer);
	if (remainder == 0)
	{
		free(remainder);
		return (NULL);
	}
	line = is_current_line(remainder);
	remainder = save_leftovers(remainder);
	printf("remainder: '%s'\n", remainder);
	free(buffer);
	return (line);
}
