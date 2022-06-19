/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:52:39 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/17 16:52:37 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack2 *stack)
{
	t_list	*cur;
	int		min;
	int		tmp;

	cur = stack->stack->bottom;
	min = INT_MAX;
	while (cur != NULL)
	{
		tmp = *(int *)cur->content;
		if (min > tmp)
			min = tmp;
		cur = cur->next;
	}
	return (min);
}

void	set_target_to_top(int target, t_stack2 *stack, t_darray *cmd)
{
	size_t	cnt;
	size_t	i;
	size_t	size_prev;
	t_list	*cur;

	size_prev = stack->stack->size;
	cur = stack->stack->bottom;
	if (stack->stack->size == 0)
		return ;
	cnt = -1;
	while (++cnt < size_prev)
	{
		if (*(int *)cur->content == target)
			break ;
		cur = cur->next;
	}
	i = -1;
	if (size_prev / 2 <= cnt)
		while (++i < size_prev - cnt - 1)
			shift_up(stack, cmd);
	else
		while (++i < cnt + 1)
			shift_down(stack, cmd);
}

int	find_next_bigger_int_idx(int target, t_stack2 *stack)
{
	size_t		i;
	long long	diff;
	int			idx;
	t_list		*cur;

	i = -1;
	diff = INT_MAX;
	idx = -1;
	cur = stack->stack->bottom;
	while (++i < stack->stack->size)
	{
		if (*(int *)cur->content > target && (diff \
					> *(int *)cur->content - target))
		{
			diff = *(int *)cur->content - target;
			idx = i;
		}
		cur = cur->next;
	}
	if (idx == (int)stack->stack->size - 1)
		return (-1);
	if (idx == -1)
		return (-2);
	return (idx);
}

void	insert_to_fit(t_stack2 *dst_sorted, t_stack2 *src, t_darray *cmd)
{
	int			cnt;
	int			i;
	int			size_prev;

	if (src->stack->size == 0)
		return ;
	i = -1;
	size_prev = dst_sorted->stack->size;
	cnt = find_next_bigger_int_idx(*(int *)src->stack->top->content, \
			dst_sorted);
	if (cnt == -2)
		set_target_to_top(find_min(dst_sorted), dst_sorted, cmd);
	else if (size_prev / 2 <= cnt)
		while (++i < size_prev - cnt - 1)
			shift_up(dst_sorted, cmd);
	else
		while (++i < cnt + 1)
			shift_down(dst_sorted, cmd);
	push(dst_sorted, src, cmd);
}
