/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p7_rip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:52:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/10 11:11:10 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_balance(char *output)
{
	int balance = 0;

	while (*output)
	{
		if (*output == '(')
			balance++;
		else if (*output == ')')
		{
			if (balance == 0)
				return (0);
			balance--;
		}
		output++;
	}
	return (balance == 0);
}

void rip(char *input, char *output, int max_del, int cur_del, int i)
{
	if (input[i] == '\0')
	{
		output[i] = '\0';
		if (is_balance(output) && cur_del == max_del)
			puts(output);
		else
			return ;
	}
	if (input[i] != '(' && input[i] != ')')
		return ;
	output[i] = input[i];
	rip(input, output, max_del, cur_del, i + 1);
	output[i] = ' ';
	rip(input, output, max_del, cur_del + 1, i + 1);
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (printf("Error: invalid arguments\n"), 2);
	char	*input = av[1];
	char	output[ft_strlen(av[1]) + 1];
	int		spaces = 0;
	int		braces = 0;
	while (*input)
	{
		if (*input == '(')
			braces++;
		else if (*input == ')' && braces-- <= 0)
			spaces++;
		input++;
	}
	rip(av[1], output, spaces + braces, 0, 0);
	return (0);
}