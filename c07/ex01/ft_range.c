/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:56:02 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/26 12:23:02 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*result;
	int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	result = (int *)malloc(size * sizeof(int));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int	*range;
// 	int	i;

// 	min = 5;
// 	max = 10;
// 	range = ft_range(min, max);
// 	if (range == NULL)
// 	{
// 		printf("failure\n");
// 		return (1);
// 	}
// 	printf("範囲 %d から %d の値: ", min, max);
// 	i = 0;
// 	while (i < (max - min))
// 	{
// 		printf("%d ", range[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(range);
// 	return (0);
// }
