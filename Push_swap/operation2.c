/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:48:04 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/18 18:13:32 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up(t_stack2 *stack, t_darray *cmd)
{
	t_list	*top1_node;
	t_list	*top2_node;
	t_list	*bottom_node;

	if (stack->stack->size < 2)
		return ;
	if (stack->a_or_b == A)
		push_cmd(cmd, RA);
	else
		push_cmd(cmd, RB);
	top1_node = stack->stack->top;
	bottom_node = stack->stack->bottom;
	top2_node = stack->stack->bottom;
	while (top2_node->next->next != NULL)
		top2_node = top2_node->next;
	stack->stack->top = top2_node;
	top2_node->next = NULL;
	top1_node->next = bottom_node;
	stack->stack->bottom = top1_node;
}

void	shift_up_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd)
{
	shift_up(stack_a, cmd);
	shift_up(stack_b, cmd);
}

void	shift_down(t_stack2 *stack, t_darray *cmd)
{
	t_list	*bottom1_node;
	t_list	*bottom2_node;

	if (stack->stack->size < 2)
		return ;
	bottom1_node = stack->stack->bottom;
	bottom2_node = stack->stack->bottom->next;
	if (stack->a_or_b == A)
		push_cmd(cmd, RRA);
	else
		push_cmd(cmd, RRB);
	bottom1_node->next = NULL;
	stack->stack->bottom = bottom2_node;
	stack->stack->top->next = bottom1_node;
	stack->stack->top = bottom1_node;
}

void	shift_down_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd)
{
	shift_down(stack_a, cmd);
	shift_down(stack_b, cmd);
}
