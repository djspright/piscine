/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:01:03 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/02 18:01:31 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		get_index(char c, char *base);
int		handle_spaces_sign(char *str, int *i);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;
	int	digit;

	i = 0;
	result = 0;
	base_len = ft_strlen(base);
	sign = handle_spaces_sign(str, &i);
	while (str[i])
	{
		digit = get_index(str[i], base);
		if (digit == -1)
			break ;
		result = result * base_len + digit;
		i++;
	}
	return (result * sign);
}

int	count_digits(int nbr, int base_len)
{
	int		count;
	long	num;

	count = 0;
	num = nbr;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		count++;
		num /= base_len;
	}
	return (count);
}

void	fill_result(char *result, long num, char *base_to, int base_len)
{
	int	pos;
	int	start_pos;

	start_pos = 0;
	while (result[start_pos] && result[start_pos] == '-')
		start_pos++;
	pos = count_digits(num, base_len) + start_pos - 1;
	while (num > 0)
	{
		result[pos--] = base_to[num % base_len];
		num /= base_len;
	}
}

char	*ft_itoa_base(int nbr, char *base_to)
{
	char	*result;
	int		digits;
	int		base_len;
	long	num;

	base_len = ft_strlen(base_to);
	num = nbr;
	digits = count_digits(num, base_len);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	if (num == 0)
		result[0] = base_to[0];
	else
		fill_result(result, num, base_to, base_len);
	return (result);
}

// int	main(int argc, char **argv)
// {
// 	char	*result;
// 	int		num;

// 	if (argc != 4)
// 	{
// 		printf("使用法: %s <数値> <元の進数> <変換先の進数>\n", argv[0]);
// 		return (1);
// 	}
// 	printf("入力: %s, 元の進数: %s, 変換先の進数: %s\n", argv[1], argv[2], argv[3]);
// 	num = ft_atoi_base(argv[1], argv[2]);
// 	printf("整数に変換: %d\n", num);
// 	result = ft_convert_base(argv[1], argv[2], argv[3]);
// 	if (result)
// 	{
// 		printf("変換結果: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("変換エラー: 無効な進数\n");
// 	}
// 	return (0);
// }
