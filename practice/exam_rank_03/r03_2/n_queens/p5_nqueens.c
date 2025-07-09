/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p5_nqueens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:21:36 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/08 16:34:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void print_board(int *board, int n)
{
	int i = 0;

	while (i < n)
	{
		printf("%d", board[i]);
		if (i < n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int	queen_is_safe(int *board, int row, int col)
{
	int i = 0;

	while (i < col)
	{
		if (board[i] == row ||
			board[i] == row - (col - i) ||
			board[i] == row + (col - i))
			return (0);
		i++;
	}
	return (1);
}

void n_queens(int *board, int n, int col)
{
	int row = 0;

	while (row < n) // Tant qu'on a pas check toutes les cases `n` des `row`
	{
		if (queen_is_safe(board, row, col)) // Solution valide trouvée
		{
			board[col] = row;
			if (col == n - 1)				// Toutes les reines placées
				print_board(board, n);
			else							// Reste des reines à placer
				n_queens(board, n, col + 1);
		}
		row++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (printf("Error: invalid arguments\n"), 1);
	int n = atoi(av[1]);
	if (n < 1)
		return (printf("Error: invalid numer\n"), 1);
	int board[n];
	n_queens(board, n, 0);
	return (0);
}