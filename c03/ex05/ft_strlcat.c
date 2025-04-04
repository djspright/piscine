/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 02:13:24 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/28 03:43:51 by shkondo          ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
// int	main(void)
// {
// 	size_t	result;

// 	char dest[10] = "Hello"; // 長さ5のバッファ（容量10）
// 	char src[] = ", world!"; // 長さ8
// 	result = ft_strlcat(dest, src, sizeof(dest));
// 	// destは "Hello, wo" になる（ヌル文字含む）
// 	// resultは 13 (5 + 8) になる
// 	// result > sizeof(dest) なので切り詰めが発生したことがわかる
// }
