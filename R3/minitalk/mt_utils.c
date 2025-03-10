/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:04 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/10 19:54:44 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_wrap(int signal, void *handler, bool use_siginfo) // ..., int bool)???
{
	struct sigaction	sa = {0};

	// PUT THE HANDLER FUNCTION IN SIGACTION
	if (use_siginfo) // if (1)???
	{
		sa.sa_flags = SA_SIGINFO; // but du flag?
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;

	// MASKS, BLOCK SIGUSR1 WHILE PROCESSING SIGUSR2 AND VICE VERSA
	sigemptyset(&sa.sa_mask); // clean tout en initialisant a 0
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	// CALL SIGACTION
	if (sigaction(signal, &sa, NULL) < 0) // troisieme arg utile pour noter l'erreur
	{
		ft_putstr_fd("Sigaction failed.\n", 2);
		exit(1);
	}
	else
		ft_printf("Success! Message sent.\n");

}
