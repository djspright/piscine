/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:07:50 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/26 19:07:58 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	int		len;

	if (!src)
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "42tokyo";
// 	char	*dup;

// 	dup = ft_strdup(src);
// 	if (dup == NULL)
// 	{
// 		printf("failure\n");
// 		return (1);
// 	}
// 	printf("source: %s\n", src);
// 	printf("duplicated: %s\n", dup);
// 	free(dup);
// 	return (0);
// }
