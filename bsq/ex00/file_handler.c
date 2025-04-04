/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:13:25 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/02 02:54:30 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

void	close_file(int fd)
{
	close(fd);
}

char	*read_line_direct(int fd)
{
	char	*line;
	int		capacity;
	int		length;
	int		read_result;
	char	c;

	capacity = 64;
	length = 0;
	line = (char *)malloc(sizeof(char) * capacity);
	if (!line)
		return (NULL);
	while ((read_result = read(fd, &c, 1)) > 0 && c != '\n')
	{
		if (!process_char(c, &line, &length, &capacity))
			return (NULL);
	}
	if (length == 0 && read_result <= 0)
	{
		free(line);
		return (NULL);
	}
	line[length] = '\0';
	return (line);
}

char	**read_map_content(int fd, int rows)
{
	char	**map_content;
	int		i;

	map_content = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map_content)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_content[i] = read_line_direct(fd);
		if (!map_content[i])
		{
			free_map_partial(map_content, i);
			return (NULL);
		}
		i++;
	}
	map_content[rows] = NULL;
	return (map_content);
}

char	**read_map_from_stdin(int rows)
{
	return (read_map_content(0, rows));
}
