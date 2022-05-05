/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:37:51 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/20 20:44:44 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		++i;
		++str;
	}
	return (i);
}

char	*copy_str_malloc(char *str, int size)
{
	char	*data;
	int		i;

	if (size < 0)
		return (NULL);
	data = malloc((sizeof(*data) * (size_t)size) + 1);
	if (!data)
		return (NULL);
	i = 0;
	while (i < size)
	{
		data[i] = str[i];
		++i;
	}
	data[i] = '\0';
	return (data);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*mystruct;
	int			i;

	i = 0;
	mystruct = malloc(sizeof(*mystruct) * (ac + 1));
	if (!mystruct)
		return (NULL);
	while (i < ac)
	{
		mystruct[i].size = ft_strlen(av[i]);
		mystruct[i].str = av[i];
		mystruct[i].copy = copy_str_malloc(av[i], mystruct[i].size);
		++i;
	}
	mystruct[i].str = 0;
	return (mystruct);
}
