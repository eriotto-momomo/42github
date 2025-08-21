/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3_permutation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:17:02 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/11 11:37:41 by emonacho         ###   ########.fr       */
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
	while(start < len - 1)
	{
		if (str[start] > str[start + 1])
			return (0);
		start++;
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
			if (str[i] > str[i + 1])
				swap(&str[i], &str[i + 1]);
			i++;
		}
	}
}

int to_swap(char *str, int start, int current)
{
	while (start < current)
	{
		if (str[start] == str[current])
			return (0);
		start++;
	}
	return (1);
}

void permutation(char *str, int len, int start)
{
	int i;

	if (start == len - 1)
		puts(str);
	else
	{
		i = start;
		while (i < len)
		{
			sort_str(str, len, start);
			if (to_swap(str, start, i))
			{
				swap(&str[start], &str[i]);
				permutation(str, len, start + 1);
				swap(&str[start], &str[i]);
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