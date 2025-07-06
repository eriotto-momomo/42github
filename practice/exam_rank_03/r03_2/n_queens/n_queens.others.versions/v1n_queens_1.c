
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void	print_chess(int **chess_board, int n)
{
	int	i = 0;
	int j = 0;

	while(i < n)
	{
		j = 0;
		while (j < n)
		{
			printf(" %d", chess_board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	**intialize_chess(int n)
{
	int	**chess = malloc(sizeof(int **) * n);
	if (!chess)
		return (0);
	int i = 0;
	while (i < n)
	{
		chess[i] = malloc(sizeof(int *) * n);
		if (!chess)
			return (0);
		i++;
	}
	i = 0;
	int j = 0;
	while (i < n)
	{
		j = 0;
		while(j < n)
		{
			chess[i][j] = 0;
			j++;
		}
		i++;
	}
	return (chess);
}

int placement_is_valid(int **chess_board, int size, int row, int col)
{
	int i = 0;
	int j = 0;

	printf("placement_is_valid | ENTERING FUNCTION\n");
	while (i < col)
	{
		if (chess_board[row][i] == 1)
		{
			return (0);
			printf("placement_is_valid | CANT PLACE QUEEN\n");
		}
		i++;
	}
	i = row;
	j = col;

	while (i >= 0 && j >= 0)
	{
		if (chess_board[i][j] == 1)
		{
			return (0);
			printf("placement_is_valid | CANT PLACE QUEEN\n");
		}
		i--;
		j--;
	}
	i = row;
	j = col;
	while (i < size && j >= 0)
	{
		if(chess_board[i][j] == 1)
		{
			return (0);
			printf("placement_is_valid | CANT PLACE QUEEN\n");
		}
		i++;
		j--;
	}
	printf("placement_is_valid | QUEEN PLACED\n");
	return (1);

}

int	solve(int **chess_board, int n, int col)
{
	int i = 0;

	if (col >= n)
		return (1);
	while (i < n)
	{
		if (placement_is_valid(chess_board, n, i, col))
		{
			chess_board[i][col] = 1;
			if (solve(chess_board, n, col + 1))
				return (1);
			chess_board[i][col] = 0;
		}
		i++;
	}
	return (0);
}

int	n_queen(int n)
{
	int	**chess_board = intialize_chess(n);
	if (!chess_board)
		return (0);
	if (!solve(chess_board, n, 0))
		return (0);
	print_chess(chess_board, n);

	return (1);
}

int main(int ac, char **av)
{
	int	n;

	if (ac != 2)
	{
		perror("Invalid args!");
		return (1);
	}
	n = atoi(av[1]);
	if (n < 0)
	{
		perror("Arg is negative!");
		return (1);
	}
	if (!n_queen(n))
	{
		perror("Not solvable!");
		return (1);
	}
	return (0);
}
