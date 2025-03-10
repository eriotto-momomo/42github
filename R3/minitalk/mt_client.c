/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:18:08 by emonacho          #+#    #+#             */
/*   Updated: 2025/03/10 19:54:46 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t	server;
	char	*message;

	if (argc != 3)
	{
		if (argc < 3)
			ft_putstr_fd("Error! Too few arguments.\n", 2);
		else if (argc > 3)
			ft_putstr_fd("Error! Too many arguments.\n", 2);
		exit(1);
	}
	server = ft_atoi(argv[1]);
	message = av[2];

	while (*message)

	return (0);
}
