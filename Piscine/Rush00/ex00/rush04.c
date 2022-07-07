/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soylee <soylee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:24:49 by soylee            #+#    #+#             */
/*   Updated: 2022/02/05 19:24:59 by soylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int row, int col, int end_row, int end_col)
{
	if (row == 1 && col == 1)
		ft_putchar('A');
	else if (row == 1 && col == end_col)
		ft_putchar('C');
	else if (row == end_row && col == 1)
		ft_putchar('C');
	else if (row == end_row && col == end_col)
		ft_putchar('A');
	else if (row == 1 || row == end_row)
		ft_putchar('B');
	else if (col == 1 || col == end_col)
		ft_putchar('B');
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
