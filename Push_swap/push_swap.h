/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:10:54 by minkyeki          #+#    #+#             */
/*   Updated: 2022/06/16 15:15:42 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h> // for INT_MAX, INT_MIN
#include "libft/include/libft.h"

# define PA		(0)
# define PB		(1)
# define SA		(2)
# define SB		(3)
# define RA		(4)
# define RB		(5)
# define RRA	(6)
# define RRB	(7)
# define SS		(8)
# define RR		(9)
# define RRR	(10)








/* print cmd */
extern void	print_cmd(t_darray *cmd);

/* oprimize cmd */
extern void	optimize_cmd(t_darray **cmd);
extern void	push_cmd(t_darray *cmd, int	cmd_code);
/* -------------------------------------------
 * |           Header for t_stack            |
 * ------------------------------------------- */

/* FIXME (1) Handle Checker Segmentation fault */

/* typedef for stack */
typedef struct s_stack {
	t_list	*bottom;
	t_list	*top;
	size_t	size;
}	t_stack;

/* Allocate new stack */
extern t_stack	*stack_new(void);

/* Free stack and it's containing elements */
extern void		stack_delete(t_stack *stack);

/* Push integer data to stack */
extern t_stack	*stack_push(t_stack *stack, int data);

/* Pop integer data from stack */
extern void		stack_pop(t_stack *stack);

/* Print integer datas inside stack (NOTE : top and bottom are upside down!)*/
extern void		stack_print(t_stack *stack);

/** Used for indexing node */
extern t_list	*stack_get_node(t_stack *stack, size_t index);

/** Used for indexing data */
extern const int * stack_get_data(t_stack *stack, size_t index);

/* -------------------------------------------
 * |          Header for push_swap           |
 * ------------------------------------------- */

#define A (1)
#define B (-1)

typedef struct s_stack2 {
	t_stack			*stack;
	int				a_or_b;
}	t_stack2;

typedef struct s_push_swap {
	t_stack2	*stack_a;
	t_stack2	*stack_b;
	t_darray	*cmd;
	int			min;
	int			max;
	int			total_input_cnt; // 전체 입력값의 개수
	/* NOTE : delete below code. After checking is done */
	t_stack2	*stack_a_copy;	// TODO : Delete here!
	t_stack2	*stack_b_copy;	// TODO : Delete here!
	t_darray	*cmd_copy;		// TODO : Delete here!
								
	t_darray	*tri_map; // triangle_map for merge sort
						  //
}	t_push_swap;

/* ---------------------------------------------------------------- */
/* NOTE : Main algorithm function */
void	sort_stack(t_push_swap *data);
/* ---------------------------------------------------------------- */



/* ---------------------------------------------------------------- */
/* NOTE : push swap altimate visualizer */
extern void	visualize_push_swap(t_push_swap *data);
/* ---------------------------------------------------------------- */




/* NOTE : Mandatory.c */
extern void	check_single_arg_and_push(char **av, t_push_swap *data);
extern void	check_num_and_push(size_t nmemb, int start_idx, char **strs, t_push_swap *data);
extern void	push_argument_to_stack(int *tmp, size_t nmemb, t_stack2 *stack);
extern void	check_if_same_number(int *tmp, size_t nmemb, t_push_swap *data);
extern void	check_if_sorted(int *tmp, size_t nmemb, t_push_swap *data);
extern void	exit_program(char *err_messege, int is_error, t_push_swap *data);

#define TRI_MAX (5)
#define MAX (1)
#define MIN (0)
#define INC (1)
#define DEC (-1)

/* NOTE  헷갈리지 않게 주의 !!!
 *
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
 *
 * */

/* Helper Functions to check input data */
extern void render_stack(t_stack2 *stack_a, t_stack2 *stack_b);
extern void	quick_sort(int *data, int start, int end, int inc_or_dec);
extern const char* get_cmd_string(int cmd_code);

/* if flag is 0 -> stack_a
 * if flag is 1 -> stack_b */
t_stack2	*init_stack2(int flag);

/* free stack */
void	delete_stack2(t_stack2 *stack);

/** @ sa or sb 
 *  Swap the first 2 elements at the top of stack.
 *  Do nothing if there is only one or no elements. */
void	swap(t_stack2 *stack, t_darray *cmd);

/** @ ss (sa and sb both) */
void	swap_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd);

/** @ pa or pb.
 *  Take the first element at the top of src and put it at the top of dst.
 *  Do nothing if src is empty.*/
void	push(t_stack2 *dst, t_stack2 *src, t_darray *cmd);

/** @ rotate a or rotate b.
 *  The first element becomes the last one. */
void	shift_up(t_stack2 *stack, t_darray *cmd);

/** @ rotate both (a and b) */
void	shift_up_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd);

/** @ reverse_rotate a or reverse_rotate b.
 *  The last element becomes the first one. */
void	shift_down(t_stack2 *stack, t_darray *cmd);

/** reverse_rotate both. */
void	shift_down_both(t_stack2 *stack_a, t_stack2 *stack_b, t_darray *cmd);

extern void	set_target_to_top(int target, t_stack2 *stack, t_darray *cmd);
extern void	insert_to_fit(t_stack2 *dst_sorted, t_stack2 *src, t_darray *cmd);
extern int	find_next_bigger_int_idx(int target, t_stack2 *stack);
extern void	sort_three(t_stack2 *stack, t_darray *cmd);
extern void	sort_four(t_push_swap *data);
extern void	sort_five(t_push_swap *data);
extern void	sort_under_five(t_push_swap *data);
extern void	sort_stack(t_push_swap *data);


/* my merge sort algorithm */

typedef struct s_triangle {
	int	size;
	int	inc_or_dec;
	int a_or_b; // which stack?
}	t_triangle;

#endif /* PUSH_SWAP_H */
