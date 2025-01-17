#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int	get_min_med_max(int size, int *array);

// Used to determine if the stack is almost sorted
// by checking the number of inversions.
int	check_disorder(int *stack, int size)
{
	int	i;
	int	j;
	int	inversions;

	i = 0;
	j = 1;
	inversions = 0;
	while (i < size && j < size)
	{
		if (stack[i] > stack[j])
			inversions++;
		i++;
		j++;
	}
	return (inversions);
}

int main(void)
{
	int *int_array;
	int size = 5;
	int_array = malloc(sizeof(int) * size);
	int_array[0] = 433;
	int_array[1] = -989;
	int_array[2] = -1000;
	int_array[3] = 690;
	int_array[4] = 543;

	//int min_value = 0;
	//int max_value = 0;
	//int median_value;
	//median_value = get_closest_median(size, int_array);
	//printf("median_value: %d\n", median_value);
	int inversions = 0;
	inversions = check_disorder(int_array, size);
	printf("inversions: %d\n", inversions);
	//printf("max_value: %d\n", max_value);
	//printf("min_value: %d\n", min_value);

	return (0);
}

/*int main(void)
{
	int *int_array;
	char **str_array;
	int size = 3;

	int_array = malloc(sizeof(int) * size);
	str_array = malloc(sizeof(char *) * size);

	int_array[0] = 1;
	int_array[1] = 2;
	int_array[2] = 3;
	str_array[0] = strdup("one");
	str_array[1] = strdup("two");
	str_array[2] = strdup("three");

	int i;
	for(i = 0; i < 3; i++)
		printf("int_array[%i] before cleaning: %i\n", i, int_array[i]);
	for(i = 0; i < 3; i++)
		printf("str_array[%i] before cleaning: %s\n", i, str_array[i]);
	free_int_or_str_array(int_array, 1, size);
	//printf("Burp!\n");
	free_int_or_str_array(str_array, 2, size);
	//printf("Burp!\n");
	for(i = 0; i < 3; i++)
		printf("int_array[%i] after cleaning: %i\n", i, int_array[i]);
	for(i = 0; i < 3; i++)
		printf("str_array[%i] after cleaning: %s\n", i, str_array[i]);
}*/

/*
// Every elements go down in the stack, the last
// element becomes the first. "go down" means
// (horizontally speaking): that elements
// are going from left to right in the string.
// 'DOWN' = '->' = '--'
void reverse_rotate(int *stack, int stack_size)
{
	int	tmp_stack;
	int	i;

	if (stack == NULL || stack_size <= 2)
		return;
	tmp_stack = stack[stack_size - 1];
	i = stack_size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp_stack;
}

// Every elements go up in the stack, the first
// element becomes the last. "go up" means
// (horizontally speaking): that elements
// are going from right to left in the string.
// 'UP' = '<-' = '++'
void rotate(int *stack, int stack_size)
{
	int	tmp_stack;
	int	i;

	if (stack == NULL || stack_size <= 2)
		return;
	tmp_stack = stack[0];
	i = 0;
	while (i < stack_size)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[stack_size - 1] = tmp_stack;
}

void push(int *src_stack, int *dst_stack, int stack_size)
{
	int	i;

	if (src_stack == NULL || dst_stack == NULL || stack_size <= 2)
		return;
	i = stack_size;
	while (i > 0)
	{

		dst_stack[i] = dst_stack[i - 1];
		i--;
	}
	dst_stack[0] = src_stack[0];
	while (i < stack_size)
	{
		src_stack[i] = src_stack[i + 1];
		i++;
	}
	src_stack[stack_size - 1] = 0;
}

int main(void)
{
	int i = 0;
	int stack_size = 3;
	int a_stack [3] = {
		1,
		0,
		0
	};
	int b_stack [3] = {
		2,
		3,
		0
	};

	printf("........................\n|||| ORIGINAL STACK ||||\n");
	i = 0;
	while (i < stack_size)
	{
		printf("a_stack[%i] = %d\n", i, a_stack[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < stack_size)
	{
		printf("b_stack[%i] = %d\n", i, b_stack[i]);
		i++;
	}

	printf("........................\n||||||||| PUSH |||||||||\n");
	i = 0;
	push (a_stack, b_stack, stack_size);
	while (i < stack_size)
	{
		printf("a_stack[%i] = %d\n", i, a_stack[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < stack_size)
	{
		printf("b_stack[%i] = %d\n", i, b_stack[i]);
		i++;
	}

	printf("........................\n|||||||| ROTATE ||||||||\n");
	printf("| 1 |\n");
	i = 0;
	rotate(b_stack, stack_size);
	while (i < stack_size)
	{
		printf("b_stack[%i] = %d\n", i, b_stack[i]);
		i++;
	}
	printf("\n");
	printf("| 2 |\n");
	i = 0;
	rotate(b_stack, stack_size);
	while (i < stack_size)
	{
		printf("b_stack[%i] = %d\n", i, b_stack[i]);
		i++;
	}
	printf("\n");
	printf("| 3 |\n");
	i = 0;
	rotate(b_stack, stack_size);
	while (i < stack_size)
	{
		printf("b_stack[%i] = %d\n", i, b_stack[i]);
		i++;
	}
	printf("\n");

	printf("........................\n|||| REVERSE ROTATE ||||\n");
	printf("| 1 |\n");
	i = 0;
	reverse_rotate(b_stack, stack_size);
	while (i < stack_size)
	{
		printf("b_stack[%i] = %d\n", i, b_stack[i]);
		i++;
	}
	printf("\n");
	printf("| 2 |\n");
	i = 0;
	reverse_rotate(b_stack, stack_size);
	while (i < stack_size)
	{
		printf("b_stack[%i] = %d\n", i, b_stack[i]);
		i++;
	}
	printf("\n");
	printf("| 3 |\n");
	i = 0;
	reverse_rotate(b_stack, stack_size);
	while (i < stack_size)
	{
		printf("b_stack[%i] = %d\n", i, b_stack[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
