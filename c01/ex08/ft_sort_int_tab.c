/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:34 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/26 20:49:44 by shkondo          ###   ########.fr       */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	int	i;
// 	int	arr[5] = {5, 2, 4, 3, 1};

// 	ft_sort_int_tab(arr, 5);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }
