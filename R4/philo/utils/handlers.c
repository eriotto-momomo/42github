/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:33:36 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/25 11:43:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	handle_thread(pthread_t *thread, t_routines mode, void *(*foo)(void *), void *data)
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
		return (ft_putstr_fd("Error: thread routine error\n", 2), 1);
	return (0);
}

int	handle_mutex(pthread_mutex_t *mutex, t_routines mode)
{
	int	ret;

	ret = 0;
	if (mode == INIT)
	{
		//printf("%shandle_mutex | mode = %d | INIT%s\n", B, mode, RST);
		ret = pthread_mutex_init(mutex, NULL);
	}
	else if (mode == DESTROY)
	{
		//printf("%shandle_mutex | mode = %d | DESTROY%s\n", B, mode, RST);
		ret = pthread_mutex_destroy(mutex);
	}
	else if (mode == LOCK)
	{
		//printf("%shandle_mutex | mode = %d | LOCK%s\n", B, mode, RST);
		ret = pthread_mutex_lock(mutex);
	}
	else if (mode == UNLOCK)
	{
		//printf("%shandle_mutex | mode = %d | UNLOCK%s\n", B, mode, RST);
		ret = pthread_mutex_unlock(mutex);
	}
	if (ret != 0)
		return (ft_putstr_fd("Error: mutex error\n", 2), 1);
	return (0);
}
