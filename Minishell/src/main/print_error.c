/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:21:54 by yehan             #+#    #+#             */
/*   Updated: 2022/08/04 14:13:22 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "../libft/include/libft.h"
#include "../lexer/token.h"

/** use to send messege to STDERR */
void	print_error_syntax_char(char err_char)
{
	ft_putstr_fd("lesh: syntax error near unexpected token", STDERR_FILENO);
	ft_putstr_fd(" \'", STDERR_FILENO);
	ft_putchar_fd(err_char, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
}

void	print_error_syntax_str(char *err_str)
{
	ft_putstr_fd("lesh: syntax error near unexpected token", STDERR_FILENO);
	ft_putstr_fd(" \'", STDERR_FILENO);
	ft_putstr_fd(err_str, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
}

void	print_error_redir(char *filename)
{
	ft_putstr_fd("lesh: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	ft_perror(char *message)
{
	ft_putstr_fd("lesh: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
