/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_rip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:49:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/08 17:17:39 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_balance(char *output)
{
	int balance = 0;

	while (*output)
	{
		if (*output == '(')
			balance++;
		else if (*output == ')')
		{
			if (balance == 0) // Will never be `balanced` - NOT VALID
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
			puts(output);	// Solution found
		return ;
	}
	if (input[i] != '(' && input[i] != ')')
		return ;
	output[i] = ' ';		// Delete brace
	rip(input, output, max_del, cur_del + 1, i + 1);
	output[i] = input[i];	// Skip brace
	rip(input, output, max_del, cur_del, i + 1);
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
		return (printf("Error: invalid arguments\n"), 1);
	char *input = av[1];
	char output[ft_strlen(av[1]) + 1];
	int spaces = 0;
	int braces = 0;
	while (*input)
	{
		if (*input == '(')
			braces++;
		if (*input == ')' && braces-- <= 0) // Trouve une paire valide
			spaces++;
		input++;
	}
	rip(av[1], output, braces + spaces, 0, 0);
	return (0);
}