/*
* Assignement name: rip
* Expected files: *.c *.h
* Allowed functions: puts, write
* ------------------------------
* Write a program that will take as agrument a string containing only parentheses.
*
* If the parentheses are unbalanced (for exemple "())") your program shall remove
* the minimum number of parentheses for the expression to be balanced.
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
*/

// Related to 'permutation'?

#include <stdio.h>

int	cnt_parenthesis(char *str)
{
	int	i = 0;
	int	left_cnt = 0;
	int	right_cnt = 0;

	while (str[i])
	{
		if (str[i] != '(' && str[i] != ')')
			return (0);
		else if (str[i] == '(')
			left_cnt++;
		else if (str[i] == ')')
			right_cnt++;
		i++;
	}
	//if (left_cnt == 0 || right_cnt == 0)
	//	return (0);
	if (left_cnt > right_cnt || left_cnt == right_cnt)
		return (left_cnt);
	else if (left_cnt < right_cnt)
		return (right_cnt);
	else
		return (0);
}

int	parenthesis_backtracking(char *str)
{
	int	cnt = 0;

	cnt = cnt_parenthesis(str);
	if (cnt == 0)
		return (0);
	puts("Original string:");
	puts(str);
	printf("cnt = %d\n", cnt);


	//else
	//	backtrack(str);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1] == NULL)
		return (1);
	if (!parenthesis_backtracking(av[1]))
		return (1);
	return (0);
}