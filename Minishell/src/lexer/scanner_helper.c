/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:52:12 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/04 14:38:54 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "../../include/libft.h"
#include "../main/helper.h"
#include "../main/print_error.h"
#include "scanner.h"

bool	is_meta_token_overlap(t_list *token_list)
{
	t_list	*cur;
	t_token	*tok_1;
	t_token	*tok_2;

	if (token_list == NULL)
		return (false);
	cur = token_list;
	while (cur->next != NULL)
	{
		tok_1 = cur->content;
		tok_2 = cur->next->content;
		if (is_meta_token_type(tok_1->type) && is_meta_token_type(tok_2->type))
		{
			print_error_syntax_str(tok_1->str->text);
			return (true);
		}
		cur = cur->next;
	}
	return (false);
}

static bool	is_last_token_meta(t_token *tok_1)
{
	if (tok_1->type == E_TYPE_REDIRECT)
	{
		print_error_syntax_str("newline");
		return (true);
	}
	else if (is_meta_token_type(tok_1->type))
	{
		print_error_syntax_str(tok_1->str->text);
		return (true);
	}
	if (tok_1->str->text[0] == ')')
	{
		print_error_syntax_char(tok_1->str->text[0]);
		return (true);
	}
	return (false);
}

/** NOTES:
 * 1) valid BRACKET type is always covered with a pair like: [ (command) ]
 * STEPS:
 * 1) if start with |, ||, &, &&, print eror
 * 2) if end with <, <<, >, >>, print error
 * 3) if end with |, ||, &, &&, print eror
 * 4) if end with single bracket ), print error
 * 5) if end with (...., print error
 */
bool	is_start_or_end_with_meta(t_list *token_list)
{
	t_list	*cur;
	t_token	*tok;

	cur = token_list;
	tok = cur->content;
	if (is_meta_token_type(tok->type))
	{
		print_error_syntax_str(tok->str->text);
		return (true);
	}
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	tok = cur->content;
	if (is_last_token_meta(tok))
		return (true);
	else if (tok->type == E_TYPE_BRACKET \
				&& is_bracket_unclosed(tok))
		return (true);
	else
		return (false);
}

bool	is_invalid_token_type(t_list *token_list)
{
	t_list	*cur;
	t_token	*tok;

	cur = token_list;
	while (cur != NULL)
	{
		tok = cur->content;
		if (tok->type == E_TYPE_AMPERSAND)
		{
			print_error_syntax_str(tok->str->text);
			return (true);
		}
		if (tok->type == E_TYPE_BRACKET)
		{
			if (is_bracket_unclosed(tok))
				return (true);
		}
		cur = cur->next;
	}
	return (false);
}
