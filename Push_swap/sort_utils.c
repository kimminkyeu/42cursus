/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:52:39 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/14 20:43:05 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** (only for sorted) roll back until target reaches top of the stack 
 * NOTE : 이 함수의 목적은 ra rra 둘중 무엇을 해야 더 빠른지 알아내서 실행하는 것*/
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
			break;
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

/* return index of 후속자 (차가 가장 적은 큰 수) */
int		find_next_bigger_int_idx(int target, t_stack2 *stack)
{
	size_t		i;
	/** TODO : okay to use int? */
	long long	diff;
	int			idx;
	t_list		*cur;

	i = 0;
	diff = INT_MAX;
	idx = -1;
	cur = stack->stack->bottom;

	// 바닥에서 올라가면서 체크
	while (i < stack->stack->size)
	{
		/** ft_printf("comparing... %d(idx%d):%d\n", *(int *)cur->content, idx, target); */
		if (*(int *)cur->content > target && (diff > *(int *)cur->content - target))
		{
			diff = *(int *)cur->content - target;
			idx = i;
			/** ft_printf("diff:%d, idx:%d, target:%d\n", diff, idx, target); */
		}
		cur = cur->next;
		i++;
	}
	if (idx == -1 || idx == (int)stack->stack->size - 1)
		return (-1);
	return (idx);
}

/* stack_b 의 원소를 이미 정렬된 stack_a의 올바른 위치에 삽입하기 위함. */
void	insert_to_fit(t_stack2 *dst_sorted, t_stack2 *src, t_darray *cmd)
{
	int			cnt;
	int			i;
	int			size_prev;

	if (src->stack->size == 0)
		return ;
	i = -1;
	size_prev = dst_sorted->stack->size;
	cnt = find_next_bigger_int_idx(*(int *)src->stack->top->content, dst_sorted);
	/** ft_printf("CNT : %d and size_prev : %d\n",cnt, size_prev); */
	if (cnt == -1)
		push(dst_sorted, src, cmd);
	else if (size_prev / 2 <= cnt)
	{
		while (++i < size_prev - cnt - 1)
			shift_up(dst_sorted, cmd);
		push(dst_sorted, src, cmd);
	}
	else
	{
		while (++i < cnt + 1)
			shift_down(dst_sorted, cmd);
		push(dst_sorted, src, cmd);
	}
}
