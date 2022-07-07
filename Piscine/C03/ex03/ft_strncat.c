/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:48:56 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/14 19:46:53 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned char	*dest_tmp;

	dest_tmp = (unsigned char *)dest;
	if (nb == 0)
		return (dest);
	while (*dest_tmp != '\0')
		++dest_tmp;
	while (nb > 0 && *src != '\0')
	{
		*dest_tmp = *((unsigned char *)src);
		++dest_tmp;
		++src;
		--nb;
	}
	*dest_tmp = '\0';
	return (dest);
}
