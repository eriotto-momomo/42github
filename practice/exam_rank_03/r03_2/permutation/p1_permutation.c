/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1_permutation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:06:43 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/10 21:43:38 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y)
{
	char tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int is_sorted(char *str, int len, int start)
{
	int i = start;

	while (i < len - 1)
	{
		if (str[i] && (str[i] > str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void sort_str(char *str, int len, int start)
{
	int i;

	while (!is_sorted(str, len, start))
	{
		i = start;
		while (i < len - 1)
		{
			if (str[i] && (str[i] > str[i + 1]))
				swap(&str[i], &str[i + 1]);
			i++;
		}
	}
}

int is_swappable(char *str, int start, int current) //⚠️❌
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

void permutation(char *input, int len, int start)
{
	if (start == len - 1)
		puts(input);
	else
	{
		int i = start;
		while (i < len)
		{
			sort_str(input, len, start);
			if (is_swappable(input, start, i)) //⚠️❌
			{
				swap(&input[start], &input[i]); //⚠️❌
				permutation(input, len, start + 1);
				swap(&input[start], &input[i]); //⚠️❌
			}
			i++;
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (printf("Error: invalid arguments\n"), 1);
	int len = strlen(av[1]);
	sort_str(av[1], len, 0);
	permutation(av[1], len, 0);
	return (0);
}