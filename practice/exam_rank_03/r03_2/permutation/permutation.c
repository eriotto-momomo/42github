
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

//1. swap le nombre à l'index de `i` avec le dernier de la chaîne
//2. rappelle `permutation` en incrémentant le point de départ `start`
//3. replace la chaîne à son état précédent
//4. incrémente `i` pour répéter l'opératon et générer toutes les combis
void	permutation(char *str, int start, int end)
{
	int	i;

	if (start == end)
		printf("%s\n", str);
	else
	{
		i = start;
		while (i <= end)
		{
			swap(&str[start], &str[i]);
			permutation(str, start + 1, end);
			swap(&str[start], &str[i]);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int	end;

	if (ac != 2)
	{
		perror("Invalid arguments!");
		return (1);
	}
	else
	{
		end = strlen(av[1]);
		permutation(av[1], 0, end - 1);
	}
	return (0);
}