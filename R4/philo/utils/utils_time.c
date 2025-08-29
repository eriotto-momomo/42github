/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:56:37 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 19:13:15 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//bool	time_elapsed(int time_to_add, )

//int	ft_usleep(t_philo *p, int milliseconds)
//{
//	struct timeval	now;
//	int				elapsed_time;

//	elapsed_time = 0;
//	if (gettimeofday(&now, NULL) != 0)
//		return (-1);
//	while (elapsed_time < milliseconds)
//	{
//		if (elapsed_time < 0)
//			return (-1);
//		usleep(500);
//	}
//	return (0);
//}

int	get_time_ms(struct timeval ref_time)
{
	struct timeval	clock;
	long long		now;

	if (gettimeofday(&clock, NULL))
		return (-1);
	now = (clock.tv_usec - ref_time.tv_usec) / 1000;
	now += (clock.tv_sec - ref_time.tv_sec) * 1000;
	if (now > INT_MAX)
		return (-1);
	return ((int)now);
}
