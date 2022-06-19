/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:47:56 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 22:36:41 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_merge_info(t_triangle *t3, t_merge_info *info, t_push_swap *data);
void	update_edge_value_3tri(t_merge_info *info);
void	push_target_3tri(t_merge_info *info, t_push_swap *data);
void	set_target_3tri(t_merge_info *info);

void	merge_3tri_each(t_triangle *t1, t_triangle *t2, t_triangle *t3, \
		t_push_swap *data)
{
	t_merge_info	info;

	info.t[0] = t1->size;
	info.t[1] = t2->size;
	info.t[2] = t3->size;
	set_merge_info(t3, &info, data);
	while (info.t[0] + info.t[1] + info.t[2] > 0)
	{	
		update_edge_value_3tri(&info);
		set_target_3tri(&info);
		push_target_3tri(&info, data);
	}
}

void	set_merge_info(t_triangle *t3, t_merge_info *info, t_push_swap *data)
{
	if (t3->a_or_b == A)
	{
		info->dst = data->stack_a;
		info->src = data->stack_b;
	}
	else if (t3->a_or_b == B)
	{
		info->dst = data->stack_b;
		info->src = data->stack_a;
	}
	if (t3->inc_or_dec == INC)
		info->max_or_min = MAX;
	else
		info->max_or_min = MIN;
}

void	update_edge_value_3tri(t_merge_info *info)
{
	if (info->src->stack->bottom != NULL)
		info->d3[0] = *(int *)info->src->stack->bottom->content;
	if (info->src->stack->top != NULL)
		info->d3[1] = *(int *)info->src->stack->top->content;
	if (info->dst->stack->bottom != NULL)
		info->d3[2] = *(int *)info->dst->stack->bottom->content;
}

void	set_target_3tri(t_merge_info *info)
{
	if (info->t[0] != 0 && info->t[1] != 0 && info->t[2] != 0)
		info->target = find_max_or_min(info->d3, 3, info->max_or_min);
	else if (info->t[0] == 0 && info->t[1] != 0 && info->t[2] != 0)
		info->target = find_max_or_min_2(info->d3[1], \
				info->d3[2], info->max_or_min);
	else if (info->t[0] != 0 && info->t[1] != 0 && info->t[2] == 0)
		info->target = find_max_or_min_2(info->d3[0], \
				info->d3[1], info->max_or_min);
	else if (info->t[0] != 0 && info->t[1] == 0 && info->t[2] != 0)
		info->target = find_max_or_min_2(info->d3[0], \
				info->d3[2], info->max_or_min);
	else if (info->t[0] == 0 && info->t[1] == 0 && info->t[2] != 0)
		info->target = info->d3[2];
	else if (info->t[0] == 0 && info->t[1] != 0 && info->t[2] == 0)
		info->target = info->d3[1];
	else if (info->t[0] != 0 && info->t[1] == 0 && info->t[2] == 0)
		info->target = info->d3[0];
}

void	push_target_3tri(t_merge_info *info, t_push_swap *data)
{
	if (info->t[0] > 0 && info->target == info->d3[0])
	{
		shift_down(info->src, data->cmd);
		push(info->dst, info->src, data->cmd);
		(info->t[0]) -= 1;
	}
	else if (info->t[1] > 0 && info->target == info->d3[1])
	{
		push(info->dst, info->src, data->cmd);
		(info->t[1]) -= 1;
	}
	else if (info->t[2] > 0 && info->target == info->d3[2])
	{
		shift_down(info->dst, data->cmd);
		(info->t[2]) -= 1;
	}
}
