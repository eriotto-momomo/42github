/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:29 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/01 12:15:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
char	*save_leftovers(t_gnl *s, char *remainder)
{
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
	s->leftovers = malloc(j * sizeof(char));
	if (s->leftovers == 0)
		return (NULL);
	j = 0;
	while (remainder[i] != '\0')
	{
		s->leftovers[j] = remainder[i + 1];
		i++;
		j++;
	}
	free(remainder);
	return (s->leftovers);
}

void	is_current_line(t_gnl *s, char *remainder)
{
	int		i;

	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	s->current_line = malloc(sizeof(char) * (i + 2));
	if (s->current_line == 0)
	{
		s->current_line = NULL;
		return ;
	}
	s->current_line[i + 1] = '\0';
	while (i >= 0)
	{
		s->current_line[i] = remainder[i];
		i--;
	}
}

static char	*read_and_store_fd(t_gnl *s, char *remainder, int fd)
{
	s->bytes_read = 1;
	s->buffer = (char *)malloc((s->buf_size + 1) * sizeof(char));
	if (s->buffer == 0)
		return (NULL);
	while (s->bytes_read > 0 && check_for_next_line(remainder))
	{
		s->bytes_read = read(fd, s->buffer, s->buf_size);
		if (s->bytes_read == 0 && *remainder != 0)
			break ;
		else if (s->bytes_read <= 0)
		{
			free(s->buffer);
			free(remainder);
			return (NULL);
		}
		s->buffer[s->bytes_read] = '\0';
		remainder = ft_strjoin(remainder, s->buffer);
	}
	free(s->buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	t_gnl		s;

	s.buf_size = 100;
	if (fd == -1)
	{
		if (remainder)
			free(remainder);
		return (NULL);
	}
	else if (fd < -1)
		return (NULL);
	if (remainder == 0)
		remainder = ft_strdup("");
	remainder = read_and_store_fd(&s, remainder, fd);
	if (remainder == 0)
		return (NULL);
	is_current_line(&s, remainder);
	if (s.current_line == NULL)
	{
		free(remainder);
		return (NULL);
	}
	remainder = save_leftovers(&s, remainder);
	return (s.current_line);
}
