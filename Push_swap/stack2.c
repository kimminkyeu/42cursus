/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:42:50 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 20:47:05 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_push(t_stack *stack, int data)
{
	int		*pa_data;
	t_list	*last;

	pa_data = malloc(sizeof(*pa_data));
	if (pa_data != NULL)
	{
		*pa_data = data;
		last = ft_lstnew(pa_data);
		ft_lstadd_back(&(stack->bottom), last);
		stack->top = last;
		stack->size += 1;
		return (stack);
	}
	return (NULL);
}

t_list	*stack_get_node(t_stack *stack, size_t index)
{
	size_t	i;
	t_list	*curr;

	if (index == stack->size - 1)
		return (stack->top);
	if (index > stack->size - 1)
		return (NULL);
	i = 0;
	curr = stack->bottom;
	while (i < index)
	{
		curr = curr->next;
		i++;
	}
	return (curr);
}

const int	*stack_get_data(t_stack *stack, size_t index)
{
	t_list	*node;

	node = stack_get_node(stack, index);
	if (node == NULL)
		return (NULL);
	return ((const int *)node->content);
}
