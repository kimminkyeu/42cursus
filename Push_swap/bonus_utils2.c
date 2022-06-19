/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:16:46 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 19:27:13 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack_to_arr(int *arr, t_stack2 *stack)
{
	size_t	i;
	t_list	*tmp_node;

	i = 0;
	tmp_node = stack->stack->bottom;
	while (i < stack->stack->size)
	{
		arr[stack->stack->size - 1 - i] = *(int *)tmp_node->content;
		tmp_node = tmp_node->next;
		i++;
	}
}

static void	print_bar(int top_or_bottom)
{
	if (top_or_bottom == 1)
	{
		ft_printf("----------\t----------\n");
		ft_printf("|  TOP   |\t|  TOP   |\n");
		ft_printf("----------\t----------\n");
	}
	else
	{
		ft_printf("----------\t----------\n");
		ft_printf("| BOTTOM |\t| BOTTOM |\n");
		ft_printf("----------\t----------\n");
	}
}

void	render_stack(t_stack2 *stack_a, t_stack2 *stack_b)
{
	size_t	i;
	int		*tmp_a;
	int		*tmp_b;

	tmp_a = ft_calloc(stack_a->stack->size, sizeof(int));
	tmp_b = ft_calloc(stack_b->stack->size, sizeof(int));
	copy_stack_to_arr(tmp_a, stack_a);
	copy_stack_to_arr(tmp_b, stack_b);
	ft_printf("\n\nA-size: %d\tB-size: %d\n", stack_a->stack->size, \
			stack_b->stack->size);
	i = -1;
	print_bar(1);
	while (++i < stack_a->stack->size + stack_b->stack->size)
	{
		if (i < stack_a->stack->size)
			ft_printf("   %d", tmp_a[i]);
		ft_printf("\t\t");
		if (i < stack_b->stack->size)
			ft_printf("   %d", tmp_b[i]);
		ft_printf("\n");
	}
	print_bar(0);
	free(tmp_a);
	free(tmp_b);
}
