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

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		puts("Too many/few arguments\n");
		return (1);
	}
	if (rip(av[1]) != 0)
	{
		puts("No solution possible\n");
		return (1);
	}




}

