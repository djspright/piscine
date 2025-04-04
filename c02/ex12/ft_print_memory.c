/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:00:38 by shkondo           #+#    #+#             */
/*   Updated: 2025/04/04 04:35:39 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_is_last = 0;

void	print_memory_addr(void *addr)
{
	int		i;
	char	tmp;

	i = 15;
	while (i >= 0)
	{
		tmp = ((char)((unsigned long long int)addr >> 0x4 * i) & 0xf);
		if (tmp > 0x9)
			tmp += 'a' - 10;
		else
			tmp += '0';
		write(STDOUT_FILENO, &tmp, sizeof(char));
		i--;
	}
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
}

void	print_memory_hex_2words(void *addr, int i, unsigned int size)
{
	int		j;
	char	tmp;

	j = 0;
	while (j < 2)
	{
		if (((char *)addr)[i + j] == '\0' && (i + j) == (int)size)
		{
			g_is_last = 1;
			write(STDOUT_FILENO, "    ", sizeof(char) * 2 * (2 - j));
			break ;
		}
		else
		{
			tmp = '0' + (((char *)addr)[i + j] / 0x10);
			if (tmp > '9')
				tmp += ('a' - '9' - 1);
			write(STDOUT_FILENO, &tmp, sizeof(char));
			tmp = '0' + (((char *)addr)[i + j] % 0x10);
			if (tmp > '9')
				tmp += ('a' - '9' - 1);
			write(STDOUT_FILENO, &tmp, sizeof(char));
			j++;
		}
	}
}

void	print_memory_hex(void *addr, unsigned int size)
{
	int	i;

	i = 0;
	g_is_last = 0;
	while (i < 16)
	{
		if (g_is_last)
			write(STDOUT_FILENO, "    ", sizeof(char) * 4);
		else
			print_memory_hex_2words(addr, i, size);
		write(STDOUT_FILENO, " ", sizeof(char));
		i = i + 2;
	}
}

void	print_printable_binary(void *addr, unsigned int size)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < 16)
	{
		tmp = ((char *)addr)[i];
		if ((tmp >> 0x0 && tmp <= 0x1f) || tmp == 0x7f)
		{
			write(STDOUT_FILENO, ".", sizeof(char));
			if (((char *)addr)[i] == '\0' && i == (int)size)
				break ;
		}
		else
			write(STDOUT_FILENO, &tmp, sizeof(char));
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (addr);
	while (i < (size / 0x10) + 1)
	{
		print_memory_addr(addr + (i * 0x10));
		print_memory_hex(addr + (i * 0x10), size % 0x10);
		print_printable_binary(addr + (i * 0x10), size % 0x10);
		write(STDOUT_FILENO, "\n", sizeof(char));
		i++;
	}
	return (addr);
}

// #include <string.h>

// int	main(void)
// {
// 	char	str[] = {0x42, 0x6f, 0x6e, 0x6a, 0x6f, 0x75, 0x72, 0x20, 0x6c, 0x65,
// 			0x73, 0x20, 0x61, 0x6d, 0x69, 0x6e, 0x63, 0x68, 0x65, 0x73, 0x09,
// 			0x0a, 0x00, 0x63, 0x07, 0x20, 0x65, 0x73, 0x74, 0x20, 0x66, 0x6f,
// 			0x75, 0x09, 0x74, 0x6f, 0x75, 0x74, 0x09, 0x63, 0x65, 0x20, 0x71,
// 			0x75, 0x20, 0x6f, 0x6e, 0x20, 0x70, 0x65, 0x75, 0x74, 0x20, 0x66,
// 			0x61, 0x69, 0x72, 0x65, 0x20, 0x61, 0x76, 0x65, 0x63, 0x09, 0x0a,
// 			0x09, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x5f, 0x6d, 0x65, 0x6d, 0x6f,
// 			0x72, 0x79, 0x0a, 0x0a, 0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c,
// 			0x6f, 0x6c, 0x0a, 0x20, 0x00};

// 	ft_print_memory(str, 92);
// 	return (0);
// }
