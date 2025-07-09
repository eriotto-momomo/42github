/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p6_nqueens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:17:53 by emonacho          #+#    #+#             */
/*   Updated: 2025/07/08 17:26:53 by emonacho         ###   ########.fr       */
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

int queen_is_safe(int *board, int row, int col)
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

	while (row < n)
	{
		if (queen_is_safe(board, row, col))
		{
			board[col] = row;
			if (col == n - 1)
				print_board(board, n);
			else
				n_queens(board, n, col + 1);
		}
		row++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (printf("Error: invalid arguments\n"), 2);
	int n = atoi(av[1]);
	if (n < 1)
		return (printf("Error: invalid number\n"), 2);
	int board[n];
	n_queens(board, n, 0);
	return (0);
}