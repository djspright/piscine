/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:10:39 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/28 16:04:39 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nb;
	char	c;

	base_len = is_base_valid(base);
	if (base_len == 0)
		return ;
	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	c = base[nb % base_len];
	write(1, &c, 1);
}

// int	main(void)
// {
// 	printf("42 in decimal: ");
// 	ft_putnbr_base(42, "0123456789");
// 	printf("\n");
// 	printf("42 in binary: ");
// 	ft_putnbr_base(42, "01");
// 	printf("\n");
// 	printf("42 in hexadecimal: ");
// 	ft_putnbr_base(42, "0123456789ABCDEF");
// 	printf("\n");
// 	printf("42 in octal: ");
// 	ft_putnbr_base(42, "01234567");
// 	printf("\n");
// 	printf("42 in custom base: ");
// 	ft_putnbr_base(42, "poneyvif");
// 	printf("\n");
// 	printf("-42 in decimal: ");
// 	ft_putnbr_base(-42, "0123456789");
// 	printf("\n");
// 	printf("0 in decimal: ");
// 	ft_putnbr_base(0, "0123456789");
// 	printf("\n");
// 	printf("INT_MIN in decimal: ");
// 	ft_putnbr_base(-2147483648, "0123456789");
// 	printf("\n");
// 	printf("Invalid base (empty): ");
// 	ft_putnbr_base(42, "");
// 	printf("[should print nothing]\n");
// 	printf("Invalid base (single char): ");
// 	ft_putnbr_base(42, "0");
// 	printf("[should print nothing]\n");
// 	printf("Invalid base (duplicates): ");
// 	ft_putnbr_base(42, "0123456789012");
// 	printf("[should print nothing]\n");
// 	printf("Invalid base (contains +): ");
// 	ft_putnbr_base(42, "0123+56789");
// 	printf("[should print nothing]\n");
// 	return (0);
// }
