/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:01:16 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/17 21:10:20 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_strcmp(char *a, char *b)
{
	while (*a == *b && *a && *b)
	{
		++a;
		++b;
	}
	return ((int)(*a - *b));
}

void	sort_ascii(int len, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < len - 1)
	{
		j = i;
		while (j + 1 < len)
		{
			if (my_strcmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			++j;
		}
		--len;
	}
}

void	print_2(char *str)
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
	int	i;

	i = 1;
	sort_ascii(argc, argv);
	while (i < argc)
	{
		print_2(argv[i]);
		++i;
	}
	return (0);
}
