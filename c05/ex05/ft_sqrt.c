/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:23:03 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/20 21:55:20 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	long long	left;
	long long	right;
	long long	mid;

	if (nb <= 0)
		return (0);
	left = 1;
	right = nb;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid < nb)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("Square root of 16: %d\n", ft_sqrt(0));
// 	printf("Square root of 25: %d\n", ft_sqrt(1));
// 	printf("Square root of 36: %d\n", ft_sqrt(2));
// 	printf("Square root of 1: %d\n", ft_sqrt(1764));
// 	printf("Square root of 0: %d\n", ft_sqrt(-42));
// 	printf("Square root of -4: %d\n", ft_sqrt(1646114237));
// 	printf("Square root of 50: %d\n", ft_sqrt(2072434576));
// 	return (0);
// }
