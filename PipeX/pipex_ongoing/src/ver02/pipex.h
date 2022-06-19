/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:32:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/05/13 21:34:38 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for exit and free, malloc
#include <stdio.h> // for perror
#include <unistd.h> // system call
#include <sys/wait.h> // wait function
#include <fcntl.h> // open

#include "../include/libft.h"

#define CHILD (0)
#define ERROR (-1)
#define READ_END (0)
#define WRITE_END (1)

#define NAME	(0)
#define OPTION	(1)

#define ACCESS_OK	(0)

extern char	**environ; // environment variable
					   //
extern void	pipex(int fd_start, int fd_end, char *av[], char **environ);


