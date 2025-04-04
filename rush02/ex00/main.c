/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atanimot <atanimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:23:19 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 12:18:49 by atanimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	validate_and_convert(char *arg, unsigned long long *num)
{
	if (arg[0] == '-')
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!ft_is_numeric(arg))
	{
		ft_putstr("Error\n");
		return (1);
	}
	*num = ft_atoi(arg);
	return (0);
}

int	process_args(int argc, char **argv, char **dict_file,
		unsigned long long *num)
{
	if (argc != 2 && argc != 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		*dict_file = "numbers.dict";
		if (validate_and_convert(argv[1], num))
			return (1);
	}
	else
	{
		*dict_file = argv[1];
		if (validate_and_convert(argv[2], num))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dict				*dict;
	unsigned long long	num;
	int					ret;
	char				*dict_file;

	ret = process_args(argc, argv, &dict_file, &num);
	if (ret != 0)
		return (1);
	dict = create_dict();
	if (!dict)
		return (1);
	ret = parse_dict_file(dict_file, dict);
	if (ret != 0)
	{
		free_dict(dict);
		return (1);
	}
	ret = convert_number(num, dict);
	free_dict(dict);
	return (ret);
}
