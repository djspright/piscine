/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanizak <stanizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:17:34 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 17:44:48 by stanizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*create_dict(void)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->entries = NULL;
	return (dict);
}

void	free_dict(t_dict *dict)
{
	t_dict_entry	*entry;
	t_dict_entry	*tmp;

	if (!dict)
		return ;
	entry = dict->entries;
	while (entry)
	{
		tmp = entry->next;
		free(entry->word);
		free(entry);
		entry = tmp;
	}
	free(dict);
}

t_dict_entry	*find_number(t_dict *dict, unsigned long long num)
{
	t_dict_entry	*entry;

	if (!dict)
		return (NULL);
	entry = dict->entries;
	while (entry)
	{
		if (entry->number == num)
			return (entry);
		entry = entry->next;
	}
	return (NULL);
}

void	append_entry(t_dict *dict, t_dict_entry *entry)
{
	t_dict_entry	*tmp;

	if (!dict || !entry)
		return ;
	if (!dict->entries)
		dict->entries = entry;
	else
	{
		tmp = dict->entries;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = entry;
	}
}
