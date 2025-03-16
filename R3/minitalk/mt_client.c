/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:08 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/16 17:44:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = ready;

void	end_handler(int signal)
{
	ft_putstr_fd("Success! Message received.\n", 1);
	exit(0);
}

void	ack_handler(int signal)
{
	g_ack = ready;
	ft_printf(".client | ack_handler | g_ack = ready; | signal = %d\n", signal);
}

void	send_bits(char c, pid_t server)
{
	int				i;
	int				bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		g_ack = busy;
		if ((c >> bit) & 1)
			w_kill(server, SIGUSR1);
		else
			w_kill(server, SIGUSR2);
		while (g_ack == busy)
		{
			usleep(50);
			//ft_printf("BUSY!\n");
		}
		bit++;
	}
}

// INSTALLER LES HANDLERS AVANT D'ENVOYER LES BITS!
int	main(int ac, char *av[])
{
	pid_t	server;
	int		i;

	if (ac != 3)
	{
		if (ac < 3)
			ft_putstr_fd("Error! Too few arguments.\n", 2);
		else if (ac > 3)
			ft_putstr_fd("Error! Too many arguments.\n", 2);
		exit(1);
	}
	server = check_pid(av[1]);
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, end_handler);
	i = 0;
	while (av[2][i])
	{
		send_bits(av[2][i], server);
		i++;
	}
	send_bits('\0', server);
	ft_printf(".client | main | SENDING NULL TERMINATED\n");
	while(1)
		pause();
	return (0);
}
