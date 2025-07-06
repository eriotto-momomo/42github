
#include<string.h>
#include<unistd.h>
#include<stdio.h>


void	swap(char *x, char *y)
{
	char	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	permutation(char *str, int first_pos, int last_pos)
{
	int	i;

	if (first_pos == last_pos)
		printf("%s\n", str);
	else
	{
		i = first_pos;
		while (i <= last_pos)
		{
			swap(&str[first_pos], &str[i]);
			permutation(str, first_pos + 1, last_pos);
			swap(&str[first_pos], &str[i]);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int	last_pos;

	if (ac != 2)
	{
		perror("Invalid arguments!");
		return (1);
	}
	else
	{
		last_pos = strlen(av[1]);
		permutation(av[1], 0, last_pos - 1);
	}
	return (0);
}