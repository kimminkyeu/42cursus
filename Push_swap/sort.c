/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:47:47 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 15:10:23 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	merge(t_push_swap *data);
t_triangle	*create_triangle(int _inc_or_dec, int _size, int _a_or_b);
t_darray	*make_tri_map(int total_num);
void	print_tri_map(t_darray *tri_map);
void	tringify(t_push_swap *data);
void	merge_3tri_each(t_triangle *t1, t_triangle *t2, t_triangle *t3, t_push_swap *data);
void	push_top_tri_to_opposite(t_triangle *t3, t_push_swap *data);

void	sort_stack(t_push_swap *data)
{
	if (data->stack_a->stack->size <= 5)
		sort_under_five(data);
	else
	{
		data->tri_map = make_tri_map(data->stack_a->stack->size);
		tringify(data);
		while (((t_triangle *)data->tri_map->data[0])->size < data->total_input_cnt)
			merge(data);
		if (data->stack_a->stack->size == 0)
		{
			while (data->stack_a->stack->size < (size_t)data->total_input_cnt)
				push(data->stack_a, data->stack_b, data->cmd);
		}
		delete_darray(&data->tri_map);
	}
}

void	merge(t_push_swap *data)
{
	size_t	i;
	t_triangle	*t1;
	t_triangle	*t2;
	t_triangle	*t3; // t3가 병합 전에 넘길 애들
	
	i = -1; // merge 시작 전에 전체의 1/3을 넘겨야 한다.
	while (++i < (data->tri_map->size / 3))
	{
		t3 = data->tri_map->data[data->tri_map->size - 1 - i];
		push_top_tri_to_opposite(t3, data);
	}

	i = -1; // 모든 삼각형을 순서대로 순회
	while (++i < (data->tri_map->size / 3))
	{
		t1 = data->tri_map->data[i]; //시작
		t2 = data->tri_map->data[((data->tri_map->size / 3) * 2) - 1 - i]; //중간
		t3 = data->tri_map->data[data->tri_map->size - 1 - i]; // 마지막
		merge_3tri_each(t1, t2, t3, data);
		t1->a_or_b *= -1; // join됬으니 방향은 반대
		t1->size = t1->size + t2->size + t3->size; // join됬으니 합친 크기로 변경
	}
	i = -1;
	size_t	map_size_prev = data->tri_map->size;
	while (++i < (map_size_prev / 3) * 2)
		darray_pop_back(data->tri_map);
	print_tri_map(data->tri_map);
}

void	push_top_tri_to_opposite(t_triangle *t3, t_push_swap *data)
{
	int	i;

	i = 0;
	while (i < t3->size)
	{
		if (t3->a_or_b == B) // push to A.
			push(data->stack_a, data->stack_b, data->cmd);
		else // push to b.
			push(data->stack_b, data->stack_a, data->cmd);
		i++;
	}
	t3->inc_or_dec *= -1; // 넘긴 삼각형 정보 업데이트
	t3->a_or_b *= -1;
}

int	find_max_or_min(int *arr, int size, int max_or_min)
{
	int	i;
	int	target;
	
	i = -1;
	target = arr[0];
	if (max_or_min == MAX)
	{
		while (++i < size - 1)
		{
			if (arr[i + 1] > target)
				target = arr[i + 1];
		}
	}
	else // DEC 면 최솟값을 찾아서 리턴
	{
		while (++i < size - 1)
		{
			if (arr[i + 1] < target)
				target = arr[i + 1];
		}
	}
	return (target);
}

int	find_max_or_min_2(int a, int b, int max_or_min)
{
	int	target;

	target = a;
	if ((max_or_min == MAX && a < b) || (max_or_min == MIN && a > b))
		target = b;
	return (target);
}


