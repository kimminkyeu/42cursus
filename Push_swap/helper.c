/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:41:40 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 15:08:54 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

static void	swap_data(int *data, size_t idx1, size_t idx2)
{
	int	tmp;

	tmp = data[idx1];
	data[idx1] = data[idx2];
	data[idx2] = tmp;
}

static int	find_pivot_inc(int *data, size_t start, size_t end)
{
	size_t	left;
	size_t	right;
	int		pivot;

	left = start + 1;
	right = end;
	pivot = data[start];
	while (left < right)
	{
		while (pivot > data[left])
			++left;
		while (data[right] > pivot)
			--right;
		if (left < right)
			swap_data(data, left, right);
	}
	if (left > right || data[start] > data[right])
		swap_data(data, start, right);
	return (right);
}

static int	find_pivot_dec(int *data, size_t start, size_t end)
{
	size_t	left;
	size_t	right;
	int		pivot;

	left = start + 1;
	right = end;
	pivot = data[start];
	while (left < right)
	{
		while (pivot < data[left])
			++left;
		while (data[right] < pivot)
			--right;
		if (left < right)
			swap_data(data, left, right);
	}
	if (left > right || data[start] < data[right])
		swap_data(data, start, right);
	return (right);
}

void	quick_sort(int *data, int start, int end, int inc_or_dec)
{
	size_t	pivot_idx;

	if (start < end)
	{
		if (inc_or_dec == INC)
			pivot_idx = find_pivot_inc(data, start, end);
		else
			pivot_idx = find_pivot_dec(data, start, end);
		quick_sort(data, start, pivot_idx - 1, inc_or_dec);
		quick_sort(data, pivot_idx + 1, end, inc_or_dec);
	}
}

const char*	get_cmd_string(int cmd_code)
{
	if (cmd_code == PA)
		return ("pa");
	else if (cmd_code == PB)
		return ("pb");
	else if (cmd_code == SA)
		return ("sa");
	else if (cmd_code == SB)
		return ("sb");
	else if (cmd_code == RA)
		return ("ra");
	else if (cmd_code == RB)
		return ("rb");
	else if (cmd_code == RRA)
		return ("rra");
	else if (cmd_code == RRB)
		return ("rrb");
	else if (cmd_code == SS)
		return ("ss");
	else if (cmd_code == RR)
		return ("rr");
	else if (cmd_code == RRR)
		return ("rrr");
	else
		return ("???");
}

void	print_cmd(t_darray *cmd)
{
	size_t	i;
	int		cmd_code;

	i = -1;
	while (++i < cmd->size)
	{
		cmd_code = *((int *)(cmd->data[i]));
		ft_printf("%s ", get_cmd_string(cmd_code));
	}
	ft_printf("Total Count : %d\n", cmd->size);
}

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

void	render_stack(t_stack2 *stack_a, t_stack2 *stack_b)
{
	size_t	i;
	int		tmp_a[stack_a->stack->size];
	int		tmp_b[stack_b->stack->size];

	copy_stack_to_arr(tmp_a, stack_a);
	copy_stack_to_arr(tmp_b, stack_b);
	ft_printf("\n\n");
	ft_printf("A-size: %d\tB-size: %d\n", stack_a->stack->size, stack_b->stack->size);
	ft_printf("----------\t----------\n");
	ft_printf("|  TOP   |\t|  TOP   |\n");
	ft_printf("----------\t----------\n");
	i = -1;
	while (++i < stack_a->stack->size + stack_b->stack->size)
	{
		if (i < stack_a->stack->size)
			ft_printf("   %d", tmp_a[i]);
		ft_printf("\t\t");
		if (i < stack_b->stack->size)
			ft_printf("   %d", tmp_b[i]);
		ft_printf("\n");
	}
	ft_printf("----------\t----------\n");
	ft_printf("| BOTTOM |\t| BOTTOM |\n");
	ft_printf("----------\t----------\n");
}

