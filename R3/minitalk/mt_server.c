/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:10 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/10 19:54:26 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *info, void *more_info)
{
	(void)more_info; // inutile dans minitalk, quel usage normalement?

	//write(STDOUT_FILENO, "Hello", 5);
}

int	main(void)
{
	ft_printf("SERVER PID=%d\n", getpid()); // print macos

	signal_wrap(SIGUSR1, handler, true); // ..., 1)???
	signal_wrap(SIGUSR2, handler, true); // ..., 1)???

	while(1337) // (1)???
		pause();

	return (0);
}