void	merge_3tri_each(t_triangle *t1, t_triangle *t2, t_triangle *t3, t_push_swap *data)
{
	int	d[3];
	t_stack2 *dst;
	t_stack2 *src;
	int	max_or_min;
	int	target;

	if (t3->a_or_b == A)
	{
		dst = data->stack_a;
		src = data->stack_b;
	}
	else if (t3->a_or_b == B)// if 넘겨진 곳이 B라면, d1 d2는  A에 있고 d3는 B에 있다.
	{
		dst = data->stack_b;
		src = data->stack_a;
	}
	if (t3->inc_or_dec == INC)
		max_or_min = MAX;
	else
		max_or_min = MIN;
	
	/** 정렬 시작 */

	// 3개중 max or min을 찾아서 실행
	int	t1_size = t1->size;
	int t2_size = t2->size;
	int t3_size = t3->size;

	while (t1_size + t2_size + t3_size > 0)
	{	
		/** ft_printf("t1:%d t2:%d t3:%d\n", t1_size, t2_size, t3_size); */
		if (t1_size != 0 && t2_size != 0 && t3_size != 0)
		{
			d[0] = *(int *)src->stack->bottom->content;    // t1, d[0] = 많은 쪽의 bottom
			d[1] = *(int *)src->stack->top->content;      // t2, d[1] = 많은 쪽의 top
			d[2] = *(int *)dst->stack->bottom->content;  // t3, d[2] = 반대편의 넘겨진 삼각형의 bottom
			target = find_max_or_min(d, 3, max_or_min);
		}
		else if (t1_size == 0 && t2_size != 0 && t3_size != 0)
			target = find_max_or_min_2(*(int *)src->stack->top->content, *(int *)dst->stack->bottom->content, max_or_min);
		else if (t1_size != 0 && t2_size != 0 && t3_size == 0)
			target = find_max_or_min_2(*(int *)src->stack->bottom->content, *(int *)src->stack->top->content, max_or_min);
		else if (t1_size != 0 && t2_size == 0 && t3_size != 0)
			target = find_max_or_min_2(*(int *)src->stack->bottom->content, *(int *)dst->stack->bottom->content, max_or_min);
		else if (t1_size == 0 && t2_size == 0 && t3_size != 0)
			target = *(int *)dst->stack->bottom->content;
		else if (t1_size == 0 && t2_size != 0 && t3_size == 0)
			target = *(int *)src->stack->top->content;
		else if (t1_size != 0 && t2_size == 0 && t3_size == 0)
			target = *(int *)src->stack->bottom->content;
		else
			break ;

		if (t1_size > 0 && target == *(int *)src->stack->bottom->content)
		{
			shift_down(src, data->cmd);
			push(dst, src, data->cmd);
			t1_size--;
		}
		else if (t2_size > 0 && target == *(int *)src->stack->top->content)
		{
			push(dst, src, data->cmd);
			t2_size--;
		}
		else if (t3_size > 0 && target == *(int *)dst->stack->bottom->content)
		{
			shift_down(dst, data->cmd);
			t3_size--;
		}
	}
} 

t_triangle	*create_triangle(int _inc_or_dec, int _size, int _a_or_b)
{
	t_triangle	*tmp;

	tmp = ft_calloc(1, sizeof(*tmp));
	if (tmp != NULL)
	{
		tmp->size = _size;
		tmp->inc_or_dec = _inc_or_dec;
		tmp->a_or_b = _a_or_b;
	}
	return (tmp);
}

int	get_total_step(int total_num)
{
	int	i;

	i = 0;
	while (total_num > TRI_MAX)
	{
		total_num /= 3;
		i++;
	}
	return (i);
}

