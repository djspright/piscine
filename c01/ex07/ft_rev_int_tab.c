/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:59:12 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/26 20:50:01 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	end;

	i = 0;
	while (i < (size / 2))
	{
		end = size - i - 1;
		ft_swap(&tab[i], &tab[end]);
		i++;
	}
	return ;
}

// int	main(void)
// {
// 	int	i;
// 	int	arr[5] = {5, 4, 3, 2, 1};

// 	ft_rev_int_tab(arr, 5);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }
