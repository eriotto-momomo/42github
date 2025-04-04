/*
Assignment

Write a program that will take one and only one argument s.
Your program will then read from stdin and write all the content
read in stdout except that every occurance of s must be replaced
by a "*" (as many as the length of s).

For example:
equivalent to filter.sh
./filter bonjour
Will behave in the same way as:
sed 's/bonjour/ ****** /g'

./filter abc
will behave in the same way as:
sed 's/abc/ *** /g'

Allowed functions: read, write, strlen, memmem, memmove, malloc, calloc,
realloc, free, perror, printf, stderr



It must be the equivalent of the shell script filfer.sh
(Under is a copy of the file "filter.sh" that you get with the assignment.
You're told that your program should work the same)

In case of error during a read or malloc, you must write "Error: " followed by the error message in stderr and return 1.

e.g. this should work:
echo 'abcdefaaaabcdeabcabcdabc' | ./filter abc | cat -e
***defaaa***de******d***

echo 'ababcabababc' | ./filter ababc | cat -e
*****ab*****$
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void get_stdin(char *stdin_copy)
{
	int		bytes_read = 0;
	size_t	size = 0;
	char	current_char;

	while (1)
	{
		bytes_read = read(0, &current_char, 1);
		if (bytes_read < 0)
		{
			if (stdin_copy != NULL)
				stdin_copy = NULL;
			return ;
		}
		realloc(stdin_copy, size + 1);
		if (stdin_copy == NULL)
			return ;
		if (current_char == '\0' || current_char == '\n')
		{
			stdin_copy[size] = '\0'
			return ;
		}
		else
			stdin_copy[size] = current_char;
		size++;
	}
}

int ft_filter(const char *filter)
{
	char *stdin_copy;

	stdin_copy = calloc(sizeof(char), 1);
	if (stdin_copy == NULL)
		return (0);
	get_stdin(stdin_copy);
	if (stdin_copy == NULL)
		return (0);
	filter_if_match(stdin_copy);
	printf("%s\n", stdin_copy);
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2 || av[1] == NULL)
		return (1);
	if (!ft_filter(av[1]))
	{
		perror("Error");
		return (1);
	}
	return (0);
}