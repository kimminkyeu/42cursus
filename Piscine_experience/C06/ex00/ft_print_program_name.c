/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:59:22 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/17 20:56:31 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*program;

	--argc;
	program = argv[0];
	while (*program)
	{
		write(1, program, 1);
		++program;
	}
	write(1, "\n", 1);
	return (0);
}
