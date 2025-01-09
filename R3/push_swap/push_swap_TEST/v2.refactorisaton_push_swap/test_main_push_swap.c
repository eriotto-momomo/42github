#include "push_swap.h"

int	main(void)
{
	int i;
	int *result1;
	int *result2;
	int *result3;
	int *result4;
	int *result5;
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
		"12 12ab"
	};
	char *argv4[2] = {
		"./a.out",
		"12 -3 44 -3 -78"
	};
	char *argv5[2] = {
		"./a.out",
		"1111111111 -1111111111 -2147483648 2147483647"
	};
	int argc1 = 6;
	int argc2 = 2;

	i = 0;
	printf("//// TEST 1 /////////////////////////////////////\n");
	result1 = push_swap(argc1, argv1);
	while (result1[i])
	{
		printf("result[%i] is: %i\n", i, result1[i]);
		i++;
	}
	i = 0;
	printf("//// TEST 2 /////////////////////////////////////\n");
	result2 = push_swap(argc1, argv2);
	while (result2[i])
	{
		printf("result[%i] is: %i\n", i, result2[i]);
		i++;
	}
	i = 0;
	printf("//// TEST 3 /////////////////////////////////////\n");
	result3 = push_swap(argc2, argv3);
	while (result3[i])
	{
		printf("result[%i] is: %i\n", i, result3[i]);
		i++;
	}
	i = 0;
	printf("//// TEST 4 /////////////////////////////////////\n");
	result4 = push_swap(argc2, argv4);
	while (result4[i])
	{
		printf("result[%i] is: %i\n", i, result4[i]);
		i++;
	}
	i = 0;
	printf("//// TEST 5 /////////////////////////////////////\n");
	result5 = push_swap(argc2, argv5);
	while (result5[i])
	{
		printf("result[%i] is: %i\n", i, result5[i]);
		i++;
	}
	return (0);
}