/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:29 by emonacho          #+#    #+#             */
/*   Updated: 2024/12/21 17:47:23 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (remainder[i] == 0)
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

static char	*read_and_store_fd(int fd, char *remainder)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == 0)
		return (NULL);
	while (bytes_read > 0 && check_for_next_line(remainder))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder == 0)
		remainder = ft_strdup("");
	remainder = read_and_store_fd(fd, remainder);
	if (remainder == 0)
		return (NULL);
	line = is_current_line(remainder);
	remainder = save_leftovers(remainder);
	return (line);
}
