/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:51:25 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/14 19:47:02 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmp;
	char	*i;
	char	*j;

	tmp = str;
	if (*to_find == '\0')
		return (str);
	while (*tmp != '\0')
	{
		i = tmp;
		j = to_find;
		while (*i != '\0' && *j != '\0' && *i == *j)
		{
			++i;
			++j;
			if (*j == '\0')
				return (tmp);
		}
		++tmp;
	}
	return (0);
}
