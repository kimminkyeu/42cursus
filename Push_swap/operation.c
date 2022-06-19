/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:10:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:49:01 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack2	*init_stack2(int flag)
{
	t_stack2	*tmp;

	tmp = ft_calloc(1, sizeof(*tmp));
	tmp->a_or_b = flag;
	tmp->stack = stack_new();
	return (tmp);
}

void	delete_stack2(t_stack2 *stack)
{
	stack_delete(stack->stack);
	free(stack);
}

void	swap(t_stack2 *stack, t_darray *cmd)
{
	int	tmp1;
	int	tmp2;

	if (stack->stack->size < 2)
		return ;
	if (stack->a_or_b == A)
		push_cmd(cmd, SA);
	else
		push_cmd(cmd, SB);
	tmp1 = *(int *)stack->stack->top->content;
	stack_pop(stack->stack);
	tmp2 = *(int *)stack->stack->top->content;
	stack_pop(stack->stack);
	stack_push(stack->stack, tmp1);
	stack_push(stack->stack, tmp2);
}

void	swap_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd)
{
	swap(stack_a, cmd);
	swap(stack_b, cmd);
}

void	push(t_stack2 *dst, t_stack2 *src, t_darray *cmd)
{
	int	tmp1;

	if (dst->a_or_b == A)
		push_cmd(cmd, PA);
	else
		push_cmd(cmd, PB);
	if (src->stack->size > 0)
	{
		tmp1 = *(int *)(src->stack->top->content);
		stack_pop(src->stack);
		stack_push(dst->stack, tmp1);
	}
}
