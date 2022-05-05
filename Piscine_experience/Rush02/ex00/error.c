/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:45:33 by djeong            #+#    #+#             */
/*   Updated: 2022/02/20 19:05:43 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_check_number(char *nbr)
{
	int	i;
	int	nbr_size;

	i = 0;
	nbr_size = ft_strlen(nbr);
	if (nbr_size > 39)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_dict_error(char *str, char *buffer)
{
	if (ft_convert_full_nbr(str, buffer))
		write(2, "dict Error\n", 11);
}

int	ft_check_dict_error(char *buffer, char *to_find)
{
	int		size;
	char	*tmp;
	char	*start;

	start = ft_strstr(buffer, to_find);
	size = 0;
	while (start[size] >= '0' && start[size] <= '9')
		size++;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	tmp[size] = '\0';
	size = 0;
	while (start[size] >= '0' && start[size] <= '9')
	{
		tmp[size] = start[size];
		size++;
	}
	if (ft_strcmp(to_find, tmp) != 0)
	{
		free(tmp);
		return (1);
	}
	ft_write_nbr_into_ltrs(start, buffer);
	free(tmp);
	return (0);
}
