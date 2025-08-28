/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:33:36 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/28 16:53:36 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//bool	is_prior(t_main *s, t_time time_to_check, int id)
//{
//	int		i;
//	t_time	time;
//	int		equal_times;
//	bool	is_prior;

//	time = time_to_check;
//	equal_times = 0;
//	is_prior = false;
//	i = 0;
//	fprintf(stderr, "❗️is_prior | time to check...: %llu | philo with id: %d check others\n", time_to_check, id);
//	while (i < s->in[N_PHILO])
//	{
//		fprintf(stderr, "⏰is_prior | p[%d]p->last_meal: %llu\n", s->philos[i].id, s->philos[i].last_meal);
//		if (s->philos[i].last_meal == time_to_check)
//			equal_times++;
//		if (time < s->philos[i].last_meal)
//			is_prior = true;
//		else
//			is_prior = false;
//		time = s->philos[i].last_meal;
//		i++;
//	}
//	if ((equal_times) == s->in[N_PHILO])
//		is_prior = true;
//	fprintf(stderr, "is_prior | equal_times: %d | is_prior: %d\n", equal_times, is_prior);
//	if (is_prior == true)
//		return (true);
//	return (false);
//}

void	pick_forks(t_philo *p)
{
	//	ft_usleep(1);					//TO DELETE ?
	if (p->id % 2 == 0)
	{
		handle_mutex(&p->scnd_fork->fork, LOCK);
		print_philo(p, "has taken a fork", false);
		handle_mutex(&p->frst_fork->fork, LOCK);
	}
	else
	{
		handle_mutex(&p->frst_fork->fork, LOCK);
		print_philo(p, "has taken a fork", false);
		handle_mutex(&p->scnd_fork->fork, LOCK);
	}
	//fprintf(stderr, "🔵 pick_forks | [%d] last_meal..........: %llu\n", p->id, p->last_meal - p->start_time); //🖨️❗️
	//fprintf(stderr, "🔵 pick_forks | [%d] now................: %llu\n", p->id, now - p->start_time); //🖨️❗️
	//fprintf(stderr, "🔵 pick_forks | [%d] now - last_meal....: %llu\n", p->id, now - p->last_meal); //🖨️❗️
	//fprintf(stderr, "🔵 pick_forks | [%d] starving_time......: %llu\n", p->id, p->starving_time - p->start_time); //🖨️❗️
	//fprintf(stderr, "🔵 pick_forks | [%d] now + wait.........: %llu\n", p->id, ((now - p->start_time) + p->s->wait_time)); //🖨️❗️
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
