/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:10:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 09:47:51 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** allocate and init stack2 */
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

/** @ sa or sb 
 *  Swap the first 2 elements at the top of stack.
 *  Do nothing if there is only one or no elements. */
void	swap(t_stack2 *stack, t_darray *cmd)
{
	int	tmp1;
	int	tmp2;

	/** do i need pop? how about manupulating list? */
	if (stack->stack->size < 2)
		return ;

	if (stack->a_or_b == A)
		push_cmd(cmd, SA);
	else
		push_cmd(cmd, SB);

	
	/** TODO :do not use pop or push. just reconnect list nodes */
	// (1) pop 2 elements
	tmp1 = *(int *)stack->stack->top->content;
	stack_pop(stack->stack);
	tmp2 = *(int *)stack->stack->top->content;
	stack_pop(stack->stack);
	
	// (2) push again with reverse order
	stack_push(stack->stack, tmp1);
	stack_push(stack->stack, tmp2);
}

/** @ ss (swap top1 top2 -> a and b both) */
void	swap_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd)
{
	/** ft_printf("ss\n"); */
	swap(stack_a, cmd);
	swap(stack_b, cmd);
}

/** @ pa / pb.
 *  Take the first element at the top of src and put it at the top of dst.
 *  Do nothing if src is empty.*/
void	push(t_stack2 *dst, t_stack2 *src, t_darray *cmd)
{
	if (dst->a_or_b == A)
		push_cmd(cmd, PA);
	else
		push_cmd(cmd, PB);

	int	tmp1;
	if (src->stack->size > 0)
	{
		tmp1 = *(int *)(src->stack->top->content);
		stack_pop(src->stack);
		stack_push(dst->stack, tmp1);
	}
}

/** @ ra / rb : rotate a or rotate b.
 *  The first element becomes the last one. */
void	shift_up(t_stack2 *stack, t_darray *cmd)
{
	if (stack->a_or_b == A)
		push_cmd(cmd, RA);
	else
		push_cmd(cmd, RB);
	if (stack->stack->size < 2)
	{
		ft_printf("nothing happens (size < 2)\n");
		return ;
	}
	t_list *top1_node;
	t_list *top2_node;
	t_list *bottom_node;

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

/** @ rrr : rotate both (a and b) */
void	shift_up_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd)
{
	shift_up(stack_a, cmd);
	shift_up(stack_b, cmd);
}

/** @ reverse_rotate a or reverse_rotate b.
 *  The last element becomes the first one. */
void	shift_down(t_stack2 *stack, t_darray *cmd)
{
	/** pop bottom. then push it to top */
	/** int	tmp1; */
	/** int	*pa_data; */

	/** tmp1 = *(int *)stack->stack->bottom; */
	/** pa_data = malloc(sizeof(*pa_data)); */
	if (stack->stack->size < 2)
		return ;
	if (stack->a_or_b == A)
		push_cmd(cmd, RRA);
	else
		push_cmd(cmd, RRB);
	t_list *bottom1_node = stack->stack->bottom;
	t_list *bottom2_node = stack->stack->bottom->next;
	bottom1_node->next = NULL;
	stack->stack->bottom = bottom2_node;
	stack->stack->top->next = bottom1_node;
	stack->stack->top = bottom1_node;
}

/** reverse_rotate both. */
void	shift_down_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd)
{
	shift_down(stack_a, cmd);
	shift_down(stack_b, cmd);
}
