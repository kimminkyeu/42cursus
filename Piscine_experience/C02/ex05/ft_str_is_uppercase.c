/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:26:40 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/10 17:00:38 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	is_uppercase;

	is_uppercase = 1;
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
		{
			is_uppercase = 0;
			return (is_uppercase);
		}
		++str;
	}
	return (is_uppercase);
}
