/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:47 by emonacho          #+#    #+#             */
/*   Updated: 2024/12/21 17:47:14 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 42
# endif

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
