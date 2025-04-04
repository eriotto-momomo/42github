
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filter_stdin(char *stdin_copy, int start, int len)
{
	while (len > 0)
	{
		stdin_copy[start] = '*';
		start++;
		len--;
	}
}

void check_if_match(char *stdin_copy, const char *filter)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	match = 0;

	while (stdin_copy[i])
	{
		if (stdin_copy[i] == filter[0])
		{
			match = i;
			while (stdin_copy[match] && filter[j] && stdin_copy[match] == filter[j])
			{
				if (match - i + 1 == strlen(filter))
					filter_stdin(stdin_copy, i, strlen(filter));
				match++;
				j++;
			}
			j = 0;
			match = 0;
		}
		i++;
	}
}

void get_stdin(char *stdin_copy)
{
	size_t	size = 0;
	int		bytes_read = 0;
	char 	current_char = '\0';

	while (1)
	{
		bytes_read = read(0, &current_char, 1);
		if (bytes_read < 0)
		{
			stdin_copy = NULL;
			return ;
		}
		stdin_copy = realloc(stdin_copy, size + 1);
		if (stdin_copy == NULL)
			return ;
		if (bytes_read == 0 || current_char == '\n')
		{
			stdin_copy[size] = '\0';
			return ;
		}
		else
			stdin_copy[size] = current_char;
		size++;
	}
}

// ATTENTION!
// 1. Toujours initialiser les `str` avant de les utiliser
// 2. `malloc` etc... toujours avec `size + 1`
int	ft_filter(const char *filter)
{
	char *stdin_copy = NULL;

	stdin_copy = calloc(1, sizeof(char));
	if (stdin_copy == NULL)
		return (0);
	get_stdin(stdin_copy);
	if (stdin_copy == NULL)
		return (0);
	check_if_match(stdin_copy, filter);
	printf("%s\n", stdin_copy);
	free(stdin_copy);
	return (1);
}


int	main(int ac, char **av)
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