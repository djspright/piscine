/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:39:26 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/27 20:47:24 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char			src[] = "Hello, 42 Tokyo!";
// 	char			dest1[20];
// 	char			dest2[10];
// 	char			dest3[5];
// 	unsigned int	len1;
// 	unsigned int	len2;
// 	unsigned int	len3;

// 	len1 = ft_strlcpy(dest1, src, sizeof(dest1));
// 	printf("Test 1 (size=%lu):\n", sizeof(dest1));
// 	printf("Source: %s (length: %u)\n", src, len1);
// 	printf("Destination: %s\n\n", dest1);
// 	len2 = ft_strlcpy(dest2, src, sizeof(dest2));
// 	printf("Test 2 (size=%lu):\n", sizeof(dest2));
// 	printf("Source: %s (length: %u)\n", src, len2);
// 	printf("Destination: %s\n\n", dest2);
// 	len3 = ft_strlcpy(dest3, src, sizeof(dest3));
// 	printf("Test 3 (size=%lu):\n", sizeof(dest3));
// 	printf("Source: %s (length: %u)\n", src, len3);
// 	printf("Destination: %s\n", dest3);
// 	return (0);
// }
