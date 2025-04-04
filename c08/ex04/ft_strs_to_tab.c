/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:59:40 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/25 22:16:43 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_allocated(struct s_stock_str *tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
}

int	process_string(struct s_stock_str *tab, char *str, int index)
{
	tab[index].size = ft_strlen(str);
	tab[index].str = str;
	tab[index].copy = ft_strdup(str);
	if (!tab[index].copy)
		return (0);
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char *av[])
{
	int					i;
	struct s_stock_str	*tab;

	tab = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (!process_string(tab, av[i], i))
		{
			free_allocated(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[ac].str = 0;
	return (tab);
}

// int	main(int ac, char *av[])
// {
// 	int					i;
// 	struct s_stock_str	*stocks;

// 	stocks = ft_strs_to_tab(ac, av);
// 	if (stocks == NULL)
// 	{
// 		printf("Error\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (stocks[i].str != 0)
// 	{
// 		printf("String %d:\n", i);
// 		printf("  Original: [%s]\n", stocks[i].str);
// 		printf("  Size: %d\n", stocks[i].size);
// 		printf("  Copy: [%s]\n", stocks[i].copy);
// 		i++;
// 	}
// 	i = 0;
// 	while (stocks[i].str != 0)
// 	{
// 		free(stocks[i].copy);
// 		i++;
// 	}
// 	free(stocks);
// 	return (0);
// }
