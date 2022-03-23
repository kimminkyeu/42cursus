/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:58:52 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 16:40:24 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_nbr_len(unsigned int n)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (n == 0)
		nbr_len = 1;
	else
	{
		while (n > 0)
		{
			n /= 10;
			++nbr_len;
		}
	}
	return (nbr_len);
}

char *ft_itoa(int n)
{
	unsigned int	n_tmp;
	char			*pa_result;
	size_t			nbr_len;
	size_t			idx;
	size_t			sign;

	sign = 0;
	if (n < 0)
	{
		n_tmp = -n; 
		sign = 1;
	}
	else
		n_tmp = n;
	nbr_len = get_nbr_len(n_tmp);
	pa_result = malloc(sizeof(*pa_result) * (nbr_len + sign + 1));
	if (!pa_result)
		return (NULL);
	if (sign == 1)
		pa_result[0] = '-';
	idx = nbr_len;
	while (idx > 0)
	{
		pa_result[idx + sign - 1] = n_tmp % 10 + '0';
		n_tmp /= 10;
		--idx;
	}
	pa_result[nbr_len + sign] = '\0';
	return (pa_result);
}
/** 
  * #include <stdlib.h>
  * #include <stdio.h>
  * int main(int argc, char *argv[])
  * {
  *     (void)argc;
  *     char *arr = ft_itoa(atoi(argv[1]));
  *     printf("%s\n", arr);
  * } */
