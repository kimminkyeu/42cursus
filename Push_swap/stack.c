/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:58:17 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/14 20:58:59 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** function for lst_clear */
static void	del(void *data)
{
	if (data != NULL)
		free(data);
	data = NULL;
	return ;
}

/** data를 개별 malloc하지 않기 때문에 main문에서 stack을 만들어야 함. (scope 유지) */
t_stack	*stack_new(void)
{
	t_stack *tmp;

	tmp = ft_calloc(1, sizeof(*tmp));
	if (tmp != NULL)
	{
		tmp->bottom = NULL;
		tmp->top = NULL;
		tmp->size = 0;
	}
	return (tmp);
}

/** free stack elements, free stack. */
void	stack_delete(t_stack *stack)
{
	ft_lstclear(&(stack->bottom), del);
	free(stack);
	stack = NULL;
}

/** push data to top 
 * if error, returns NULL */
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
		// set it's last element to new element
		/** ft_printf("stack pushed data %d\n", *(int *)last->content); */
		stack->top = last;
		stack->size += 1;
		return (stack);
	}
	return (NULL);
}

/** pop data from top 
 * if error, returns NULL */
void	stack_pop(t_stack *stack)
{
	t_list *node;

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
	// find element before last
	node = stack->bottom;
	while (stack->size > 1 && node->next->next != NULL)
		node = node->next;
	ft_lstdelone(stack->top, del); node->next = NULL; stack->top = node;
	stack->top->next = NULL;
	stack->size -= 1;
}

/** used for indexing  --> return t_list element pointer */
t_list	*stack_get_node(t_stack *stack, size_t index)
{
	size_t	i;
	t_list	*curr;

	if (index == stack->size - 1)
		return (stack->top);
	// get total size.
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

const int * stack_get_data(t_stack *stack, size_t index)
{
	t_list*	node;
	
	node = stack_get_node(stack, index);
	if (node == NULL)
		return (NULL);
	return ((const int *)node->content);
}
