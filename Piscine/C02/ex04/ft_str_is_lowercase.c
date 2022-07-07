/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:24:12 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/10 17:00:30 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	is_lowercase;

	is_lowercase = 1;
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
		{
			is_lowercase = 0;
			return (is_lowercase);
		}
		++str;
	}
	return (is_lowercase);
}
