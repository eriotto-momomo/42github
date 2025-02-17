#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
	int	n = 100;
	int	array[n];

	printf("\nSORTED ARRAY\n");
	for (int i = 0; i < n; i++)
	{	// fill array
		array[i] = i;
		printf("%d ", array[i]);
	}

	for (int i = 0; i < n; i++)
	{	// shuffle array
		int temp = array[i];
		int randomIndex = rand() % n;

		array[i]           = array[randomIndex];
		array[randomIndex] = temp;
	}

	printf("\nRANDOMIZED ARRAY\n");
	for (int i = 0; i < n; i++)
	{	// print array
		printf("%d ",array[i]);
	}
}
