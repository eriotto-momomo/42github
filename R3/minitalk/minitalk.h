/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/14 23:50:22 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>

enum e_state
{
	ready,
	busy,
};

int		check_pid(char *pid);
void	kill_wrap(pid_t pid, int signal);
void	signal_wrap(int signal, void (*handler)(int));

#endif
