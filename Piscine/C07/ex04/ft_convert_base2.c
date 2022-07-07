/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:29:31 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/24 10:00:00 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern unsigned int	get_base_size(char *base);
extern int			is_valid(char *base);
extern int			ft_atoi_base(char *str, char *base);

long long	get_result_size(long long num, long long base_len)
{
	long long	size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	while (num != 0)
	{
		num /= base_len;
		++size;
	}
	return (size);
}

void	init_out(char *out_arr, int num, long long num_len, char *base)
{
	int			sign;
	int			i;
	long long	base_len;

	sign = 0;
	if (num < 0)
	{
		num = -num;
		out_arr[0] = '-';
		sign = 1;
	}
	base_len = get_base_size(base);
	i = 0;
	while (i < num_len)
	{
		out_arr[num_len + sign - i - 1] = base[num % base_len];
		num /= base_len;
		++i;
	}
	out_arr[num_len + (long long)sign] = '\0';
}

char	*ft_putnbr_base_malloc(long long nb, char *base)
{
	long long	num_len;
	long long	base_len;
	char		*out;
	int			sign;

	sign = 0;
	if (nb < 0)
		sign = 1;
	base_len = get_base_size(base);
	num_len = get_result_size(nb, base_len);
	out = malloc(sizeof(*out) * (num_len + sign + 1));
	if (!out)
		return (NULL);
	init_out(out, nb, num_len, base);
	return (out);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	decimal_num;
	char		*converted_num;

	if (!is_valid(base_from) || !is_valid(base_to))
		return (NULL);
	decimal_num = ft_atoi_base(nbr, base_from);
	converted_num = ft_putnbr_base_malloc(decimal_num, base_to);
	if (!converted_num)
		return (NULL);
	return (converted_num);
}
