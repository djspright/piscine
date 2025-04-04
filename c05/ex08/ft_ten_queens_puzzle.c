/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 04:08:22 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/03 11:09:36 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_solution(int board[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(STDOUT_FILENO, &c, sizeof(char));
		i++;
	}
	write(STDOUT_FILENO, "\n", sizeof(char));
}

int	ft_validate_queens(int board[10], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col || board[i] + i == row
			+ col)
			return (0);
		i++;
	}
	return (1);
}

int	ft_set_queens(int board[10], int col, int *count)
{
	int	row;

	if (col == 10)
	{
		ft_print_solution(board);
		(*count)++;
		return (1);
	}
	row = 0;
	while (row < 10)
	{
		if (ft_validate_queens(board, col, row))
		{
			board[col] = row;
			ft_set_queens(board, col + 1, count);
		}
		row++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	ft_set_queens(board, 0, &count);
	return (count);
}

// int	main(void)
// {
// 	int	solutions;

// 	solutions = ft_ten_queens_puzzle();
// 	return (0);
// }
