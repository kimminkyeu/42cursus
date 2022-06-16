/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:41:40 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 14:36:13 by minkyeki         ###   ########.fr       */
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

/** FIXME : 이런 식으로 문자열을 r-value로 처리해도 될까?  */
/** NOTE : 명령어 Optimazation은 이 함수에서 진행하지 않는다.   */
const char* get_cmd_string(int cmd_code)
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

	/* TODO : Oprimize commands. ex sa sb = ss */
	i = -1;
	while (++i < cmd->size)
	{
		cmd_code = *((int *)(cmd->data[i]));
		ft_printf("%s\n", get_cmd_string(cmd_code));
	}
	/** ft_printf("Total Count: %d\n", i); */
}

void render_stack(t_stack2 *stack_a, t_stack2 *stack_b)
{
	size_t	i;
	t_list	*tmp_node_a;
	t_list	*tmp_node_b;
	int		tmp_a[stack_a->stack->size];
	int		tmp_b[stack_b->stack->size];

	i = 0;
	tmp_node_a = stack_a->stack->bottom;
	while (i < stack_a->stack->size)
	{
		tmp_a[stack_a->stack->size - 1 - i] = *(int *)tmp_node_a->content;
		tmp_node_a = tmp_node_a->next;
		i++;
	}

	i = 0;
	tmp_node_b = stack_b->stack->bottom;
	while (i < stack_b->stack->size)
	{
		tmp_b[stack_b->stack->size - 1 - i] = *(int *)tmp_node_b->content;
		tmp_node_b = tmp_node_b->next;
		i++;
	}

	ft_printf("A-size: %d\tB-size: %d\n", stack_a->stack->size, stack_b->stack->size);
	ft_printf("----------\t----------\n");
	ft_printf("|  TOP   |\t|  TOP   |\n");
	ft_printf("----------\t----------\n");

	i = 0;
	while (i < stack_a->stack->size + stack_b->stack->size)
	{
		if (i < stack_a->stack->size)
			ft_printf("   %d", tmp_a[i]);
		ft_printf("\t\t");
		if (i < stack_b->stack->size)
			ft_printf("   %d", tmp_b[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("----------\t----------\n");
	ft_printf("| BOTTOM |\t| BOTTOM |\n");
	ft_printf("----------\t----------\n");

	ft_printf("\n_______________________________________________\n");
    ft_printf("\n\n");
}

/** void	run_single_cmd(t_push_swap *data, int cmd_code1)
  * {
  *     if (cmd_code1 == PA)
  *         push(data->stack_a_copy, data->stack_b_copy, data->cmd_copy);
  *     else if (cmd_code1 == PB)
  *         push(data->stack_b_copy, data->stack_a_copy, data->cmd_copy);
  *     else if (cmd_code1 == SA)
  *         swap(data->stack_a_copy, data->cmd_copy);
  *     else if (cmd_code1 == SB)
  *         swap(data->stack_b_copy, data->cmd_copy);
  *     else if (cmd_code1 == RA)
  *         shift_up(data->stack_a_copy, data->cmd_copy);
  *     else if (cmd_code1 == RB)
  *         shift_up(data->stack_b_copy, data->cmd_copy);
  *     else if (cmd_code1 == RRA)
  *         shift_down(data->stack_a_copy, data->cmd_copy);
  *     else if (cmd_code1 == RRB)
  *         shift_down(data->stack_b_copy, data->cmd_copy);
  *     else if (cmd_code1 == SS)
  *         swap_both(data->stack_a, data->stack_b, data->cmd_copy);
  *     else if (cmd_code1 == RR)
  *         shift_up_both(data->stack_a, data->stack_b, data->cmd_copy);
  *     else if (cmd_code1 == RRR)
  *         shift_down_both(data->stack_a, data->stack_b, data->cmd_copy);
  *
  *     ft_printf("CMD: %s\n\n", get_cmd_string(cmd_code1));
  *     render_stack(data->stack_a_copy, data->stack_b_copy);
  * } */

/* when running cmd of original darray, it automatically copies data to cmd_copy for furthur optimization  */
// returns 1 if last command is not runned
/** void	optimize_and_run_2cmd(t_push_swap *data, size_t *i, int cmd_code1, int cmd_code2)
  * {
  *     ft_printf("comparing cmd%d:%s cmd%d:%s\n", *i, get_cmd_string(cmd_code1), *i + 1, get_cmd_string(cmd_code2));
  *     [> TODO : OPTIMIZE in here!... 더 최적화할 만한건 없는가? <]
  *     [> (rra ra = do nothing | pa pb = do nothing | ra rb = rr | rra rrb = rrr | sa sb = ss ) <]
  *     if (cmd_code1 == SA && cmd_code2 == SB)
  *     {
  *         run_single_cmd(data, SS);
  *         *i += 2;
  *     }
  *     else if (cmd_code1 == RA && cmd_code2 == RB)
  *     {
  *         run_single_cmd(data, RR);
  *         *i += 2;
  *     }
  *     else if (cmd_code1 == RRA && cmd_code2 == RRB)
  *     {
  *         run_single_cmd(data, RRR);
  *         *i += 2;
  *     }
  *     else if ((cmd_code1 == RRA && cmd_code2 == RA) \
  *             || (cmd_code1 == RRB && cmd_code2 == RB) \
  *             || (cmd_code1 == RA && cmd_code2 == RRA) \
  *             || (cmd_code1 == RB && cmd_code2 == RRB) \
  *             || (cmd_code1 == PA && cmd_code2 == PB) \
  *             || (cmd_code1 == PB && cmd_code2 == PA))
  *     {
  *         ft_printf("Skipping two opposed commands...\n\n");
  *         *i += 2; // do nothing
  *     }
  *     else
  *     {
  *         // no optimization
  *         run_single_cmd(data, cmd_code1);
  *         *i += 1;
  *     }
  * } */

/** TODO : 3 cmd에 대한 최적화  
 * 
 * 예를 들어, ra pa rra 는 sa pa로 줄인다.
 *            rb pb rrb 는 sb pb로 줄인다.
 *
 *
 * TODO : 또 다른 최적화는 2cmd를 한번 더 실행해서 ra ra rra rra를 없애는 것이다.
 *
 * */
/** void	optimize_and_run_3cmd() */

/** void visualize_push_swap(t_push_swap *data)
  * {
  *     size_t	i;
  *
  *     ft_printf("\n");
  *     ft_printf("--------------------------------\n");
  *     ft_printf("|          Visualizer          |\n");
  *     ft_printf("--------------------------------\n");
  *     ft_printf("\n");
  *     i = 0;
  *     while (i < data->cmd->size - 1)
  *         optimize_and_run_2cmd(data, &i, *(int *)(data->cmd->data)[i], *(int *)(data->cmd->data)[i + 1]);
  *     // if 1, 3 cmd or 5 cmd, etc... then last cmd didn't run.. so run accordingly
  *     if (i == data->cmd->size - 1)
  *         run_single_cmd(data, *(int *)(data->cmd->data)[i]);
  * } */

void	push_cmd(t_darray *cmd, int	cmd_code)
{
	// pa(0) pb(1) sa(2) sb(3) ss(4) ra(5) rb(6) rr(7) rra(8) rrb(9) rrr(10)
	int	*cmd_info;

	cmd_info = malloc(sizeof(*cmd_info));
	*cmd_info = cmd_code;
	darray_push_back(cmd, cmd_info);
}

size_t	optimize_2cmd(t_darray *prev_cmd, t_darray *new_cmd)
{
	/** optimize and copy to new_cmd */
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
			i += 2; // do nothing
		}
		else
		{
			// no optimization
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
	/** optimize and copy to new_cmd */
	// ra pb rra = sa pb
	// rb pa rrb = sb pa
	
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
			// no optimization
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
	// (1) make new cmd_array
	t_darray	*new_cmd;

	/** TODO : darray_shrink_to_fit 마지막에 진행  */
	
	// (2) optimize while there is no difference
	new_cmd = new_darray_malloc((*prev_cmd)->size);
	while (optimize_2cmd(*prev_cmd, new_cmd) != (*prev_cmd)->size)
	{
		ft_printf("Optimizing 2cmd...\n");
		/** change prev_cmd pointer to new_cmd */
		delete_darray(prev_cmd);
		*prev_cmd = new_cmd;
		new_cmd = new_darray_malloc((*prev_cmd)->size);
	}
	delete_darray(prev_cmd);
	*prev_cmd = new_cmd;

	new_cmd = new_darray_malloc((*prev_cmd)->size);
	while (optimize_3cmd(*prev_cmd, new_cmd) != (*prev_cmd)->size)
	{
		ft_printf("Optimizing 3cmd...\n");
		/** change prev_cmd pointer to new_cmd */
		delete_darray(prev_cmd);
		*prev_cmd = new_cmd;
		new_cmd = new_darray_malloc((*prev_cmd)->size);
	}
	delete_darray(prev_cmd);
	*prev_cmd = new_cmd;
}
