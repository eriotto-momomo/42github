/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:56:37 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 18:58:14 by emonacho         ###   ########.fr       */
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
