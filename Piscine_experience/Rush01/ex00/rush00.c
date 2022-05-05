/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyekim <dohyekim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:44:44 by dohyekim          #+#    #+#             */
/*   Updated: 2022/02/13 21:58:41 by juntakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern char	g_board[17];

int		check_colup(char	*board);
int		check_coldown(char	*board);
int		check_down_num(char	*board);
int		check_up_num(char	*board);
int		check_left_num(char	*board);
int		check_right_num(char	*board);
void	finish(char *board);

int	bbd(void)
{
	int	i;
	int	sum;
	int	j;

	sum = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			sum += g_board[i + j * 4] - '0';
		if (sum != 10)
			return (0);
		sum = 0;
	}
	return (1);
}

int	cbd(void)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	sum = 0;
	while (g_board[i])
	{
		sum += g_board[i] - 48;
		i++;
		if (i != 0 && i % 4 == 0 && sum != 10)
			return (0);
		if (i != 0 && i % 4 == 0)
			sum = 0;
	}
	return (1);
}

int	check_same_num_row(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_board[i])
	{
		j = i / 4 * 4;
		while (j < i && i % 4 != 0)
		{
			if (g_board[j] == g_board[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_same_num_col(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_board[i] == g_board[i + 4])
			return (0);
		if (g_board[i] == g_board[i + 8])
			return (0);
		if (g_board[i] == g_board[i + 12])
			return (0);
		if (g_board[i + 4] == g_board[i + 8])
			return (0);
		if (g_board[i + 4] == g_board[i + 12])
			return (0);
		if (g_board[i + 8] == g_board[i + 12])
			return (0);
		i++;
	}
	return (1);
}

void	rush(int	index, int	check, int	flag, char	*board)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	if (check == 5 || index == 16)
	{
		finish(board);
		return ;
	}
	if (flag == 1)
	{
		if (index > 1 && (g_board[index - 2] == g_board[index - 1]) && g_board[index - 2] != 0)
			return ;
		while (check < 5)
		{
			g_board[index] = check + '0';
			rush(index, check, 0, board);
			check++;
		}
	}
	else
		rush(index + 1, 1, 1, board);
}
