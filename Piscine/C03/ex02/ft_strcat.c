/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:43:15 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/14 10:51:55 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned char	*dest_tmp;

	dest_tmp = (unsigned char *)dest;
	while (*dest_tmp != '\0')
		++dest_tmp;
	while (*src != '\0')
	{
		*dest_tmp = *((unsigned char *)src);
		++dest_tmp;
		++src;
	}
	*dest_tmp = '\0';
	return (dest);
}
