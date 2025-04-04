/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanizak <stanizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:24:12 by shkondo           #+#    #+#             */
/*   Updated: 2025/03/31 17:48:15 by stanizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUF_SIZE
#  define BUF_SIZE 10000
# endif

typedef struct s_dict_entry
{
	unsigned long long	number;
	char				*word;
	struct s_dict_entry	*next;
}						t_dict_entry;

typedef struct s_dict
{
	t_dict_entry		*entries;
}						t_dict;

int						ft_strlen(char *str);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strdup(char *src);
void					ft_putstr(char *str);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_substr(char *s, int start, int len);

unsigned long long		ft_atoi(char *str);
int						ft_is_numeric(char *str);

t_dict					*create_dict(void);
int						parse_dict_file(char *filename, t_dict *dict);
t_dict_entry			*find_number(t_dict *dict, unsigned long long num);
void					free_dict(t_dict *dict);
void					append_entry(t_dict *dict, t_dict_entry *entry);
char					*trim_whitespace(char *str);
char					*read_file_content(char *filename);
t_dict_entry			*create_entry(char *num_str, char *word_str);
int						parse_line(char *line, t_dict *dict);
int						process_buffer_lines(char *buf, t_dict *dict);

int						convert_number(unsigned long long num, t_dict *dict);
void					print_tens_fallback(unsigned long long n);
int						print_small_number(unsigned long long n, t_dict *d);
int						print_tens_remainder(unsigned long long n, t_dict *d);
int						print_tens(unsigned long long n, t_dict *d);
int						print_hundreds_remainder(unsigned long long n,
							t_dict *d);
int						print_hundreds(unsigned long long n, t_dict *d);
int						print_thousands_scale(unsigned long long f, t_dict *d);
int						print_thousands_remainder(unsigned long long n,
							unsigned long long f, t_dict *d);
int						print_thousands(unsigned long long n, t_dict *d);

#endif
