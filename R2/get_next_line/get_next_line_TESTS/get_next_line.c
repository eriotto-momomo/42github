/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:29 by emonacho          #+#    #+#             */
/*   Updated: 2024/12/21 17:25:56 by emonacho         ###   ########.fr       */
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
// - remainder: until a full new 'line'('\n' or '\0' -terminated) is found,
// contains all the 'read' calls stored in the buffer.
// - leftovers: take the remaining 'bytes' after truncating a full new 'line'
// and store them in 'remainder'.
// As 'read' could read past '\n', (depending 'fd' content and 'BUFFER_SIZE')
// we need to store the 'leftovers' to preserve what has already been 'read'
// for the next line in future function calls.
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

// When allocating 'current_line' (i + 2), 'i' represents the last character
// before '\n', '+1' accounts for the '\n', and the final '+1' reserves space
// for the '\0'.
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

// The result of 'read' is stored in 'buffer' and saved in 'remainder',
// and then joined together to form the next complete 'line' as long as:
// - 'fd' contains bytes left to read
// - 'remainder' doesn't contain a '\n' or '\0'
// If an error occurs during 'read', 'bytes_read' becomes negative. In that case
// all the dynamically allocated memory will be freed and 'NULL' returned.
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

//This function reads a file from 'fd' and return a full line up to '\n' or '\0'
// 1. If 'remainder' isn't already used, it's initialised with 'ft_strdup'
// 2. The result of 'read(fd, buffer, BUFFER_SIZE)' is stored into 'remainder'
// until the 'fd' is fully read (no bytes left), or if a '\n' or '\0' is found.
// 3. The 'line' to return is extracted from 'remainder' up to the first '\n' or
// '\0' encountered.
// 4. The extra bytes left into 'remainder' are stored in the static variable,
// and will be reused at next function call to constitue the next 'line'.
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
