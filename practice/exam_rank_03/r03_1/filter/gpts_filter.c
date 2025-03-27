#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void replace_and_print(const char *s)
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
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		return EXIT_FAILURE;
	}
	replace_and_print(argv[1]);
	return EXIT_SUCCESS;
}
