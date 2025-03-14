/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:10 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/14 23:50:17 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	hndl_msg(int signal)
{
	static int	bit;
	static int	c;
	pid_t	client;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	else if (signal == SIGUSR2)
		c &= ~(1 << bit);
		//c &= (1 >> bit); // Pourquoi ne marche pas?
	++bit;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (c == '\0') // WIP
		{
			kill(client, SIGUSR2); //
			return ;
		} // WIP
		write(1, &c, 1);
		c = 0;
	}
	//kill(client, SIGUSR1); // ack_handler
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID=%d\n", pid);
	signal_wrap(SIGUSR1, hndl_msg);
	signal_wrap(SIGUSR2, hndl_msg);
	while(1)
		pause();
	return (0);
}
