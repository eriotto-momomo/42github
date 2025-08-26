/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:19:15 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/26 19:08:30 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

# define R "\033[1;31m" //🖨️❗️
# define G "\033[1;32m" //🖨️❗️
# define Y "\033[1;33m" //🖨️❗️
# define B "\033[1;34m" //🖨️❗️
# define P "\033[1;35m" //🖨️❗️
# define C "\033[1;36m" //🖨️❗️
# define RST "\033[0m" //🖨️❗️

void	helper_print_data(t_main *s)
{
	handle_mutex(&s->main_lock, LOCK);
	fprintf(stderr, "%s-------------------%s\n", G, RST); //🖨️❗️
	fprintf(stderr, "🧙🏻‍♂️N_PHILO: %d\n", s->in[N_PHILO]); //🖨️❗️
	fprintf(stderr, "☠️TTO_DIE: %d\n", s->in[TTO_DIE]); //🖨️❗️
	fprintf(stderr, "⏰TTO_EAT: %d\n", s->in[TTO_EAT]); //🖨️❗️
	fprintf(stderr, "💤TTO_SLP: %d\n", s->in[TTO_SLEEP]); //🖨️❗️
	fprintf(stderr, "🍝MST_EAT: %d\n",s->in[MUST_EAT]); //🖨️❗️
	fprintf(stderr, "PHIL_INIT: %d\n", s->philos_init); //🖨️❗️
	fprintf(stderr, "%s-------------------%s\n", G, RST); //🖨️❗️
	handle_mutex(&s->main_lock, UNLOCK);
}

void	helper_print_philo(t_philo *p)
{
	handle_mutex(&p->s->main_lock, LOCK);
	fprintf(stderr, "%s----------------------%s\n", B, RST); //🖨️❗️
	fprintf(stderr, "🧙🏻‍♂️Philo......ID: %s%d%s\n", Y, p->id, RST); //🖨️❗️
	fprintf(stderr, "🍴First fork ID: %s%d%s\n🍴Secnd fork ID: %s%d%s\n", Y, p->frst_fork->id, RST, Y, p->scnd_fork->id, RST); //🖨️❗️
	fprintf(stderr, "🍽️Meals eaten..: %s%d%s / %d\n", Y, p->meals_eaten, RST, p->s->in[MUST_EAT]); //🖨️❗️
	fprintf(stderr, "%s----------------------%s\n", B, RST); //🖨️❗️
	handle_mutex(&p->s->main_lock, UNLOCK);
}

/*
*	TESTS
*	4 310 200 100 (one should die)
*	4 410 200 200 (no one should die)
*	5 800 200 200 (no one should die)
*	5 800 200 200 7 (no one should die and every philo eats 7 times)
*
*	valgrind --tool=helgrind
*	valgrind --tool=drd --read-var-info=yes
*/

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
