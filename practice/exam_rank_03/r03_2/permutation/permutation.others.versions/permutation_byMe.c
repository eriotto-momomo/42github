/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation_byMe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:25 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/10 18:12:44 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>

void	swap(char *x, char *y)
{
	char	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	is_sorted(char *str, int len, int start)
{
	int i = start;

	while (i < len - 1)
	{
		if (str[i + 1] && (str[i] > str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	sort_str(char *str, int len, int start)
{
	int i;

	while (!is_sorted(str, len, start))
	{
		i = start;
		while (i < len - 1)
		{
			if (str[i] > str[i + 1])
				swap(&str[i], &str[i + 1]);
			i++;
		}
	}
}

int	should_swap(char *str, int start, int current)
{
	int i = start;

	while (i < current)
	{
		if (str[i] == str[current])
			return (0);
		i++;
	}
	return (1);
}


void	permutation(char *str, int len, int start)
{
	int i;

	if (start == len  - 1)
		printf("%s\n", str);
	else
	{
		i = start;
		while (i < len)
		{
			sort_str(str, len, start);
			if (should_swap(str, start, i))
			{
				swap(&str[start], &str[i]);
				permutation(str, len, start + 1);
				swap(&str[start], &str[i]);
			}
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (perror("Invalid arguments!"), 1);
	int	len = strlen(av[1]);
	sort_str(av[1], len, 0);
	permutation(av[1], len, 0);
	return (0);
}
