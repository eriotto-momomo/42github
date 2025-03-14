/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:04 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/14 23:50:21 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	signal_wrap(int signal, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signal, &sa, NULL) < 0)
	{
		ft_putstr_fd("Error! Sigaction failed.\n", 2);
		exit(1);
	}
}

void	kill_wrap(pid_t pid, int signal)
{
	if(kill(pid, signal) < 0)
	{
		ft_putstr_fd("Error! Function 'kill' failed.\n", 2);
		exit(1);
	}
}
