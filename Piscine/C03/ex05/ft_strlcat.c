/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:01:59 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/14 20:22:07 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_len(char *data)
{
	unsigned int	cnt;

	cnt = 0;
	while (*data != '\0')
	{
		++cnt;
		++data;
	}
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	count;

	dest_len = get_len(dest);
	src_len = get_len(src);
	count = 0;
	while (*dest != '\0')
		++dest;
	while ((dest_len + count + 1 < size) && *src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
		++count;
	}
	*dest = '\0';
	if (size < dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
