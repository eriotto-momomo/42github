/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:10 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/16 17:44:50 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_init = 0;

void	fill_buffer(t_s *s)
{
	s->buffer[s->i] = s->c;
	(s->i)++;
	ft_printf("s->i = %d || s->msg_len = %d\n", s->i, s->msg_len);
	if (s->i != s->msg_len)
		ft_printf(".server | fill_buffer | FILLING BUFFER\n");
	//if (s->i == s->msg_len)
	if (s->c == '\0')
	{
		s->buffer[s->msg_len] = '\0';
		ft_printf(".server | fill_buffer | BUFFER IS FULL! = [%s]\n", s->buffer);
		write(1, s->buffer, s->msg_len);
		write(1, "\n", 1);
		free(s->buffer);
		s->buffer = NULL;
		w_kill(s->client_pid, SIGUSR2);
		is_init = 0;
		//s->step = 0;
	}
}

int	msg_is_valid(t_s *s)
{
	s->msg_len = s->c;
	if (s->msg_len <= 0 || s->msg_len > 1024)
	{
		ft_putstr_fd("Error! Message too long.\n", 2);
		return (0);
	}
	ft_printf(".server | msg_is_valid | s->msg_len = %d]\n", s->msg_len);
	s->buffer = malloc(sizeof(char) * s->msg_len + 1);
	if (s->buffer == NULL)
		exit(1);
	ft_printf(".server | msg_is_valid | c = %c\n", s->c);
	s->buffer[0] = s->c;
	s->i = 1;
	ft_printf(".server | msg_is_valid | BUFFER CREATED[s->msg_len + 1 = %d]\n", s->msg_len + 1);
	return (1);
}

void	bit_decoder(int signal, t_s *s)
{
	if (signal == SIGUSR1)
		s->c |= (1 << s->bit);
	else if (signal == SIGUSR2)
		s->c &= ~(1 << s->bit);
	(s->bit)++;
}

void	msg_handler(int signal, siginfo_t *info, void *more_info)
{
	static t_s	s;

	//ft_printf("msg_handler/ Signal incoming!\n");
	(void)more_info;
	if (is_init == 0)		// GLOBAL VARIABLE
		is_init = initialize_struct(&s);
	if (s.client_pid == 0)
		s.client_pid = info->si_pid;
	//ft_printf("Client PID = %d\n", s.client_pid);
	//ft_printf("Received signal: %d, current bit: %d\n", signal, s.bit);
	bit_decoder(signal, &s);
	//ft_printf("After decoding: char = %c (%d), bit = %d\n", s.c, s.c, s.bit);
	w_kill(s.client_pid, SIGUSR1);
	//ft_printf("Send ack = ready to client\n");
	if (s.bit == CHAR_BIT)
	{
		ft_printf(".server | msg_handler | CHARACTER COMPLETED, c = %c\n", s.c);
		s.bit = 0;
		if (!s.step)
		{
			if (!msg_is_valid(&s))
				exit(1);
			s.step = 1;
		}
		else if(s.step)
			fill_buffer(&s);
		s.c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("SERVER PID=%d\n", pid);
	sa.sa_sigaction = msg_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
	/*if (sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		ft_putstr_fd("Error! Sigaction failed.\n", 2);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
	{
		ft_putstr_fd("Error! Sigaction failed.\n", 2);
		exit(1);
	}*/
	while(1)
		pause();
	return (0);
}

// BACKUP
/*int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID=%d\n", pid);
	while(1)
	{
		w_signal(SIGUSR1, msg_handler);
		w_signal(SIGUSR2, msg_handler);
		pause();
	}
	return (0);
}*/
