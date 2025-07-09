//Powerset (3rd Edition that take care of minus by Raoul)
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	N;
int	size;
int	*nums_org;
int	*nums_sol;

void print_solution(int idx_sol)
{
	int i = 0;
	while (i < idx_sol)
	{
		printf("%d", nums_sol[i]);
		if (i <= idx_sol - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void solve(int remains, int idx_org, int idx_sol)
{
	if (remains == 0)
	{
		if (N != 0 || idx_sol > 0)
		{
			print_solution(idx_sol);
			return;
		}
	}
	if (idx_org >= size)
		return;
	while (idx_org < size )
	{
		nums_sol[idx_sol] = nums_org[idx_org];
		solve(remains - nums_org[idx_org], idx_org + 1, idx_sol + 1);
		idx_org++;
	}
}

int main(int ac, char ** av)
{
	if (ac < 3)
		return (printf("Error usage: %s <target> <num1> [num2 ...]\n", av[0]), 1);
	N = atoi(av[1]);
	size = ac - 2;
	nums_org = malloc(sizeof(int) * size);
	nums_sol = malloc(sizeof(int) * size);
	int i = 0;
	while (i < size)
	{
		nums_org[i] = atoi(av[i + 2]);
		i++;
	}
	solve(N, 0, 0);
	free(nums_org);
	free(nums_sol);
	return (0);
}

///////////////////////////////////////////////////////////////
//V1
//Use some global variable

//#include <unistd.h>
//#include <stdlib.h>
//#include <stdio.h>

//// --- Global Variables ---
//int *nums_org;                 // Will store the input numbers
//int N;                    // Will store the size of nums_org
//int *nums;   // Will store the current subset being constructed

//void print_solution(int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d", nums[i]);
//		if (i < size - 1)
//			printf(" ");
//	}
//	printf("\n");
//}

//void find_subset(int target_remaining, int size, int idx_start)
//{
//	if (target_remaining == 0)
//	{
//		print_solution(size);
//		return;
//	}
//	int i = 0;
//	while (i < N)
//	{
//		if (nums_org[i] <= target_remaining)
//		{
//			nums[size] = nums_org[i];
//			find_subset(target_remaining - nums_org[i], size + 1, i + 1);
//		}
//		i++;
//	}
//}


//int main(int ac, char **av)
//{
//	if (ac < 3)
//		return (printf("Error usage: %s <target> <num1> [num2 ...]\n", av[0]), 1);
//	int power = atoi(av[1]);
//	N = ac - 2;
//	nums_org = malloc(sizeof(int) * N);
//	nums = malloc(sizeof(int) * N);
//	if (!nums_org || !nums)
//	{
//		if (nums_org)
//			free(nums_org);
//		if (nums)
//			free(nums);
//		return (printf("Error: malloc failed\n"), 1);
//	}
//	for (int i = 0; i < N; i++)
//		nums_org[i] = atoi(av[i + 2]);
//	find_subset(power, 0, 0);
//	free(nums_org);
//	free(nums);
//	return (0);
//}