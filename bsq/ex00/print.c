/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:22:49 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/01 22:03:55 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fn_print_board(t_map *map, t_square solution)
{
	
}

void	fn_print_error(void)
{
	write(STDERR_FILENO, "map error\n", 10);
}
