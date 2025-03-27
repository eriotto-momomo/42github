
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

// BACKUP
/*char *get_stdin(void)
{
	char	*copy = NULL;
	char	current_char;
	int		copy_size = 1;
	int		bytes_read = 0;

	copy = calloc(copy_size, sizeof(char));
	if (copy == NULL)
		return (0);
	while(1)
	{
		bytes_read = read(0, &current_char, 1);
		if (bytes_read == -1)
		{
			if (copy != NULL)
				free(copy);
			return (NULL);
		}
		else if (bytes_read == 0)
		{
			copy = realloc(copy, copy_size + 1);
			if (copy == NULL)
				return (NULL);
			copy[copy_size - 1] = '\0';
			return (copy);
		}
		else
		{
			copy = realloc(copy, copy_size + 1);
			if (copy == NULL)
				return (NULL);
			copy[copy_size - 1] = current_char;
			copy_size++;
		}
	}
}*/

void get_stdin(char *copy)
{
	char	current_char;
	int		copy_size = 1;
	int		bytes_read = 0;

	while(1)
	{
		bytes_read = read(0, &current_char, 1);
		if (bytes_read == -1)
		{
			if (copy != NULL)
				free(copy);
			return ;
		}
		else
		{
			copy = realloc(copy, copy_size + 1);
			if (copy == NULL)
				return ;
			if (bytes_read == 0)
			{
				copy[copy_size - 1] = '\0';
				return ;
			}
			copy[copy_size - 1] = current_char;
			copy_size++;
		}
	}
}

void	filter_if_match(char *filter, char *stdin_copy, int i)
{
	size_t	j = i;
	size_t	k = 0;
	size_t	match = 0;
	size_t	filter_len = strlen(filter);

	while(stdin_copy[j] && filter[k] && match < filter_len)
	{
		if (stdin_copy[j] == filter[k])
		{
			match++;
			if (match == filter_len)
			{
				j = i;
				while (match > 0)
				{
					stdin_copy[j] = '*';
					match--;
					j++;
				}
				return ;
			}
		}
		j++;
		k++;
	}
}

void	apply_filter(char *filter, char *stdin_copy)
{
	size_t	i = 0;

	while(stdin_copy[i] != '\0')
	{
		if (stdin_copy[i] == filter[0])
			filter_if_match(filter, stdin_copy, i);
		i++;
	}
}

int ft_filter(char *filter)
{
	char	*stdin_copy = NULL;

	stdin_copy = calloc(1, sizeof(char));
	if (stdin_copy == NULL)
		return (0);
	get_stdin(stdin_copy);
	if (stdin_copy == NULL)
		return (0);
	apply_filter(filter, stdin_copy);
	printf("%s\n", stdin_copy);
	free(stdin_copy);
	return (1);
}

int main(int ac, char *av[])
{
	if (ac != 2 || av[0] == NULL)
		return (1);
	if (!ft_filter(av[1]))
	{
		perror("Error");
		return (1);
	}
	return (0);
}