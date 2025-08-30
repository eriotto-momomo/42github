/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:33:36 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/30 12:51:22 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	give_forks(t_philo *p)
{
	if (handle_mutex(&p->frst_fork->fork, UNLOCK) != 0)
	{
		if (handle_mutex(&p->scnd_fork->fork, UNLOCK) != 0)
			return (1);
		return (1);
	}
	if (handle_mutex(&p->scnd_fork->fork, UNLOCK) != 0)
		return (1);
	return (0);
}

//v.2
static int	choose_forks(t_philo *p, t_fork *first, t_fork *second)
{
	int	ret;

	ret = 0;
	if (handle_mutex(&first->fork, LOCK) != 0)
		return (1);
	if (print_philo(p, "has taken a fork", false) != 0)
		ret = 1;
	//if (dinner_is_done(p) != 0)
	//{
	//	if (handle_mutex(&first->fork, UNLOCK) != 0)
	//		return (1);
	//	return (1);
	//}
	if (!ret && handle_mutex(&second->fork, LOCK) != 0)
		ret = 1;
	if (!ret && dinner_is_done(p) != 0)
		ret = 1;
	if (!ret && print_philo(p, "has taken a fork", false) != 0)
		ret = 1;
	if (ret)
		give_forks(p);
	return (ret);
}

//v1
//static int	choose_forks(t_philo *p, t_fork *first, t_fork *second)
//{
//	int	ret;

//	ret = 0;
//	if (handle_mutex(&first->fork, LOCK) != 0)
//		return (1);
//	if (print_philo(p, "has taken a fork", false) != 0)
//	{
//		if (handle_mutex(&first->fork, UNLOCK) != 0)
//			return (1);
//		return (1);
//	}
//	if (dinner_is_done(p) != 0)
//	{
//		if (handle_mutex(&first->fork, UNLOCK) != 0)
//			return (1);
//		return (1);
//	}
//	if (handle_mutex(&second->fork, LOCK) != 0)
//	{
//		if (handle_mutex(&first->fork, UNLOCK) != 0)
//			return (1);
//		return (1);
//	}
//	if (print_philo(p, "has taken a fork", false) != 0)
//		return (give_forks(p), 1);
//	if (dinner_is_done(p) != 0)
//	{
//		if (give_forks(p) != 0)
//			return (1);
//		return (1);
//	}
//	return (0);
//}

int	pick_forks(t_philo *p)
{
	t_fork	*first;
	t_fork	*second;

	if (dinner_is_done(p) != 0)
		return (1);
	if (p->frst_fork < p->scnd_fork)
	{
		first = p->frst_fork;
		second = p->scnd_fork;
	}
	else
	{
		first = p->scnd_fork;
		second = p->frst_fork;
	}
	if (choose_forks(p, first, second) != 0)
		return (1);
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
