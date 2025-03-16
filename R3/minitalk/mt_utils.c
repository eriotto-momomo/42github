/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:04 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/16 23:41:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	initialize_struct(t_s *s)
{
	s->buffer = NULL;
	s->buff_size = 5;
	s->i = 0;
	s->c = 0;
	s->bit = 0;
	s->step = 0;
	s->msg_len = 0;
	s->client_pid = 0;
	return (1);
}

int	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_putstr_fd("Error! PID must be a digit.\n", 2);
			exit(1);
		}
		i++;
	}
	return (ft_atoi(pid));
}

/*void	w_signal(int signal, void (*handler)(int, siginfo_t *, void *))
{
	if (sigaction(signal, &sa, NULL) < 0)
	{
		ft_putstr_fd("Error! Sigaction failed.\n", 2);
		exit(1);
	}
}*/

// BACKUP
/*void	w_signal(int signal, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signal, &sa, NULL) < 0)
	{
		ft_putstr_fd("Error! Sigaction failed.\n", 2);
		exit(1);
	}
}*/

void	w_kill(pid_t pid, int signal)
{
	ft_printf(".utils | w_kill | Sendings bits | signal = %d\n", signal);
	if (kill(pid, signal) < 0)
	{
		ft_putstr_fd("Error! Function 'kill' failed.\n", 2);
		exit(1);
	}
}
