/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:10:54 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/18 23:41:29 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/include/libft.h"

/* For Operation */
# define PA			(0)
# define PB			(1)
# define SA			(2)
# define SB			(3)
# define RA			(4)
# define RB			(5)
# define RRA		(6)
# define RRB		(7)
# define SS			(8)
# define RR			(9)
# define RRR		(10)

/* For Stack */
# define A			(1)
# define B			(-1)

/* For Sorting */
# define TRI_MAX	(5)
# define MAX		(1)
# define MIN		(0)
# define INC		(1)
# define DEC		(-1)

typedef struct s_stack {
	t_list	*bottom;
	t_list	*top;
	size_t	size;
}	t_stack;

typedef struct s_stack2 {
	t_stack			*stack;
	int				a_or_b;
}	t_stack2;

typedef struct s_triangle {
	int	size;
	int	inc_or_dec;
	int	a_or_b;
}	t_triangle;

typedef struct s_merge_info {
	t_stack2	*dst;
	t_stack2	*src;
	int			d3[3];
	int			max_or_min;
	int			target;
	int			t[3];
}	t_merge_info;

/* NOTE
 * ------------------------
 *                        |
 *        INC =    *      |
 *                /|      |
 *               / |      |
 *              /__|      |
 *                        |
 * ------------------------
 *                        |
 *        DEC = ____      |
 *              \  |      |
 *               \ |      |
 *                \|      |
 *                 *      |
 * ------------------------
 * */

typedef struct s_push_swap {
	int			is_checker;
	t_stack2	*stack_a;
	t_stack2	*stack_b;
	t_darray	*cmd;
	int			min;
	int			max;
	int			total_input_cnt;
	t_darray	*tri_map;
}	t_push_swap;

/* For stack */
extern t_stack		*stack_new(void);
extern void			stack_delete(t_stack *stack);
extern t_stack		*stack_push(t_stack *stack, int data);
extern void			stack_pop(t_stack *stack);
extern void			stack_print(t_stack *stack);
extern t_list		*stack_get_node(t_stack *stack, size_t index);
extern const int	*stack_get_data(t_stack *stack, size_t index);

/* My algorithm function */
extern void			sort_three(t_stack2 *stack, t_darray *cmd);
extern void			sort_under_three(t_push_swap *data);
extern void			sort_stack(t_push_swap *data);

/* Merge */
extern void			merge(t_push_swap *data);
extern void			merge_3tri_each(t_triangle *t1, t_triangle *t2, \
		t_triangle *t3, t_push_swap *data);
extern void			push_top_tri_to_opposite(t_triangle *t3, t_push_swap *data);
extern int			find_max_or_min(int *arr, int size, int max_or_min);
extern int			find_max_or_min_2(int a, int b, int max_or_min);

/* Triangle map */
extern void			tringify(t_push_swap *data);
extern t_darray		*make_tri_map(int total_num);
extern t_triangle	*create_triangle(int _inc_or_dec, int _size, int _a_or_b);
extern int			get_total_step(int total_num);
extern void			push_tri(int size, t_triangle *tri, t_push_swap *data);
extern void			push_2_tri(t_triangle *tri, t_push_swap *data);
extern void			push_as_triangle(t_triangle *tri, t_push_swap *data);

/* For Check_input */
extern void			check_single_arg_and_push(char **av, \
		t_push_swap *data);
extern void			check_num_and_push(size_t nmemb, int start_idx, \
		char **strs, t_push_swap *data);
extern void			push_argument_to_stack(int *tmp, size_t nmemb, \
		t_stack2 *stack);
extern void			check_if_same_number(int *tmp, size_t nmemb, \
		t_push_swap *data);
extern void			check_if_sorted(int *tmp, size_t nmemb, \
		t_push_swap *data);
extern void			exit_program(char *err_messege, int is_error, \
		t_push_swap *data);

/* For operation */
extern void			print_cmd(t_darray *cmd);
extern void			optimize_cmd(t_darray **cmd);
extern void			push_cmd(t_darray *cmd, int cmd_code);
/** @ sa or sb 
 *  Swap the first 2 elements at the top of stack.
 *  Do nothing if there is only one or no elements. */
extern void			swap(t_stack2 *stack, t_darray *cmd);
/** @ ss (sa and sb both) */
extern void			swap_both(t_stack2 *stack_a, t_stack2 *stack_b, \
		t_darray *cmd);
/** @ pa or pb.
 *  Take the first element at the top of src and put it at the top of dst.
 *  Do nothing if src is empty.*/
extern void			push(t_stack2 *dst, t_stack2 *src, t_darray *cmd);
/** @ rotate a or rotate b.
 *  The first element becomes the last one. */
extern void			shift_up(t_stack2 *stack, t_darray *cmd);
/** @ rotate both (a and b) */
extern void			shift_up_both(t_stack2 *stack_a, t_stack2 *stack_b, \
		t_darray *cmd);
/** @ reverse_rotate a or reverse_rotate b.
 *  The last element becomes the first one. */
extern void			shift_down(t_stack2 *stack, t_darray *cmd);
/** reverse_rotate both. */
extern void			shift_down_both(t_stack2 *stack_a, t_stack2 *stack_b, \
		t_darray *cmd);

/* Helper functions */
extern int			find_min(t_stack2 *stack);
extern void			bubble_sort(int *data, int start, \
		int end, int inc_or_dec);
extern const char	*get_cmd_string(int cmd_code);
extern t_stack2		*init_stack2(int flag);
extern void			delete_stack2(t_stack2 *stack);
extern void			set_target_to_top(int target, t_stack2 *stack, \
		t_darray *cmd);
extern void			insert_to_fit(t_stack2 *dst_sorted, t_stack2 *src, \
		t_darray *cmd);
extern int			find_next_bigger_int_idx(int target, t_stack2 *stack);

#endif
