/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:39:21 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/27 20:50:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char	s1[] = "marvin";
// 	char	s2[] = "42tokyo";

// 	printf("%d\n", ft_str_is_printable(s1));
// 	printf("%d\n", ft_str_is_printable(s2));
// 	return (0);
// }
