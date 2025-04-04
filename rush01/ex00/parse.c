/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:59:36 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/24 05:13:32 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	parse_input(char *str, int views[16])
{
	int	i;
	int	j;

	if (!check_input_validity(str))
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			views[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input_validity(char *str)
{
	int	i;
	int	num_count;

	i = 0;
	num_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			num_count++;
			if (str[i + 1] != '\0' && str[i + 1] != ' ')
				return (0);
		}
		else if (str[i] == ' ')
		{
			if (str[i + 1] < '1' || str[i + 1] > '4')
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (num_count == 16);
}