t_darray	*make_tri_map(int total_num)
{
	t_darray	*tri_map;
	int			map_size_prev;
	int			i;

	// first check how many steps it will have. if step number is odd or even ->
	// A -> B -> A -> B -> A -> B ...
	// 0    1    2    3    4    5

	// 만약 total_step 이 짝수면... B에 정렬해야 함.
	tri_map = new_darray_malloc(30);
	if (get_total_step(total_num) % 2 == 1)
		darray_push_back(tri_map, create_triangle(INC, total_num, A));
	else
		darray_push_back(tri_map, create_triangle(DEC, total_num, B));

	print_tri_map(tri_map);
	while (((t_triangle *)(tri_map->data[0]))->size > TRI_MAX)
	{
		map_size_prev = tri_map->size;

		i = 0;
		while (i < map_size_prev)
		{
			t_triangle *tmp = ((t_triangle *)(tri_map->data[map_size_prev - 1 - i]));

			darray_push_back(tri_map, \
					create_triangle(tmp->inc_or_dec * -1, tmp->size / 3 + tmp->size % 3, tmp->a_or_b * -1));
		
			tmp->size /= 3;
			tmp->a_or_b *= -1;
			i++;
		}
		i = 0;
		while (i < map_size_prev) // 합병을 위해 넘길 애들 미러링 
		{
			t_triangle *tmp = ((t_triangle *)(tri_map->data[map_size_prev - 1 - i]));
			darray_push_back(tri_map, \
		        create_triangle(tmp->inc_or_dec * -1, tmp->size, tmp->a_or_b));
			i++;
		}
		print_tri_map(tri_map);
	}
	return (tri_map);
}

/* TODO : tringify 완료 후 직접 확인해볼 것. 잘 됬는지. visualizer 편집  */
void	push_tri(int size, t_triangle *tri, t_push_swap *data)
{
	int	p[size];
	int	i;

	i = -1;
	while (++i < size)
		p[i] = *stack_get_data(data->stack_a->stack, data->stack_a->stack->size - i - 1);

	if (tri->inc_or_dec == INC)
		quick_sort(p, 0, size - 1, DEC); // 최대값 찾아서 pb
	else
		quick_sort(p, 0, size - 1, INC); // 최솟값 찾아서 pb
	i = 0;
	while (i < size)
	{
		set_target_to_top(p[i], data->stack_a, data->cmd);
		push(data->stack_b, data->stack_a, data->cmd);
		i++;
	}
}

void	push_2_tri(t_triangle *tri, t_push_swap *data)
{
	int	p1;
	int	p2;

	p1 = *stack_get_data(data->stack_a->stack, data->stack_a->stack->size - 1);
	p2 = *stack_get_data(data->stack_a->stack, data->stack_a->stack->size - 2);

	if (tri->inc_or_dec == INC && p1 < p2) // 최대값 찾아서 pb
		swap(data->stack_a, data->cmd);
	if (tri->inc_or_dec == DEC && p1 > p2) // 최솟값 찾아서 pb
		swap(data->stack_a, data->cmd);
	push(data->stack_b, data->stack_a, data->cmd);
	push(data->stack_b, data->stack_a, data->cmd);
}

void	push_as_triangle(t_triangle *tri, t_push_swap *data)
{
	if (tri->size > 2)
		push_tri(tri->size, tri, data);
	else if (tri->size == 2)
		push_2_tri(tri, data);
	else if (tri->size == 1)
		push(data->stack_b, data->stack_a, data->cmd);

}

/** divide elements using tri_map 만들어진 tri_map으로 분할해주는 함수 */
void	tringify(t_push_swap *data)
{
	size_t		i;
	t_triangle	*tmp;
	// A to B. via map
	i = 0;
	while (i < data->tri_map->size)
	{
		tmp = data->tri_map->data[i]; // tri_map을 하나씩 순회하면서 명시된 것 만큼 정렬 후 삽입.
		push_as_triangle(tmp, data);
		i++;
	}
}

void	print_tri_map(t_darray *tri_map)
{
	size_t	i;
	
	i = 0;
	ft_printf("\n");
	while (i < tri_map->size)
	{
		t_triangle *tmp = ((t_triangle *)tri_map->data[i]);
		if (tmp->inc_or_dec == INC)
		{
			if (tmp->a_or_b == A)
				ft_printf("INC.A(%d) ", tmp->size);
			else
				ft_printf("INC.B(%d) ", tmp->size);
		}
		else
		{
			if (tmp->a_or_b == A)
				ft_printf("DEC.A(%d) ", tmp->size);
			else
				ft_printf("DEC.B(%d) ", tmp->size);
		}
		if (i == ((tri_map->size / 3) * 1) - 1)
			ft_printf(" | ");
		if (i == ((tri_map->size / 3) * 2) - 1)
			ft_printf(" || ");

		i++;
	}
	ft_printf("|");
	ft_printf("\n");
}
