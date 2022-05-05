/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:09:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/07 11:40:55 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	buf1;
	char	buf2;

	buf1 = 'N';
	buf2 = 'P';
	if (n < 0)
		write(1, &buf1, 1);
	else
		write(1, &buf2, 1);
}
