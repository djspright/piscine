/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanizak <stanizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:01:46 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 17:44:40 by stanizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict_entry	*create_entry(char *num_str, char *word_str)
{
	t_dict_entry	*entry;

	entry = malloc(sizeof(t_dict_entry));
	if (!entry)
		return (NULL);
	entry->number = ft_atoi(num_str);
	entry->word = ft_strdup(word_str);
	if (!entry->word)
	{
		free(entry);
		return (NULL);
	}
	entry->next = NULL;
	return (entry);
}

int	parse_line(char *line, t_dict *dict)
{
	char			*colon;
	char			*num_str;
	char			*word_str;
	t_dict_entry	*entry;

	line = trim_whitespace(line);
	if (*line == '\0')
		return (0);
	colon = line;
	while (*colon && *colon != ':')
		colon++;
	if (*colon != ':')
		return (-1);
	*colon = '\0';
	num_str = trim_whitespace(line);
	word_str = trim_whitespace(colon + 1);
	if (!ft_is_numeric(num_str) || word_str[0] == '\0')
		return (-1);
	entry = create_entry(num_str, word_str);
	if (!entry)
		return (-1);
	append_entry(dict, entry);
	return (1);
}

int	process_buffer_lines(char *buf, t_dict *dict)
{
	char	*ptr;
	char	*newline;
	int		ret;

	ptr = buf;
	while (*ptr)
	{
		newline = ptr;
		while (*newline && *newline != '\n')
			newline++;
		if (*newline == '\n')
			*newline = '\0';
		ret = parse_line(ptr, dict);
		if (ret == -1)
			return (1);
		if (*newline == '\0')
			ptr = newline + 1;
		else
			break ;
	}
	return (0);
}
