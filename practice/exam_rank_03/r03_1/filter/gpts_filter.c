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

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int ft_filter(const char *s)
{
	size_t	s_len;
	size_t	i;
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];
	char	*match;
	char	*start;

	s_len = strlen(s);
	while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
	{
		start = buffer;
		while ((match = memmem(start, buffer + bytes_read - start, s, s_len)))
		{
			write(STDOUT_FILENO, start, match - start);
			i = 0;
			while (i < s_len)
			{
				write(STDOUT_FILENO, "*", 1);
				i++;
			}
			start = match + s_len;
		}
		write(STDOUT_FILENO, start, buffer + bytes_read - start);
	}
	if (bytes_read < 0)
		return (0);
	return (1);
}

/* Pourquoi buffer + bytes_read - start donne la bonne taille ?
** buffer est un tableau de caractères qui contient les données lues depuis stdin.
** bytes_read est le nombre d'octets réellement lus depuis read(), donc buffer + bytes_read représente l'adresse juste après la dernière donnée valide dans buffer.
** start est un pointeur qui se déplace dans buffer au fur et à mesure qu'on remplace les occurrences de s.
** L'expression buffer + bytes_read - start donne la taille des caractères restants à écrire après le dernier remplacement, car :
** buffer + bytes_read → adresse après la dernière donnée valide.
** start → adresse actuelle après le dernier remplacement.
** La soustraction donne la distance entre start et la fin des données lues.
*/

int main(int argc, char *argv[])
{
	if (argc != 2 || argv[0] == NULL)
		return (1);
	if (!ft_filter(argv[1]))
	{
		perror("Error");
		return (1);
	}
	return (0);
}
