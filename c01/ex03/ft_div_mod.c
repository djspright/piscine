/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:42:33 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/26 20:50:46 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int	main(void)
// {
// 	int	x;
// 	int	y;
// 	int	div;
// 	int	mod;

// 	x = 42;
// 	y = 24;
// 	ft_div_mod(x, y, &div, &mod);
// 	printf("%d, %d\n", div, mod);
// }
