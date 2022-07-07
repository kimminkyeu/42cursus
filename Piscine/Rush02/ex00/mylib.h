/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:21:38 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/20 19:04:40 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 2048

int		ft_len(long nb);
void	tr_itoa(char *str, int num, int idx);
char	*ft_itoa(int nb);
void	ft_write_number_power(int size, char *buffer);
int		ft_strcmp(char *s1, char *s2);

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
int		ft_atoi(char *str);

int		ft_check_number(char *nbr);
void	print_dict_error(char *str, char *buffer);
int		ft_check_dict_error(char *buffer, char *to_find);

char	*ft_open_read(void);
char	*ft_open_read_argv(char *new_dict);

int		print_1digit(char *num_in, char *buffer, int *digit_len,
			int *num_index);
int		print_2digit(char *num_in, char *buffer, int *digit_len,
			int *num_index);
int		print_3digit(char *num_in, char *buffer, int *digit_len,
			int *num_index);
int		ft_convert_full_nbr(char *num_in, char *buffer);
int		ft_print_hundred_point(char *num_in, char *buffer, char *digit_1,
			int *index);

void	ft_write_nbr_into_ltrs(char *num_in, char *buffer);
int		ft_write_nbr_2digits(char *num_in, char *buffer);

#endif
