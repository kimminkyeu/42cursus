/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:41:53 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/20 19:08:15 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_write_nbr_into_ltrs(char *num_in, char *buffer)
{
	char	*start_str;
	int		i;

	start_str = ft_strstr(buffer, num_in);
	i = 0;
	while (start_str[i] && start_str[i] != '\n')
	{
		while (start_str[i] != ':')
			i++;
		if (start_str[i] == ':')
			i++;
		while (start_str[i] == ' ')
			i++;
		while (start_str[i] >= 32 && start_str[i] <= 126)
		{
			write(1, &start_str[i], 1);
			i++;
		}
	}
}

int	ft_write_nbr_2digits(char *num_in, char *buffer)
{
	char	*digit_10;
	char	*digit_1;

	if ((ft_strlen(num_in) == 2 && num_in[0] != '1' && num_in[1] != '0'))
	{
		digit_10 = ft_itoa((num_in[0] - '0') * 10);
		if (ft_check_dict_error(buffer, digit_10))
		{
			free(digit_10);
			return (1);
		}
		write(1, " ", 1);
		digit_1 = ft_itoa(num_in[1] - '0');
		if (ft_check_dict_error(buffer, digit_1))
		{
			free(digit_10);
			free(digit_1);
			return (1);
		}
		free(digit_10);
		free(digit_1);
	}
	else if (ft_check_dict_error(buffer, num_in))
		return (1);
	return (0);
}
