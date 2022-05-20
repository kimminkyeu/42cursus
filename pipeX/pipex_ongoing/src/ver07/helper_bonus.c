/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:46:37 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/15 17:24:37 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	exit_error(char *messege, int is_perror)
{
	if (is_perror)
		perror(messege);
	else
		ft_putstr_fd(messege, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_data(char **program_split, char **p_path_split)
{
	int	i;

	i = 0;
	while (program_split[i] != NULL)
		free(program_split[i++]);
	free(program_split);
	i = 0;
	while (p_path_split[i] != NULL)
		free(p_path_split[i++]);
	free(p_path_split);
}
