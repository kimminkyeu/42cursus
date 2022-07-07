/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:49:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/23 21:11:27 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

size_t	word_len(int size, char **strs)
{
	size_t	sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < size)
		sum += ft_strlen(strs[i++]);
	return (sum);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

void	join(int size, char *result, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size && strs[i])
	{
		ft_strcat(result, strs[i]);
		if (i < size)
			ft_strcat(result, sep);
		++i;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	size_t	total_len;

	if (!strs || !sep || size <= 0)
	{
		result = malloc(sizeof(*result));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	total_len = word_len(size, strs) + (ft_strlen(sep) * (size - 1));
	result = malloc((sizeof(*result) * total_len) + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	join(size, result, strs, sep);
	result[total_len] = '\0';
	return (result);
}
