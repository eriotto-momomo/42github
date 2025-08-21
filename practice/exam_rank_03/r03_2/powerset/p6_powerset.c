/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p6_powerset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:38:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/11 10:09:38 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int g_size;

void print_result(int *output, int i_out)
{
	int i = 0;

	while (i < i_out)
	{
		printf("%d", output[i]);
		if (i < i_out - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void powerset(int remains, int *input, int *output, int i_in, int i_out)
{
	if (remains == 0 && i_out > 0)
		return (print_result(output, i_out));
	while (i_in < g_size)
	{
		output[i_out] = input[i_in];
		powerset(remains - input[i_in], input, output, i_in + 1, i_out + 1);
		i_in++;
	}
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (printf("Error: invalid arguments\n"), 1);
	g_size = ac - 2;
	int input[g_size];
	int output[g_size];
	int i = 0;
	while (i < g_size)
	{
		input[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(atoi(av[1]), input, output, 0, 0);
	return (0);
}