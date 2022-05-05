/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:56:50 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/23 09:55:51 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_ascending;

	i = 0;
	is_ascending = 1;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			is_ascending = 0;
		++i;
	}
	if (is_ascending)
		return (1);
	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			is_ascending = 1;
		++i;
	}
	if (!is_ascending)
		return (1);
	return (0);
}
