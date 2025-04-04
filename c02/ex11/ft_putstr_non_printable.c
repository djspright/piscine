/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:39:21 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/27 04:20:32 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_puthex((unsigned char)str[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char	str[] = "Coucou\ntu vas bien ?";
// 	char	str2[] = "Test\twith\ttabs\tand\x01non\x1Fprintable\x7Fchars";

// 	ft_putstr_non_printable(str);
// 	ft_putchar('\n');
// 	ft_putstr_non_printable(str2);
// 	return (0);
// }
