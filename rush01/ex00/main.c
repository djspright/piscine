/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:42:47 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/24 05:21:32 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	init_board(int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	board[4][4];
	int	views[16];

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	if (!parse_input(argv[1], views))
	{
		print_error();
		return (1);
	}
	init_board(board);
	if (solve(board, 0, views))
		print_board(board);
	else
		print_error();
	return (0);
}
