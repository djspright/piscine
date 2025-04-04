/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:58:39 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/24 05:50:24 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

void	init_board(int board[4][4]);
int		main(int argc, char *argv[]);

int		parse_input(char *str, int views[16]);
int		check_input_validity(char *str);

int		solve(int board[4][4], int pos, int views[16]);
int		is_valid_position(int board[4][4], int row, int col, int val);

int		check_row(int board[4][4], int row, int val);
int		check_col(int board[4][4], int col, int val);
int		check_all_visibility(int board[4][4], int views[16]);

int		count_visible_up(int board[4][4], int col);
int		count_visible_down(int board[4][4], int col);
int		count_visible_left(int board[4][4], int row);
int		count_visible_right(int board[4][4], int row);

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	print_board(int board[4][4]);
void	print_error(void);

#endif
