/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:19:58 by yehan             #+#    #+#             */
/*   Updated: 2022/08/04 10:58:44 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERROR_H
# define PRINT_ERROR_H

void	print_error_syntax_char(char err_char);
void	print_error_syntax_str(char *err_str);
void	print_error_redir(char *filename);
void	ft_perror(char *message);
void	print_error_cd(char *filename);
void	print_error_command(char *command);

#endif