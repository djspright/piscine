/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:54:07 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/24 04:48:26 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_row(int board[4][4], int row, int val)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (board[row][col] == val)
			return (0);
		col++;
	}
	return (1);
}

int	check_col(int board[4][4], int col, int val)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (board[row][col] == val)
			return (0);
		row++;
	}
	return (1);
}

int	check_all_visibility(int board[4][4], int views[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (count_visible_up(board, i) != views[i])
			return (0);
		if (count_visible_down(board, i) != views[i + 4])
			return (0);
		if (count_visible_left(board, i) != views[i + 8])
			return (0);
		if (count_visible_right(board, i) != views[i + 12])
			return (0);
		i++;
	}
	return (1);
}
