/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:08 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/16 23:41:54 by emonacho         ###   ########.fr       */
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

// NOT WORKING
/*void	send_bits(char *str, pid_t server)
{
	int		i;
	int		bit;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		bit = 0;
		while (bit < CHAR_BIT)
		{
			g_ack = busy;
			if ((c >> bit) & 1)
				w_kill(server, SIGUSR1);
			else
				w_kill(server, SIGUSR2);
			while (g_ack == busy)
				usleep(50);
			bit++;
		}
		i++;
	}
}*/

// BACKUP
void	send_bits(char c, pid_t server)
{
	int	i;
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		g_ack = busy;
		if ((c >> bit) & 1)
			w_kill(server, SIGUSR1);
		else
			w_kill(server, SIGUSR2);
		while (g_ack == busy)
			usleep(50);
		bit++;
	}
}

// INSTALLER LES HANDLERS AVANT D'ENVOYER LES BITS!
int	main(int ac, char *av[])
{
	t_s		s;
	pid_t	server;
	int		i;

	if (ac != 3)
	{
		ft_putstr_fd("Error! Arguments must be server PID and message to send.\n", 2);
		exit(1);
	}
	server = check_pid(av[1]);
	s.msg_len = ft_strlen(av[2]);
	s.str_len = NULL;
	s.str_len = ft_itoa(s.msg_len);
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, end_handler);
	/*send_bits(s.str_len, server); // ?
	send_bits("\0", server); // ?
	ft_printf(".client | main | SENDING NULL TERMINATED\n");
	free(s.str_len); // ?
	send_bits(av[2], server); // ?
	send_bits("\0", server); // ?*/
	i = 0;
	while (s.str_len[i])
	{
		send_bits(s.str_len[i], server);
		printf("%d bits sent!\n", i + 1);
		i++;
	}
	send_bits('\0', server);
	ft_printf(".client | main | SENDING NULL TERMINATED\n");
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

// BACKUP
/*void	send_bits(char c, pid_t server)
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
			usleep(50);
		bit++;
	}
}*/
