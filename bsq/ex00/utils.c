/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:12:55 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/01 22:08:00 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fn_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(c));
}

void	fn_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(STDOUT_FILENO, str, sizeof(str[0]) * i);
}

int	fn_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	fn_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 0;
	result = 0;
	if (!str[i])
		return (0);
	while (str[i] >= '\t' && str[i] <= '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
