/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:24:53 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/13 14:48:25 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

static int ft_pow(unsigned int num, int power)
{
	int	result;

	if (power < 0)
		return (-1);
	result = 1;
	while (power-- > 0)
		result *= num;
	return (result);
}

void ft_putnbr_fd(int n, int fd)
{
	size_t			nbr_len;
	char			digit;
	unsigned int	divider;
	unsigned int	n_tmp;

	if (n < 0)
	{
		n_tmp = -n;
		write(1, "-", 1);
	}
	else
		n_tmp = n;
	nbr_len = get_nbr_len(n_tmp);
	while (nbr_len > 0)
	{
		divider = ft_pow(10, nbr_len-1);
		digit = (n_tmp / divider) + '0';
		n_tmp %= divider;
		nbr_len--;
		write(fd, &digit, 1);
	}
}

/** #include <stdlib.h>
  * int main(int argc, char *argv[])
  * {
  *     (void)argc;
  *     ft_putnbr_fd(atoi(argv[1]), 1);
  *     return (0);
  * }
  *  */
