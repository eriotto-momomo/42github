/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:50:17 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/25 11:42:51 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// return(1) = TRUE
// return(0) = FALSE
// return(-1)= ERROR
int	dinner_is_done(t_philo *p)
{
	if (p->meals_eaten == p->s->in[MUST_EAT])
		return (1);
	if (handle_mutex(&p->s->dead_lock, LOCK) != 0)
		return (-1);
	if (*p->s->philo_died == true)
	{
		if (handle_mutex(&p->s->dead_lock, UNLOCK) != 0)
			return (-1);
		return (1);
	}
	if (handle_mutex(&p->s->dead_lock, UNLOCK) != 0)
			return (-1);
	if ((get_time() - p->last_meal) > p->tto_die)
	{
		print_philo(p, "died", true);
		return (1);
	}
	return (0);
}

static int	big_dinner(t_philo *p)
{
	int	ret;

	while (1)
	{
		ret = dinner_is_done(p);
		if (ret == 1)
			break ;
		else if (ret == -1)
			return (1);
		philo_eat(p);
		philo_sleep(p);
		philo_think(p);
		//ft_usleep(100);
	}
	return (0);
}

static int	solo_dinner(t_philo *p)
{
	int	ret;

	printf("%ssolo_dinner | START%s\n", Y, RST); //🖨️❗️
	ret = dinner_is_done(p);
	if (ret == 0)
	{
		if (handle_mutex(&p->frst_fork->fork, LOCK) != 0)
			return (1);
		print_philo(p, "has taken a fork", false);
		while (1)
		{
			if (ret == 1)
			{
				printf("%ssolo_dinner | BREAK‼️%s\n", Y, RST); //🖨️❗️
				break ;
			}
			else if (ret == -1)
				return (1);
			ret = dinner_is_done(p);
		}
		if (handle_mutex(&p->frst_fork->fork, UNLOCK) != 0)
			return (1);
	}
	else if (ret == -1)
		return (1);
	printf("%ssolo_dinner | END%s\n", Y, RST); //🖨️❗️
	return (0);
}

void	*start_dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	//////////////////////////////////
	//helper_print_philo(philo); //🖨️❗️
	//////////////////////////////////
	if (philo->s->in[N_PHILO] == 1)
		solo_dinner(philo);
	else
		big_dinner(philo);
	return (NULL);
}

int	dinner(t_main *s)
{
	int	i;

	i = -1;
	while (++i < s->in[N_PHILO])
	{
		if (handle_thread(&s->philos[i].thread, CREATE, start_dinner, &s->philos[i]) != 0)
			return (1);
		//ft_usleep(100);
		usleep(300);
	}
	if (dinner_is_done(&s->philos[0]) == 1)
		return (0);
	else if (dinner_is_done(&s->philos[0]) == -1)
		return (1);
	i = -1;
	while (++i < s->in[N_PHILO]) // USELESS ⁉️
	{
		if (handle_thread(&s->philos[i].thread, JOIN, NULL, NULL) != 0)
			return (1);
	}
	printf("%s✅ dinner | DINNER FINISHED! 🍽️%s\n", Y, RST); //🖨️❗️
	return (0);
}
