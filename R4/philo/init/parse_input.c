/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:37:24 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/29 22:38:23 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

static int	*convert_input(int ac, char **av)
{
	int		*input;
	long	conversion;
	int		i;

	input = (malloc(sizeof(size_t) * 5));
	if (!input)
		return (ft_putstr_fd("Error: malloc failed\n", 2), NULL);
	i = 0;
	while (i < ac - 1)
	{
		conversion = ft_atol(av[i + 1]);
		if (conversion < 0 || conversion > INT_MAX)
		{
			free(input);
			ft_putstr_fd("Error: invalid arguments\n", 2);
			return (NULL);
		}
		else
			input[i] = (int)conversion;
		i++;
	}
	if (ac == 5)
		input[4] = 999999999;
	return (input);
}

static bool	is_digit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}

int	parse_input(int ac, char **av, t_main *s)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_digit(av[i]) == false)
			return (ft_putstr_fd("Error: invalid arguments\n", 2), 1);
		i++;
	}
	s->in = convert_input(ac, av);
	if (s->in == NULL)
		return (1);
	if (s->in[N_PHILO] == 0 || s->in[N_PHILO] > 200)
	{
		free(s->in);
		return (ft_putstr_fd("Error: invalid number of philosophers\n", 2), 1);
	}
	return (0);
}
