/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juntakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:47:25 by juntakim          #+#    #+#             */
/*   Updated: 2022/02/13 21:56:59 by juntakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char	g_board[17];

int	cu(char *board)
{
	int	i;
	int	num;
	int	j;
	int	count;

	i = 0;
	while (i < 4)
	{
		j = i - 4;
		count = 0;
		num = 0;
		while (j < 16)
		{
			j += 4;
			if (num < g_board[j] - '0')
			{
				num = g_board[j] - '0';
				count++;
			}
		}
		if (count + '0' != board[i])
			return (0);
		i++;
	}
	return (1);
}

int	cd(char *board)
{
	int	i;
	int	num;
	int	j;
	int	count;

	i = 0;
	while (i < 4)
	{
		j = 16 + i;
		count = 0;
		num = 0;
		while (j > 0)
		{
			j -= 4;
			if (num < g_board[j] - '0')
			{
				num = g_board[j] - '0';
				count++;
			}
		}
		if (count + '0' != (board[i + 4]))
			return (0);
		i++;
	}
	return (1);
}

int	cl(char *board)
{
	int	i;
	int	num;
	int	j;
	int	count;

	i = 0;
	while (i < 4)
	{
		num = 0;
		j = 0;
		count = 0;
		while (j < 4)
		{
			if (num < g_board[j + i % 4 * 4] - '0')
			{
				num = g_board[j + i % 4 * 4] - '0';
				count++;
			}
			j++;
		}
		if (count + '0' != board[i + 8])
			return (0);
		i++;
	}
	return (1);
}

int	cr(char *board)
{
	int	i;
	int	num;
	int	j;
	int	count;

	i = 0;
	while (i < 4)
	{
		j = 0;
		count = 0;
		num = 0;
		while (j < 4)
		{
			if (num < g_board[i * 4 + 3 - j] - '0')
			{
				num = g_board[i * 4 + 3 - j] - '0';
				count++;
			}
			j += 1;
		}
		if (count + 48 != board[i])
			return (0);
		i++;
	}
	return (1);
}
