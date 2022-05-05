/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:48:30 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/13 22:00:20 by juntakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	g_board[17];
int		g_count;

void	rush(int index, int check, int flag, char *board);

char	*erase_space(char **argv)
{
	int		i;
	int		j;
	char	*board;

	board = (char *)malloc(sizeof (char) * 17);
	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != ' ')
		{
			board[j] = argv[1][i];
			j++;
		}
		i++;
	}
	board[j] = '\0';
	return (board);
}

int	input_error_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (!(('1' <= argv[1][i] && argv[1][i] <= '4') || argv[1][i] == ' '))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (i != 31)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*board;

	if (!(input_error_check(argc, argv)))
		return (0);
	i = -1;
	board = erase_space(argv);
	while (++i < 16)
		g_board[i] = '0';
	rush(0, 1, 1, board);
	i = 0;
	if (g_count >= 1)
	{
		while (g_board[i])
		{
			write(1, &g_board[i], 1);
			i++;
			if (i % 4 == 0 && i != 0)
				write(1, "\n", 1);
		}
	}
	else
		write(2, "Error\n", 6);
	free(board);
	return (0);
}
