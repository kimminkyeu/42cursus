/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:56:29 by han-yeseul        #+#    #+#             */
/*   Updated: 2022/08/04 10:22:37 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "../main/minishell.h"
# include "../lexer/token.h"

char	*expand_line_each(char *line, t_shell_config *config);
int		expand_file(t_token *tok, t_shell_config *config);

#endif/* REDIRECTION_H */
