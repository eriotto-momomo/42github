/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1_powerset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:14:42 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/09 12:00:20 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int g_N;
int g_size;

void print_solution(int *out, int i_out)
{
	int i = 0;

	while (i < i_out)
	{
		printf("%d", out[i]);
		if (i < i_out - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void powerset(int remains, int *in, int *out, int i_in, int i_out)
{
	if (remains == 0 && i_out > 0)
		return (print_solution(out, i_out));
	while (i_in < g_size)
	{
		out[i_out] = in[i_in];
		powerset(remains - in[i_in], in, out, i_in + 1, i_out + 1);
		i_in++;
	}
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (printf("Error, invalid arguments\n"), 1);
	g_N		= atoi(av[1]);
	g_size	= ac - 2;
	int		in[g_size];
	int		out[g_size];
	int		i = 0;
	while (i < g_size)
	{
		in[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(g_N, in, out, 0, 0);
	return (0);
}