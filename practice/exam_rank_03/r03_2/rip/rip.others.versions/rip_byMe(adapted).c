/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_byMe(adapted).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:28:26 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/08 00:39:24 by emonacho         ###   ########.fr       */
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

 // TEST "((()()"

#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_balance(char *output)
{
	int	open_count;

	open_count = 0;
	while (*output)
	{
		if (*output == '(')
			open_count++;
		else if (*output == ')')
		{
			if (open_count == 0)
				return (0); // Fermeture sans ouverture
			open_count--;
		}
		output++;
	}
	return (open_count == 0); // BOOLEEN `return (1)(if true)`
}

void	rip(char *input, char *output, int max_deletions, int current_deletions, int i)
{
	if (input[i] == '\0')
	{
		output[i] = '\0';
		if (is_balance(output) && max_deletions == current_deletions)
			puts(output);
		return;
	}
	if (input[i] != '(' && input[i] != ')')
		return;
	output[i] = ' ';		// Option 1: Supprimer cette parenthèse (en mettant un espace)
	rip(input, output, max_deletions, current_deletions + 1, i + 1);
	output[i] = input[i];	// Option 2: Garder cette parenthèse
	rip(input, output, max_deletions, current_deletions, i + 1);
}

int main(int ac, char **av)
{
	int		spaces;
	int		braces;
	char	*input = av[1];
	char	output[ft_strlen(av[1]) + 1];
	if (ac != 2 || !av[1][0])
		return (printf("Error: invalid arguments"), 1);
	braces = 0;
	spaces = 0;
	while(*input)
	{
		if (*input == '(')
			braces++;
		else if (*input == ')' && braces-- <= 0)
			spaces++;
		input++;
	}
	rip(av[1], output, spaces + braces, 0, 0);
	//rip(input, output, spaces + braces, 0, 0); // Pas possible de passer `input`
}
