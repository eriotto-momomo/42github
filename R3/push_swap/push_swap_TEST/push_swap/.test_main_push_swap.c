#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	main(void)
{
	int i;
	int *result;

	char *argv1[6] = {
		"./a.out",
		"12",
		"-3",
		"45",
		"6",
		"-78",
	};
		char *argv2[6] = {
		"./a.out",
		"12",
		"3",
		"45",
		"-3",
		"-78",
	};
	char *argv3[2] = {
		"./a.out",
		"12 34"
	};
	char *argv4[2] = {
		"./a.out",
		"12 -3 44 -5 -78"
	};
	char *argv5[2] = {
		"./a.out",
		"1111111111 -1111111111 -2147483648 2147483647"
	};
	int argc1 = 6;
	int argc2 = 2;

	i = 0;
printf("----------------\n|||| TEST-1 ||||\n----------------\n");
	result = check_and_convert(argc1, argv1);
	while (result[i])
	{
		printf("|T1| result[%i] is: %i\n", i, result[i]);
		i++;
	}
	free(result);
	i = 0;
printf("----------------\n|||| TEST-2 ||||\n----------------\n");
	result = check_and_convert(argc1, argv2);
	while (result[i])
	{
		printf("|T2| result[%i] is: %i\n", i, result[i]);
		i++;
	}
	free(result);
	i = 0;
printf("----------------\n|||| TEST-3 ||||\n----------------\n");
	result = check_and_convert(argc2, argv3);
	while (result[i])
	{
		printf("|T3| result[%i] is: %i\n", i, result[i]);
		i++;
	}
	free(result);
	i = 0;
printf("----------------\n|||| TEST-4 ||||\n----------------\n");
	result = check_and_convert(argc2, argv4);
	while (result[i])
	{
		printf("|T4| result[%i] is: %i\n", i, result[i]);
		i++;
	}
	free(result);
	i = 0;
	printf("----------------\n|||| TEST-5 ||||\n----------------\n");
	result = check_and_convert(2, argv5);
	while (result[i])
	{
		printf("|T5| result[%i] is: %i\n", i, result[i]);
		i++;
	}
	free(result);
	return (0);
}