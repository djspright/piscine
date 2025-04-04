/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 07:31:06 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/20 18:59:28 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	validate_and_convert(char *str, int num)
{
	int	i;

	num = 0;
	i = 0;
	if (str[i] == '-' || !str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (num > (2147483647 - (str[i] - '0')) / 10)
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num > 0);
}

int	ft_atoi(char *str)
{
	int	num;
	int	result;

	result = validate_and_convert(str, &num);
	if (result == -1)
	{
		ft_putstr("Error: width and height are too large.\n");
		return (-1);
	}
	if (result == 0)
	{
		ft_putstr("Error: width and height must be positive integers.\n");
		return (-1);
	}
	return (num);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 3)
	{
		ft_putstr("Usage: ./rush03 width height\n");
		return (1);
	}
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (x == -1 || y == -1)
		return (1);
	rush(x, y);
	return (0);
}
