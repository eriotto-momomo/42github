/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p9_rip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:41:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/11 10:52:13 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_balance(char *out)
{
	int balance = 0;

	while (*out)
	{
		if (*out == '(')
			balance++;
		else if (*out == ')')
		{
			if (balance == 0)
				return (0);
			balance--;
		}
		out++;
	}
	return (balance == 0);
}

void rip(char *in, char *out, int max_del, int cur_del, int i)
{
	if (in[i] == '\0')
	{
		out[i] = '\0';
		if (is_balance(out) && cur_del == max_del)
			puts(out);
		else
			return ;
	}
	if (in[i] != '(' && in[i] != ')')
		return ;
	out[i] = ' ';
	rip(in, out, max_del, cur_del + 1, i + 1);
	out[i] = in[i];
	rip(in, out, max_del, cur_del, i + 1);
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
		return (printf("Error: invalide arguments\n"), 1);
	char *in = av[1];
	char out[ft_strlen(av[1]) + 1];
	int braces = 0;
	int spaces = 0;
	while (*in)
	{
		if (*in == '(')
			braces++;
		else if (*in == ')' && braces-- <= 0)
			spaces++;
		in++;
	}
	rip(av[1], out, braces + spaces, 0, 0);
	return (0);
}