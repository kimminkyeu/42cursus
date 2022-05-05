/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juntakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:15:33 by juntakim          #+#    #+#             */
/*   Updated: 2022/02/13 22:00:11 by juntakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern char	g_board[17];
extern int	g_count;

int	cbd(void);
int	bbd(void);
int	check_same_num_row(void);
int	check_same_num_col(void);
int	check_colup(char	*board);
int	check_coldown(char	*board);
int	cd(char	*board);
int	cu(char	*board);
int	cl(char	*board);
int	cr(char	*board);

void	finish(char *board)
{
	if (cbd() && bbd() && check_same_num_row() && check_same_num_col())
	{
		if (cd(board) && cl(board) && cu(board) && cr(board))
		{
			g_count = 1;
		}
	}
}
