/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:31:41 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/11 16:17:54 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 *		(1) if c is lowercase, change it to uppercase. if uppercase, return c
 * */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 040);
	else
		return (c);
}
