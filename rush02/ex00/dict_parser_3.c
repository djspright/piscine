/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanizak <stanizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:22:45 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 17:44:44 by stanizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_dict_file(char *filename, t_dict *dict)
{
	char	*buf;
	int		ret;

	buf = read_file_content(filename);
	if (!buf)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	ret = process_buffer_lines(buf, dict);
	free(buf);
	if (ret != 0)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	return (0);
}
