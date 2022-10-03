/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:22:10 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/03 20:42:00 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <stdio.h>
# include "../../include/lexer.h"
# include "../../include/parse.h"

const char	*get_token_type(t_token_type type);
void		print_tokens(t_list *tokens);
void		print_tree(t_tree *root);
void		print_tree_node(t_list *token);

#endif /* HELPER_H */
