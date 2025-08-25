/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:49:52 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/25 17:30:11 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	printf("%s----------------------%s\n", B, RST);
	printf("🧙🏻‍♂️Philo......ID: %s%d%s\n", Y, p->id, RST);
	printf("🍴First fork ID: %s%d%s\n🍴Secnd fork ID: %s%d%s\n", Y, p->frst_fork->id, RST, Y, p->scnd_fork->id, RST);
	printf("🍽️Meals eaten..: %s%d%s / %d\n", Y, p->meals_eaten, RST, p->s->in[MUST_EAT]);
	printf("%s----------------------%s\n", B, RST);
}
