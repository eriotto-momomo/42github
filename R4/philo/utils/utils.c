/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:56:37 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 15:28:14 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dinner_is_done(t_philo *p)
{
	if (handle_mutex(&p->s->main_lock, LOCK) != 0)
		return (-1);
	if (*p->s->philo_died == true)
	{
		if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
			return (-1);
		return (1);
	}
	if (handle_mutex(&p->s->main_lock, UNLOCK) != 0)
		return (-1);
	if (p->meals_eaten == p->meals_toeat)
	{
		handle_mutex(&p->s->monitor_lock, LOCK);
		p->s->philos_full++;
		handle_mutex(&p->s->monitor_lock, UNLOCK);
		return (1);
	}
	return (0);
}

t_time get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday failed\n", 2);
	return (time.tv_sec * 1000ULL + time.tv_usec / 1000ULL); // en ms
}

int	ft_usleep(size_t milliseconds)
{
	t_time	now;

	now = get_time();
	while ((get_time() - now) < (milliseconds))
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
