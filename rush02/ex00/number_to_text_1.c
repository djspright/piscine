/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_text_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:40:51 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 17:15:56 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_tens_fallback(unsigned long long n)
{
	if (n == 2)
		ft_putstr("twenty");
	else if (n == 3)
		ft_putstr("thirty");
	else if (n == 4)
		ft_putstr("forty");
	else if (n == 5)
		ft_putstr("fifty");
	else if (n == 6)
		ft_putstr("sixty");
	else if (n == 7)
		ft_putstr("seventy");
	else if (n == 8)
		ft_putstr("eighty");
	else if (n == 9)
		ft_putstr("ninety");
	else
		ft_putstr("Dict Error\n");
}

int	print_small_number(unsigned long long n, t_dict *d)
{
	t_dict_entry	*e;

	e = find_number(d, n);
	if (!e)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	ft_putstr(e->word);
	return (0);
}

int	print_tens_remainder(unsigned long long n, t_dict *d)
{
	if (n % 10)
	{
		ft_putstr(" ");
		return (print_tens(n % 10, d));
	}
	return (0);
}

int	print_tens(unsigned long long n, t_dict *d)
{
	t_dict_entry	*e;

	if (n < 20)
		return (print_small_number(n, d));
	e = find_number(d, (n / 10) * 10);
	if (!e)
	{
		print_tens_fallback(n / 10);
		if (n / 10 < 2 || n / 10 > 9)
			return (1);
	}
	else
		ft_putstr(e->word);
	return (print_tens_remainder(n, d));
}
