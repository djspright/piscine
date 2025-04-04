/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_text_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:33:42 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 17:16:25 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_thousands(unsigned long long n, t_dict *d)
{
	unsigned long long	f;
	int					r;

	f = 1;
	while (f * 1000 <= n)
		f *= 1000;
	if (n < 1000)
		return (print_hundreds(n, d));
	r = print_thousands(n / f, d);
	if (r)
		return (r);
	ft_putstr(" ");
	if (print_thousands_scale(f, d))
		return (1);
	return (print_thousands_remainder(n, f, d));
}

int	convert_number(unsigned long long num, t_dict *dict)
{
	t_dict_entry	*e;

	if (num == 0)
	{
		e = find_number(dict, 0);
		if (!e)
		{
			ft_putstr("Dict Error\n");
			return (1);
		}
		ft_putstr(e->word);
		ft_putstr("\n");
		return (0);
	}
	if (print_thousands(num, dict) == 0)
		ft_putstr("\n");
	return (0);
}
