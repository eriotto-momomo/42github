/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:49:52 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 22:34:50 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define P "\033[1;35m"
# define C "\033[1;36m"
# define RST "\033[0m"

void	helper_print_data(t_main *s)
{
	//(void)s;
	printf("%s-------------------%s\n", G, RST); //🖨️❗️
	printf("🧙🏻‍♂️N_PHILO: %d\n", s->in[N_PHILO]); //🖨️❗️
	printf("☠️TTO_DIE: %d\n", s->in[TTO_DIE]); //🖨️❗️
	printf("⏰TTO_EAT: %d\n", s->in[TTO_EAT]); //🖨️❗️
	printf("💤TTO_SLP: %d\n", s->in[TTO_SLEEP]); //🖨️❗️
	printf("🍝MST_EAT: %d\n",s->in[MUST_EAT]); //🖨️❗️
	printf("PHIL_INIT: %d\n", s->philos_init); //🖨️❗️
	printf("%s-------------------%s\n", G, RST); //🖨️❗️
}

void	helper_print_philo(t_philo *p)
{
	printf("%s----------------------%s\n", B, RST); //🖨️❗️
	printf("🧙🏻‍♂️Philo......ID: %s%d%s\n", Y, p->id, RST); //🖨️❗️
	printf("🍝Active philos: %s%d%s\n", Y, p->s->active_philos, RST); //🖨️❗️
	printf("🍴First fork ID: %s%d%s\n🍴Secnd fork ID: %s%d%s\n", Y, p->frst_fork->id, RST, Y, p->scnd_fork->id, RST); //🖨️❗️
	printf("🍽️Meals eaten..: %s%d%s / %d\n", Y, p->meals_eaten, RST, p->s->in[MUST_EAT]); //🖨️❗️
	printf("%s----------------------%s\n", B, RST); //🖨️❗️
}
