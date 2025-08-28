/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:33:36 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/28 22:04:56 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pick_forks(t_philo *p)
{
	//while (p->is_prior == false)
	//	usleep(100);
	if (p->id % 2 == 0)
	{
		handle_mutex(&p->scnd_fork->fork, LOCK);
		print_philo(p, "has taken a fork", false);
		if (dinner_is_done(p) == 1)
			return ;
		handle_mutex(&p->frst_fork->fork, LOCK);
	}
	else
	{
		handle_mutex(&p->frst_fork->fork, LOCK);
		print_philo(p, "has taken a fork", false);
		if (dinner_is_done(p) == 1)
			return ;
		handle_mutex(&p->scnd_fork->fork, LOCK);
	}
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
