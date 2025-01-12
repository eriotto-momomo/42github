#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
