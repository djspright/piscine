/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:35:53 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/26 20:50:54 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// int	main(void)
// {
// 	int	x;
// 	int	y;

// 	x = 4;
// 	y = 2;
// 	printf("before: %d, %d\n", x, y);
// 	ft_swap(&x, &y);
// 	printf("after: %d, %d\n", x, y);
// 	return (0);
// }
