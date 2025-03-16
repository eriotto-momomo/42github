/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:10 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/16 23:41:53 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_init = 0;

void	fill_buffer(t_s *s)
{
	s->buffer[s->i] = s->c;
	(s->i)++;
	ft_printf("s->i = %d || s->msg_len = %d\n", s->i, s->msg_len);
	if (s->i < s->msg_len)
		ft_printf(".server | fill_buffer | FILLING BUFFER\n");
	//if (s->i == s->msg_len)
	if (s->c == '\0')
	{
		s->buffer[s->msg_len] = '\0';
		ft_printf(".server | fill_buffer | BUFFER IS FULL! = [%s]\n", s->buffer);
		if (s->buff_size == 5)
		{
			s->buff_size = ft_atoi(s->buffer);
			ft_printf(".server | fill_buffer | s->buff_size = %d\n", s->buff_size);
		}
		else if (s->buff_size != 0) //TODO: comment faire pour sauter cette condition après avoir initialisé buff_size?
		{
			write(1, s->buffer, s->msg_len);
			write(1, "\n", 1);
			ft_printf("||||||||||||||||| PRINT BUFFER |||||||||||||||||");
		}
		free(s->buffer);
		s->buffer = NULL;
		w_kill(s->client_pid, SIGUSR2);
		is_init = 0;
	}
}

int	msg_is_valid(t_s *s)
{
	s->msg_len = s->c;
	//if (s->msg_len <= 0 || s->msg_len > 4096)
	if (s->msg_len <= 0 || s->msg_len > 4096)
	{
		ft_putstr_fd("Error! Message too long.\n", 2);
		return (0);
	}
	ft_printf(".server | msg_is_valid | s->msg_len = %d]\n", s->msg_len);
	if (s->buff_size != 0)
		s->buffer = malloc(sizeof(char) * s->buff_size + 1);
	else
		s->buffer = ft_calloc(sizeof(char), s->buff_size);
		//s->buffer = malloc(sizeof(char) * 5);
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

	//ft_printf("Client PID = %d\n", s.client_pid);
	//ft_printf("Received signal: %d, current bit: %d\n", signal, s.bit);
	//ft_printf("After decoding: char = %c (%d), bit = %d\n", s.c, s.c, s.bit);
	//ft_printf(".server | msg_handler | CHARACTER COMPLETED, c = %c\n", s.c);

void	msg_handler(int signal, siginfo_t *info, void *more_info)
{
	static t_s	s;

	(void)more_info;
	if (is_init == 0)		// GLOBAL VARIABLE
		is_init = initialize_struct(&s);
	if (s.client_pid == 0)
		s.client_pid = info->si_pid;
	bit_decoder(signal, &s);
	w_kill(s.client_pid, SIGUSR1);
	ft_printf("Send ack to client!\n");
	if (s.bit == CHAR_BIT)
	{
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
	while(1)
		pause();
	return (0);
}
