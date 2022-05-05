/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:37:52 by younglee          #+#    #+#             */
/*   Updated: 2022/02/05 20:37:54 by younglee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int row, int col, int end_row, int end_col)
{
	if (row == 1 && col == 1)
		ft_putchar('o');
	else if (row == 1 && col == end_col)
		ft_putchar('o');
	else if (row == end_row && col == 1)
		ft_putchar('o');
	else if (row == end_row && col == end_col)
		ft_putchar('o');
	else if (row == 1 || row == end_row)
		ft_putchar('-');
	else if (col == 1 || col == end_col)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 1;
	while (row <= y && x > 0)
	{
		col = 1;
		while (col <= x)
		{
			print(row, col, y, x);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
