/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_text_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:32:21 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 17:18:29 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_hundreds_remainder(unsigned long long n, t_dict *d)
{
	int	r;

	if (n % 100)
	{
		ft_putstr(" ");
		r = print_tens(n % 100, d);
		if (r)
			return (1);
	}
	return (0);
}

int	print_hundreds(unsigned long long n, t_dict *d)
{
	t_dict_entry	*e;

	if (n < 100)
		return (print_tens(n, d));
	e = find_number(d, n / 100);
	if (!e)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	ft_putstr(e->word);
	ft_putstr(" ");
	if (!find_number(d, 100))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	ft_putstr(find_number(d, 100)->word);
	return (print_hundreds_remainder(n, d));
}

int	print_thousands_scale(unsigned long long f, t_dict *d)
{
	if (!find_number(d, f))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	ft_putstr(find_number(d, f)->word);
	return (0);
}

int	print_thousands_remainder(unsigned long long n, unsigned long long f,
		t_dict *d)
{
	int	r;

	if (n % f)
	{
		ft_putstr(" ");
		r = print_thousands(n % f, d);
		if (r)
			return (1);
	}
	return (0);
}
