/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:07:14 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/02 03:54:17 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (base_len);
}

int	handle_spaces_and_sign(char *str, int *i)
{
	int	sign;

	while (is_space(str[*i]))
		(*i)++;
	sign = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	long	nb;
	int		sign;
	int		digit;
	int		base_len;

	base_len = is_base_valid(base);
	if (base_len == 0)
		return (0);
	i = 0;
	sign = handle_spaces_and_sign(str, &i);
	nb = 0;
	digit = get_index(str[i], base);
	while (digit >= 0)
	{
		nb = nb * base_len + digit;
		i++;
		digit = get_index(str[i], base);
	}
	return ((int)(nb * sign));
}

// int	main(void)
// {
// 	printf("'42' in decimal: %d\n", ft_atoi_base("42", "0123456789"));
// 	printf("'101010' in binary: %d\n", ft_atoi_base("101010", "01"));
// 	printf("'2A' in hexadecimal: %d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
// 	printf("'52' in octal: %d\n", ft_atoi_base("52", "01234567"));
// 	printf("'-42' in decimal: %d\n", ft_atoi_base("-42", "0123456789"));
// 	printf("Invalid base (empty): %d\n", ft_atoi_base("42", ""));
// 	printf("Invalid base (single char): %d\n", ft_atoi_base("42", "0"));
// 	return (0);
// }
