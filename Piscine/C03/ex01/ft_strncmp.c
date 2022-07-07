/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:40:49 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/12 11:42:57 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (n == 0)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n > 1 && *a == *b && *a != '\0' && *b != '\0')
	{
		++a;
		++b;
		--n;
	}
	return (*a - *b);
}
