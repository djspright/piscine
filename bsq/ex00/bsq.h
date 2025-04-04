/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:19:30 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/02 02:53:47 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096
# define LINE_BUFFER 8192

typedef struct s_map
{
	int		row;
	int		col;
	char	**content;
	char	empty;
	char	obstacle;
	char	full;
}			t_map;

typedef struct s_square
{
	int		x;
	int		y;
	int		size;
}			t_square;

int			main(int ac, char **av);

void		fn_putchar(char c);
void		fn_putstr(char *str);

void		fn_print_board(t_map *map, t_square solution);
void		fn_print_error(void);

int			process_char(char c, char **line, int *length, int *capacity);
char		*resize_buffer(char *old_buffer, int old_size, int new_size);
void		free_map_partial(char **map, int rows);

#endif
