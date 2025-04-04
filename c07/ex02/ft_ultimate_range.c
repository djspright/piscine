/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:16:02 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/26 12:28:23 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int	*range;
// 	int	size;
// 	int	i;

// 	min = 5;
// 	max = 10;
// 	size = ft_ultimate_range(&range, min, max);
// 	if (size == -1)
// 	{
// 		printf("failure\n");
// 		return (1);
// 	}
// 	printf("returned size: %d\n", size);
// 	printf("範囲 %d から %d の値: ", min, max);
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", range[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(range);
// 	return (0);
// }
