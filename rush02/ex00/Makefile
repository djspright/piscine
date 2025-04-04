# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 14:28:37 by shkondo           #+#    #+#              #
#    Updated: 2025/03/31 17:17:14 by shkondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRCS = main.c dict_parser_1.c dict_parser_2.c dict_parser_3.c dict_reader.c \
       number_to_text_1.c number_to_text_2.c number_to_text_3.c \
       utils_num.c utils_str_1.c utils_str_2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
