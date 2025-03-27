/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:31:23 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/27 19:16:06 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strcomp(char *str, char *filter)
{
	size_t flen = strlen(filter); //Filter
	size_t pos = 0;

	while(str[pos] && filter[pos] && str[pos] == filter[pos] && pos < flen - 1) //We have to make the compare does not compre the \0 of filter
		pos++;
	return filter[pos] - str[pos];
}

void ft_applyfilter(char *str, char *filter)
{
	size_t	pos = 0 ;
	size_t	stars_left = 0; //remaining amount of star to replace
	size_t	filter_len = strlen(filter); //The number of stars to place avery time we see the filter

	while(str[pos])
	{
		if(stars_left == 0 && ft_strcomp(&(str[pos]), filter) == 0) //If the filter is found at 'pos' in str and there no active filter (stars_left == 0) then we can set the 'filter_len' chars asc '*'
		{
			stars_left = filter_len;
		}
		if(stars_left > 0) //Applying stars
		{
			str[pos] = '*';
			stars_left--;
		}
		pos++;
	}
	printf("%s", str); //Printing result do not place \n as this charcter is already in str
}

int ft_filter(char *filter)
{
	char current_char; //Char extracted from read
	int	read_bytes; //Result of read
	char *buffer_string; //On each read character we add them in this string we realloc it every times
	size_t len = 0; //Len of the current buffer string

	buffer_string = calloc(sizeof(char), 1); //First buffer init --> ""
	if(!buffer_string)
		return (-1);
	read_bytes = read(0, &current_char, 1); // Reading next char
	while(read_bytes > 0) //Loop until read_bytes is either 0 (End Of File -> ctrl + D) or en error
	{
		//Adding to buffer string
		len++;
		buffer_string = realloc(buffer_string, len + 1); //Reallocating buffer size with new len;
		if(!buffer_string)
			return -1;
		buffer_string[len - 1] = current_char; //Adding or new char to the string
		buffer_string[len] = 0;

		if(current_char == '\n') //Whenever the user press enter (add a \n) we have to filter the buffer and print it. Then we clear it
		{
			ft_applyfilter(buffer_string, filter);
			//CLEARING buffer
			free(buffer_string);
			buffer_string = calloc(sizeof(char), 1);
			if(!buffer_string)
				return (-1);
			len = 0;
		}
		read_bytes = read(0, &current_char, 1); // Reading next char
	}
	ft_applyfilter(buffer_string, filter);
	free(buffer_string);
	return read_bytes;
}

int main(int argc, char **argv)
{
	//Checking if the unique argument is valid
	if(argc != 2 || strlen(argv[1]) == 0)
	{
		return (1);
	}
	if(ft_filter(argv[1]) < 0) //Calling main function and if return a value lower than 0 that mean read or malloc failed
	{
		perror("Error");
		return (1);
	}

	return (0);
}