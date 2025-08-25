/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:49:52 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/25 11:34:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	helper_print_philo(t_philo *p)
{
	printf("🧙🏻‍♂️Philo......ID: %d\n", p->id);
	printf("🍴First fork ID: %d\n🍴Secnd fork ID: %d\n", p->frst_fork->id, p->scnd_fork->id);
	printf("🍽️Meals eaten..: %s%d%s / %d\n", Y, p->meals_eaten, RST, p->s->in[MUST_EAT]);
	if (*p->s->philo_died == true)
		printf("☠️Philo died...: %strue%s\n", G, RST);
	else if (*p->s->philo_died == false)
		printf("☠️Philo died...: %sfalse%s\n", P, RST);
	printf("%s-------------------%s\n", B, RST);
}
