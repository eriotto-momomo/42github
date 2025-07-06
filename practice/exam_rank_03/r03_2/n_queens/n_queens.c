/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:36:23 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/06 18:47:44 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_board(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i < n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int	queen_is_safe(int x, int y, int *board)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (board[i] == y ||			// check si 'queen` présente à la même hauter de [y] (donc sur même ligne)
			board[i] == y + (x - i) ||	// check diagonale montante
			board[i] == y - (x - i))	// check diagonale descendante
		i++;
	}
	return (1);
}

//💡 `row` go horizontal (x) / `col` go vertical (y)
void	n_queens(int *board, int n, int x)
{
	int	y;

	y = 0;
	while (y < n)
	{
		if (queen_is_safe(x, y, board))
		{
			board[x] = y;
			if (x == n - 1)
				print_board(board, n);
			else
				n_queens(board, n, x + 1);
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int *board;

	if (ac != 2 || !av[1])
		return(fprintf(stderr, "Error: incorrect arguments\n"));
	n = atoi(av[1]);
	if (n < 1)
		return(fprintf(stderr, "Error: invalid number of queens\n"));
	board = malloc (sizeof(int) * n);
	if (!board)
		return(fprintf(stderr, "Error: malloc failed\n"));
	n_queens(board, n, 0);
	free(board);
	return (0);
}