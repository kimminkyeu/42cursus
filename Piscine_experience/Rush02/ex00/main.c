/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:41:52 by djeong            #+#    #+#             */
/*   Updated: 2022/02/20 19:08:49 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	main(int argc, char **argv)
{
	char	*buffer;

	if (argc > 3 || argc == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
	{
		if (ft_check_number(argv[1]) == 0)
			return (0);
		buffer = ft_open_read();
		print_dict_error(argv[1], buffer);
		free(buffer);
	}
	else if (argc == 3)
	{
		if (ft_check_number(argv[2]) == 0)
			return (0);
		buffer = ft_open_read_argv(argv[1]);
		print_dict_error(argv[2], buffer);
		free(buffer);
	}
	return (0);
}
