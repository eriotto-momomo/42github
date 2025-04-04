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
