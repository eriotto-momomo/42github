/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:33:36 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 14:13:10 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int choose_forks(t_philo *p, t_fork *first, t_fork *second)
{
	handle_mutex(&first->fork, LOCK);
	print_philo(p, "has taken a fork", false);
	if (dinner_is_done(p) != 0)
	{
		handle_mutex(&first->fork, UNLOCK);
		return (1);
	}
	handle_mutex(&second->fork, LOCK);
	print_philo(p, "has taken a fork", false);
	if (dinner_is_done(p) != 0)
	{
		handle_mutex(&first->fork, UNLOCK);
		handle_mutex(&second->fork, UNLOCK);
		return (1);
	}
	return (0);
}

int	pick_forks(t_philo *p)
{
	if (dinner_is_done(p) != 0)
		return (1);
	if (p->id % 2 == 0)
	{
		if (choose_forks(p, p->scnd_fork, p->frst_fork) != 0)
			return (1);
	}
	else
	{
		if (choose_forks(p, p->frst_fork, p->scnd_fork) != 0)
			return (1);
	}
	return (0);
}

int	handle_thread(pthread_t *thread, t_routines mode,
		void *(*foo)(void *), void *data)
{
	int	ret;

	ret = 0;
	if (mode == CREATE)
		ret = pthread_create(thread, NULL, foo, data);
	else if (mode == DETACH)
		ret = pthread_detach(*thread);
	else if (mode == JOIN)
		ret = pthread_join(*thread, NULL);
	if (ret != 0)
		return (ft_putstr_fd("Error: thread error\n", 2), 1);
	return (0);
}

int	handle_mutex(pthread_mutex_t *mutex, t_routines mode)
{
	int	ret;

	ret = 0;
	if (mode == INIT)
		ret = pthread_mutex_init(mutex, NULL);
	else if (mode == DESTROY)
		ret = pthread_mutex_destroy(mutex);
	else if (mode == LOCK)
		ret = pthread_mutex_lock(mutex);
	else if (mode == UNLOCK)
		ret = pthread_mutex_unlock(mutex);
	if (ret != 0)
		return (ft_putstr_fd("Error: mutex error\n", 2), 1);
	return (0);
}
