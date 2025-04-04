/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:39:21 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/27 19:32:25 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char	s1[] = "marvin";
// 	char	s2[] = "42tokyo";

// 	printf("%d\n", ft_str_is_lowercase(s1));
// 	printf("%d\n", ft_str_is_lowercase(s2));
// 	return (0);
// }
