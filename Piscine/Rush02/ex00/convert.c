/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:25:21 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/20 19:05:30 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	print_1digit(char *num_in, char *buffer, int *digit_len, int *index)
{
	char	*digit_1;

	digit_1 = ft_itoa(num_in[*index] - '0');
	if (ft_check_dict_error(buffer, digit_1))
	{
		free(digit_1);
		return (1);
	}
	*digit_len -= 1;
	*index += 1;
	ft_write_number_power(*digit_len, buffer);
	free(digit_1);
	return (0);
}

int	print_2digit(char *num_in, char *buffer, int *digit_len, int *index)
{
	char	*digit_10;
	int		tmp;

	tmp = (num_in[*index] - '0') * 10 + num_in[*index + 1] - '0';
	digit_10 = ft_itoa(tmp);
	if (ft_write_nbr_2digits(digit_10, buffer))
	{
		free(digit_10);
		return (1);
	}
	*index += 2;
	*digit_len -= 2;
	ft_write_number_power(*digit_len, buffer);
	free(digit_10);
	return (0);
}

int	print_3digit(char *num_in, char *buffer, int *digit_len, int *index)
{
	char	*digit_10;
	char	*digit_1;
	int		tmp;

	digit_1 = ft_itoa(num_in[*index] - '0');
	if (ft_print_hundred_point(num_in, buffer, digit_1, index))
		return (1);
	tmp = (num_in[*index + 1] - '0') * 10 + (num_in[*index + 2] - '0');
	digit_10 = ft_itoa(tmp);
	if (num_in[*index + 1] != '0' || num_in[*index + 2] != '0')
	{
		write(1, " ", 1);
		ft_write_nbr_2digits(digit_10, buffer);
	}
	*digit_len -= 3;
	if ((*digit_len >= 3) && (num_in[*index] != '0' || num_in[*index \
			+ 1] != '0' || num_in[*index + 2] != '0'))
		ft_write_number_power(*digit_len, buffer);
	*index += 3;
	free(digit_1);
	free(digit_10);
	return (0);
}

int	ft_print_hundred_point(char *num_in, char *buffer, char *digit_1,
		int *index)
{
	if (num_in[*index] != '0')
	{
		if (*index != 0)
			write(1, " ", 1);
		if (ft_check_dict_error(buffer, digit_1))
		{
			free(digit_1);
			return (1);
		}
		write(1, " ", 1);
		if (ft_check_dict_error(buffer, "100"))
		{
			free(digit_1);
			return (1);
		}
	}
	return (0);
}

int	ft_convert_full_nbr(char *num_in, char *buffer)
{
	int	digit_len;
	int	i;

	i = 0;
	digit_len = ft_strlen(num_in);
	while (digit_len > 0)
	{
		if (digit_len > 1 && num_in[0] == '0')
		{
			write(1, "Dict Error\n", 11);
			return (1);
		}
		if ((digit_len % 3 == 1) && (print_1digit(num_in, buffer, &digit_len, \
					&i)))
			return (1);
		else if ((digit_len % 3 == 2) && (print_2digit(num_in, buffer, \
						&digit_len, &i)))
			return (1);
		else if ((digit_len % 3 == 0) && (print_3digit(num_in, buffer, \
						&digit_len, &i)))
			return (1);
	}
	return (0);
}
