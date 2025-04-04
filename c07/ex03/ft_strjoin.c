/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:26:34 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/26 12:28:04 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	calculate_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	if (size <= 0)
		return (0);
	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ft_strlen(sep) * (size - 1);
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;
	int		i;

	if (size <= 0)
	{
		result = (char *)malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	total_len = calculate_length(size, strs, sep);
	result = (char *)malloc((total_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	char	*strs[] = {"Hello", "world", "from", "42"};
// 	char	*sep;
// 	char	*result;

// 	sep = ", ";
// 	result = ft_strjoin(4, strs, sep);
// 	if (result)
// 	{
// 		printf("linked: %s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("failed\n");
// 	result = ft_strjoin(0, NULL, sep);
// 	if (result)
// 	{
// 		printf("empty: %s\n", result);
// 		free(result);
// 	}
// 	return (0);
// }
