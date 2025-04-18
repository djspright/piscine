#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 19:07:18 by shkondo           #+#    #+#              #
#    Updated: 2025/03/29 19:48:20 by shkondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS="-Wall -Wextra -Werror"

$CC $CFLAGS -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

ranlib libft.a

rm -f *.o

echo "libft.a has been created successflly"
