#include "push_swap.h"

int	main(void)
{
	/*char *argv1[9] = {
		"./a.out",
		"23",
		"4",
		"56",
		"7",
		"32",
		"2147483647",
		"-32",
		"-2147483648"
	};
		char *argv2[9] = {
		"./a.out",
		"23",
		"4",
		"23",
		"7",
		"7",
		"2147483647",
		"-32",
		"-2147483648"
	};*/
	char *argv3[2] = {
		"./a.out",
		"23 -23 45 4 67 890 123 -2147483648 2147483647"
	};
	//int res[argc];
	//int i = 0;
	int argc = 2;
	push_swap(argc, argv3);
	/*res[argc - 1] = push_swap(argc, argv);
	while (i < argc)
	{
		printf("array[%i] = %i\n", i, res[i]);
		i++;
	}*/
	return (0);
}