void	push_cmd(t_darray *cmd, int	cmd_code)
{
	int	*cmd_info;

	cmd_info = malloc(sizeof(*cmd_info));
	*cmd_info = cmd_code;
	darray_push_back(cmd, cmd_info);
}

size_t	optimize_2cmd(t_darray *prev_cmd, t_darray *new_cmd)
{
	size_t	i;
	int		cmd_code1;
	int		cmd_code2;

	i = 0;
	while (i < prev_cmd->size - 1)
	{
		cmd_code1 = *(int *)(prev_cmd->data)[i];
		cmd_code2 = *(int *)(prev_cmd->data)[i + 1];
		if (cmd_code1 == SA && cmd_code2 == SB)
		{
			push_cmd(new_cmd, SS);
			i += 2;
		}
		else if (cmd_code1 == RA && cmd_code2 == RB)
		{
			push_cmd(new_cmd, RR);
			i += 2;
		}
		else if (cmd_code1 == RRA && cmd_code2 == RRB)
		{
			push_cmd(new_cmd, RRR);
			i += 2;
		}
		else if ((cmd_code1 == RRA && cmd_code2 == RA) \
				|| (cmd_code1 == RRB && cmd_code2 == RB) \
				|| (cmd_code1 == RA && cmd_code2 == RRA) \
				|| (cmd_code1 == RB && cmd_code2 == RRB) \
				|| (cmd_code1 == PA && cmd_code2 == PB) \
				|| (cmd_code1 == PB && cmd_code2 == PA))
		{
			i += 2;
		}
		else
		{
			push_cmd(new_cmd, cmd_code1);
			i += 1;
		}
	}
	if (i == prev_cmd->size - 1)
			push_cmd(new_cmd, cmd_code2);
	return (new_cmd->size);
}

size_t	optimize_3cmd(t_darray *prev_cmd, t_darray *new_cmd)
{
	size_t	i;
	int		cmd_code1;
	int		cmd_code2;
	int		cmd_code3;

	i = 0;
	while (i < prev_cmd->size - 2)
	{
		cmd_code1 = *(int *)(prev_cmd->data)[i];
		cmd_code2 = *(int *)(prev_cmd->data)[i + 1];
		cmd_code3 = *(int *)(prev_cmd->data)[i + 2];
		if (cmd_code1 == RA && cmd_code2 == PB && cmd_code3 == RRA)
		{
			push_cmd(new_cmd, SA);
			push_cmd(new_cmd, PB);
			i += 3;
		}
		else if (cmd_code1 == RB && cmd_code2 == PA && cmd_code3 == RRB)
		{
			push_cmd(new_cmd, SB);
			push_cmd(new_cmd, PA);
			i += 3;
		}
		else
		{
			push_cmd(new_cmd, cmd_code1);
			i += 1;
		}
	}
	if (i == prev_cmd->size - 2)
	{
		push_cmd(new_cmd, cmd_code2);
		push_cmd(new_cmd, cmd_code3);
	}
	return (new_cmd->size);
}


void	optimize_cmd(t_darray **prev_cmd)
{
	t_darray	*new_cmd;

	new_cmd = new_darray_malloc((*prev_cmd)->size);
	while (optimize_2cmd(*prev_cmd, new_cmd) != (*prev_cmd)->size)
	{
		delete_darray(prev_cmd);
		*prev_cmd = new_cmd;
		new_cmd = new_darray_malloc((*prev_cmd)->size);
	}
	delete_darray(prev_cmd);
	*prev_cmd = new_cmd;

	new_cmd = new_darray_malloc((*prev_cmd)->size);
	while (optimize_3cmd(*prev_cmd, new_cmd) != (*prev_cmd)->size)
	{
		delete_darray(prev_cmd);
		*prev_cmd = new_cmd;
		new_cmd = new_darray_malloc((*prev_cmd)->size);
	}
	delete_darray(prev_cmd);
	*prev_cmd = new_cmd;
}
