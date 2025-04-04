/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 00:35:42 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/24 05:52:59 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_visible_up(int board[4][4], int col)
{
	int	row;
	int	count;
	int	max_height;

	count = 0;
	max_height = 0;
	row = 0;
	while (row < 4)
	{
		if (board[row][col] > max_height)
		{
			count++;
			max_height = board[row][col];
		}
		row++;
	}
	return (count);
}

int	count_visible_down(int board[4][4], int col)
{
	int	row;
	int	count;
	int	max_height;

	count = 0;
	max_height = 0;
	row = 3;
	while (row >= 0)
	{
		if (board[row][col] > max_height)
		{
			count++;
			max_height = board[row][col];
		}
		row--;
	}
	return (count);
}

int	count_visible_left(int board[4][4], int row)
{
	int	col;
	int	count;
	int	max_height;

	count = 0;
	max_height = 0;
	col = 0;
	while (col < 4)
	{
		if (board[row][col] > max_height)
		{
			count++;
			max_height = board[row][col];
		}
		col++;
	}
	return (count);
}

int	count_visible_right(int board[4][4], int row)
{
	int	col;
	int	count;
	int	max_height;

	count = 0;
	max_height = 0;
	col = 3;
	while (col >= 0)
	{
		if (board[row][col] > max_height)
		{
			count++;
			max_height = board[row][col];
		}
		col--;
	}
	return (count);
}
