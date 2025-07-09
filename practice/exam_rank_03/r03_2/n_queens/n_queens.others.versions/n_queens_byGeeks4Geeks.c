#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define N 4

// SOURCE: https://www.geeksforgeeks.org/c-program-for-n-queen-problem-backtracking-3/

void	print_solution(int board[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while ( j < N)
		{
			printf(" %d ", board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

/*	A utility function to check if a queen can
	be placed on board[row][col]. Note that this
	function is called when "col" queens are
	already placed in columns from 0 to col -1.
	So we need to check only left side for
	attacking queens */
int	queen_is_safe(int board[N][N], int row, int column)
{
	int	i;
	int	j;

	i = 0;
	while (i < column)			// Check this row on left side
		if (board[row][i++])
			return (1);
	i = row;
	j = column;
	while (i >= 0 && j >= 0)	// Check upper diagonal on left side
		if (board[i--][j--])
			return (1);
	i = row;
	j = column;
	while (i < N && j >= 0)		// Check lower diagonal on left side
		if (board[i++][j--])
			return (1);
	return (0);
}

int	solve_nqueen(int board[N][N], int column)
{
	int	i = 0;

	/* base case: If all queens are placed then return true */
	if (column >= N)		// Si toute les reines sont placées `return (SUCCESS);`
		return (0);			// ✅
	/* Consider this column and try placing this queen in all rows one by one */
	while (i < N)
	{
		if (queen_is_safe(board, i, column) == 0)
		{
			board[i][column] = 1;
			if (solve_nqueen(board, column + 1) == 0)
				return (0);			// Si le placement de cette reine est valide, continue à placer des reines.
			board[i][column] = 0;	// Sinon retourne en arrière `backtrack`
		}
		i++;
	}
	return (1);
}

int	nqueen()
{
	int	board[N][N] = { {0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0} };

	if (solve_nqueen(board, 0) != 0)
	{
		perror("Solution doesn't exist!");
		return (1);			// ❌
	}
	print_solution(board);
	return (0);
}

int	main(void)
{
	nqueen();
	return (0);
}