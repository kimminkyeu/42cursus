/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:05:03 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/14 11:12:22 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	cnt;
	char			*tmp;

	cnt = 0;
	tmp = dest;
	while (cnt < n && *src != '\0')
	{
		*tmp = *src;
		++tmp;
		++src;
		++cnt;
	}
	while (cnt < n)
	{
		*tmp = '\0';
		++cnt;
		++tmp;
	}
	return (dest);
}
