/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:57:48 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/07 11:00:53 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	buf;
	int		cnt;

	buf = 'a';
	cnt = 0;
	while (cnt < 26)
	{
		write(1, &buf, 1);
		++cnt;
		++buf;
	}
}
