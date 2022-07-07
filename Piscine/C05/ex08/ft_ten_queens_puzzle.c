/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:27:27 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/17 14:13:31 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_all(int board[])
{
	int		cnt;
	char	tmp;

	cnt = 0;
	while (cnt < 10)
	{
		tmp = board[cnt] + '0';
		write(1, &tmp, 1);
		++cnt;
	}
	write(1, "\n", 1);
}

int	my_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	is_queen_valid(int row_num, int board[])
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < row_num)
	{
		if (board[row_num] == board[i])
			flag = 0;
		if (board[row_num] - board[i] == my_abs(row_num - i))
			flag = 0;
		if (board[row_num] + row_num == board[i] + i)
			flag = 0;
		++i;
	}
	return (flag);
}

void	put_queen_recur(int row_num, int queen_col, int board[], int *cnt)
{
	if (row_num == 10)
	{
		++(*cnt);
		print_all(board);
		return ;
	}
	queen_col = 0;
	while (queen_col < 10)
	{
		board[row_num] = queen_col;
		if (is_queen_valid(row_num, board))
		{
			put_queen_recur(row_num + 1, queen_col, board, cnt);
		}
		++queen_col;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	answer_cnt;

	answer_cnt = 0;
	put_queen_recur(0, 0, board, &answer_cnt);
	return (answer_cnt);
}
