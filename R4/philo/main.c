/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:19:15 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/27 08:25:44 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

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

int	main(int ac, char **av)
{
	t_main	*s;

	if (!(ac == 5 || ac == 6))
		return (ft_putstr_fd("Error: invalid number of arguments\n", 2), 1);
	s = malloc(sizeof(t_main));
	if (!s)
		return (ft_putstr_fd("Error: malloc failed", 2), 1);
	if (parse_input(ac, av, s) != 0)
	{
		free(s);
		return (1);
	}
	if (init_data(s) != 0)
		return (1);
	if (dinner(s) != 0)
	{
		clean_free(s);
		return (1);
	}
	clean_free(s);
	return (0);
}
