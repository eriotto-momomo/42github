/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_bySebastian.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:28:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/07 22:29:18 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************************************************************
 * Assignement name: rip
 * Expected files: *.c *.h
 * Allowed functions: puts, write
 * ------------------------------
 * Write a program that will take as agrument a string containing only parentheses.
 *
 * If the parentheses are unbalanced (for exemple "())") your program shall remove
 * the minimum number of parentheses for the expression to be balanced.
 *
 * By removing we mean replacing by spaces. You will then print all the solutions
 * (can be more than one). The order of the solutions is not important.
 *
 * For exemple this should work:
 * $> ./rip '(()' | cat -e
 *  ()$
 * ( )$
 *
 * $> ./rip '((()()())())' | cat -e
 * ((()()())())$
 *
 * $> ./rip '()())()' | cat -e
 * ()() ()$
 * ()( )()$
 * ( ())()$
 ***************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int is_balance(char *s)
{
	int balance;

	balance = 0;
	while (*s)
	{
		balance += (*s == '(') - (*s == ')');
		if (balance < 0)
			return (0);
		s++;
	}
	return balance == 0;
}

void rip(char *str, char *res, int spaces, int cur, int i)
{
	if (!str[i])
	{
		res[i] = 0;
		if (is_balance(res) && spaces == cur)
			puts(res);
		return;
	}
	if (str[i] != '(' && str[i] != ')')
		return;
	res[i] = ' ';
	rip(str, res, spaces, cur + 1, i + 1);
	res[i] = str[i];
	rip(str, res, spaces, cur, i + 1);
}

int main(int ac, char **av)
{
	int		spaces;
	int		braces;
	char	res[ft_strlen(av[1]) + 1];

	if (ac != 2 || !av[1][0])
		return (printf("Error: invalid arguments"), 1);
	braces = 0;
	spaces = 0;
	for (char *s = av[1]; *s; s++)
	{
		if (*s == '(')
			braces++;
		else if (*s == ')' && braces-- <= 0)
			spaces++;
	}
	rip(av[1], res, spaces + braces, 0, 0);
}
