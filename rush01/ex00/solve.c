/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:00:36 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/24 02:20:42 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid_position(int board[4][4], int row, int col, int val)
{
	return (check_row(board, row, val) && check_col(board, col, val));
}

int	solve(int board[4][4], int pos, int views[16])
{
	int	row;
	int	col;
	int	val;

	if (pos == 16)
		return (check_all_visibility(board, views));
	row = pos / 4;
	col = pos % 4;
	val = 1;
	while (val <= 4)
	{
		if (is_valid_position(board, row, col, val))
		{
			board[row][col] = val;
			if (solve(board, pos + 1, views))
				return (1);
			board[row][col] = 0;
		}
		val++;
	}
	return (0);
}
