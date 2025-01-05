#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_duplicates(int argc, int int_array[argc - 1])
{
	int	i;
	int j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (int_array[i] == int_array[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int main(void)
{
	int i = 0;
	int argc = 5;
	int	int_array[4] = {
		32,
		2147483647,
		-32,
		-2147483648
	};
	char *str_array[5] = {
		"/a.out",
		"-1  +2   3 04 05",
		"2147483647",
		"32",
		"-2147483648"
	};

	i = check_duplicates(argc, int_array);
	printf("check_duplicates returned = %i\n", i);
	return (0);
}
