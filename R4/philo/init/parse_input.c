/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:37:24 by emonacho          #+#    #+#             */
/*   Updated: 2025/08/04 15:02:26 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (((str[i]) >= 9 && (str[i]) <= 13) || (str[i]) == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i]) && (str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= sign;
	return (num);
}

static int	is_digit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

static int	*convert_input(int ac, char **av)
{
	int	*input;
	int	i;

	input = (malloc(sizeof(int) * ac - 1));
	if (!input)
		return (ft_putstr_fd("Error: malloc failed\n", 2), NULL);
	i = 0;
	while (i < ac - 1)
	{
		input[i] = ft_atoi(av[i + 2]);
		if ((i < 6 && input[i] <= 0) || (i == 6 && input[i] < 0)
			|| input[i] > INT_MAX)
		{
			free(input);
			return (ft_putstr_fd
				("Error: invalid arguments\n", 2), NULL);
		}
		i++;
	}
	return (input);
}

int	parse_input(int ac, char **av, t_main *s)
{
	int	i;

	if (!(ac == 5 || ac == 6))
		return (ft_putstr_fd("Error: invalid number of arguments\n", 2), 1);
	i = 0;
	while (i < ac - 1)
	{
		if (!is_digit(av[i + 2]))
			return (ft_putstr_fd("Error: invalid arguments\n", 2), 1);
		i++;
	}
	s->in = convert_input(ac, av);
	if (s->in == NULL)
		return (1);
	return (0);
}
