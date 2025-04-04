/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:41:08 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/23 16:10:10 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_digits(int *digits, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(digits[i] + '0');
		i++;
	}
}

void	ft_generate_combn(int *digits, int n, int index, int start)
{
	int	num;

	if (index == n)
	{
		ft_print_digits(digits, n);
		if (digits[0] != 10 - n)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	num = start;
	while (num <= 9)
	{
		digits[index] = num;
		ft_generate_combn(digits, n, index + 1, num + 1);
		num++;
	}
}

void	ft_print_combn(int n)
{
	int	digits[10];

	ft_generate_combn(digits, n, 0, 0);
}

// int	main(void)
// {
// 	ft_print_combn(5);
// }
