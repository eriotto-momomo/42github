/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:56:37 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/26 18:56:21 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	quit_dinner(t_philo *p)
{
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (-1);
	return (1);
}

t_time	get_time(void)
{
	struct timeval	time;
	t_time			ret;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday failed\n", 2);
	ret = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret);
}

int	ft_usleep(size_t milliseconds)
{
	t_time	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
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
