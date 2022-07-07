/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:55:26 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/17 20:22:30 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_1(char *str)
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

	param_cnt = argc - 1;
	while (param_cnt > 0)
	{
		print_1(argv[param_cnt]);
		--param_cnt;
	}
	return (0);
}
