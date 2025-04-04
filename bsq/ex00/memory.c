/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 02:51:14 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/02 02:53:26 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:45:12 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/02 01:45:12 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*resize_buffer(char *old_buffer, int old_size, int new_size)
{
	char	*new_buffer;
	int		i;

	new_buffer = (char *)malloc(sizeof(char) * new_size);
	if (!new_buffer)
	{
		free(old_buffer);
		return (NULL);
	}
	i = 0;
	while (i < old_size)
	{
		new_buffer[i] = old_buffer[i];
		i++;
	}
	free(old_buffer);
	return (new_buffer);
}

void	free_map_partial(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	process_char(char c, char **line, int *length, int *capacity)
{
	(*line)[*length] = c;
	(*length)++;
	if (*length >= *capacity - 1)
	{
		*capacity *= 2;
		*line = resize_buffer(*line, *length, *capacity);
		if (!(*line))
			return (0);
	}
	return (1);
}
