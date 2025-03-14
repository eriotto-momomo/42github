/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:08 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/14 23:50:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_server_state = busy;

void	end_handler(int signal)
{
	ft_putstr_fd("Success! Message received.\n", 1);
	exit(0); // useless?
}

void	ack_handler(int signal)
{
	g_server_state = ready;
}

void	send_bits(char c, pid_t server)
{
	int				i;
	int				bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if ((c >> bit) & 1)
			kill_wrap(server, SIGUSR1);
		else
			kill_wrap(server, SIGUSR2);
		usleep(50);
		bit++;
		//while (g_server_state == busy)
		//	usleep(50);
		//g_server_state = busy;
	}
}

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

	i = 0;
	while (av[2][i])
	{
		send_bits(av[2][i], server);
		i++;
	}
	send_bits('\n', server);
	//signal_wrap(SIGUSR1, ack_handler);
	signal_wrap(SIGUSR2, end_handler);
	return (0);
}
