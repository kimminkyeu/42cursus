/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:58:17 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 20:45:43 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del(void *data)
{
	if (data != NULL)
		free(data);
	data = NULL;
	return ;
}

t_stack	*stack_new(void)
{
	t_stack	*tmp;

	tmp = ft_calloc(1, sizeof(*tmp));
	if (tmp != NULL)
	{
		tmp->bottom = NULL;
		tmp->top = NULL;
		tmp->size = 0;
	}
	return (tmp);
}

void	stack_delete(t_stack *stack)
{
	ft_lstclear(&(stack->bottom), del);
	free(stack);
	stack = NULL;
}

void	stack_pop(t_stack *stack)
{
	t_list	*node;

	if (stack->size < 1)
		return ;
	if (stack->size == 1)
	{
		ft_lstdelone(stack->bottom, del);
		stack->bottom = NULL;
		stack->top = NULL;
		stack->size = 0;
		return ;
	}
	node = stack->bottom;
	while (stack->size > 1 && node->next->next != NULL)
		node = node->next;
	ft_lstdelone(stack->top, del);
	node->next = NULL;
	stack->top = node;
	stack->top->next = NULL;
	stack->size -= 1;
}
