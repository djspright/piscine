/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atanimot <atanimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:24:02 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 20:12:43 by atanimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	isdigit_custom(char c)
{
	return (c >= '0' && c <= '9');
}

int	isspace_custom(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

unsigned long long	ft_atoi(char *num)
{
	unsigned long long	value;

	value = 0;
	while (isspace_custom(*num))
	{
		num++;
	}
	if (*num == '-' || *num == '+')
	{
		num++;
	}
	while (*num && isdigit_custom(*num))
	{
		value = value * 10 + (*num - '0');
		num++;
	}
	return (value);
}

int	ft_is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
