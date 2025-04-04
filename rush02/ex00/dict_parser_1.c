/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanizak <stanizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:20:11 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 17:44:30 by stanizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <fcntl.h>

char	*trim_whitespace(char *str)
{
	char	*start;
	char	*end;

	start = str;
	while (*start && (*start == ' ' || *start == '\t' || *start == '\n'
			|| *start == '\r'))
		start++;
	end = start;
	while (*end)
		end++;
	if (end != start)
	{
		end--;
		while (end > start && (*end == ' ' || *end == '\t' || *end == '\n'
				|| *end == '\r'))
		{
			*end = '\0';
			end--;
		}
	}
	return (start);
}

char	*read_file_content(char *filename)
{
	int		fd;
	int		bytes_read;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = malloc(BUF_SIZE + 1);
	if (!buf)
	{
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, buf, BUF_SIZE);
	if (bytes_read < 0)
	{
		free(buf);
		close(fd);
		return (NULL);
	}
	buf[bytes_read] = '\0';
	close(fd);
	return (buf);
}
