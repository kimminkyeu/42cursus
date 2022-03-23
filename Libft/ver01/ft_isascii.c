/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:00:50 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 13:21:58 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 혹시 extended ascii를 고려해야 하는건가? 글쎄.. 이건 출력하는게 아닌데?*/

int	ft_isascii(int c)
{
	/** asii 범위 octal 127 맞는지 체크
	 * any character between 0 and octal 0177(which is 127 decimal) inclusive. */
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
