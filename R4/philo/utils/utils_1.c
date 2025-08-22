/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:56:37 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/22 10:32:22 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_forks(t_main *s, t_fork *forks, t_philo *p)
{
	if (p->id % 2 == 0)
	{
		p->frst_fork = &forks[(p->id + 1) % s->in[N_PHILO]].fork;
		p->scnd_fork = &forks[p->id].fork;
	}
	else
	{
		p->frst_fork = &forks[p->id].fork;
		p->scnd_fork = &forks[(p->id + 1) % s->in[N_PHILO]].fork;
	}
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday failed\n", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

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
