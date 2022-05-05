/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:07:16 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/17 20:22:20 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int		param_cnt;
	int		i;

	i = 1;
	param_cnt = argc;
	while (i < param_cnt)
	{
		print(argv[i]);
		++i;
	}
	return (0);
}
