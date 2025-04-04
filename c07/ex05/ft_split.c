/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:10:49 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 13:50:37 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_separator(str[i], charset))
		{
			count++;
			while (str[i] && !ft_is_separator(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_separator(str[i], charset))
		i++;
	return (i);
}

char	*ft_strdup(char *str, char *charset)
{
	int		i;
	int		len;
	char	*dst;

	len = ft_strlen(str, charset);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	result = (char **)malloc((ft_count_words(str, charset) + 1)
			* sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i], charset))
			i++;
		if (str[i])
		{
			result[j++] = ft_strdup(&str[i], charset);
			while (str[i] && !ft_is_separator(str[i], charset))
				i++;
		}
	}
	result[j] = 0;
	return (result);
}

// int	main(void)
// {
// 	char	str[] = "Gaspard de la nuit\tOndine,Le Gibet:Scarbo";
// 	char	charset[] = " ,.:;\t";
// 	char	**result;
// 	int		i;

// 	result = ft_split(str, charset);
// 	if (!result)
// 	{
// 		printf("Error: Memory allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	printf("Original string: \"%s\"\n", str);
// 	printf("Charset: \"%s\"\n\n", charset);
// 	printf("Split result:\n");
// 	while (result[i])
// 	{
// 		printf("[%d]: \"%s\"\n", i, result[i]);
// 		i++;
// 	}
// 	// メモリ解放
// 	i = 0;
// 	while (result[i])
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
