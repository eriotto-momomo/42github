/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/16 17:44:43 by emonacho         ###   ########.fr       */
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
	busy,
	ready,
}	t_state;

typedef struct s_minitalk
{
	char	*buffer;
	int		i;
	int		c;
	int		bit;
	int		step;
	int		msg_len;
	pid_t	client_pid;
}			t_s;

int		initialize_struct(t_s *s);
int		check_pid(char *pid);
void	w_kill(pid_t pid, int signal);
void	w_signal(int signal, void (*handler)(int, siginfo_t *, void *));

#endif
