/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 07:34:20 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/17 22:11:38 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	get_char(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == y - 1 && j == 0))
		return ('A');
	else if ((i == 0 && j == x - 1) || (i == y - 1 && j == x - 1))
		return ('C');
	else if (i == 0 || i == y - 1)
		return ('B');
	else if (j == 0 || j == x - 1)
		return ('B');
	else
		return (' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putchar(get_char(i, j, x, y));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
