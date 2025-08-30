/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:56:37 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/30 12:52:36 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_time_ms(struct timeval ref_time)
{
	struct timeval	clock;
	long long		now;

	if (gettimeofday(&clock, NULL))
		return (-1);
	now = (clock.tv_usec - ref_time.tv_usec) / 1000;
	now += (clock.tv_sec - ref_time.tv_sec) * 1000;
	if (now > INT_MAX)
		return (-1);
	return ((int)now);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
