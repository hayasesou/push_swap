/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:50:48 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 02:58:55 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <libc.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

# define NEXT 1
# define PREV 0

# define A 1
# define B 2
# define SAME 3

# define MAX_CASE 1
# define MIN_CASE 2
# define MIDDLE_CASE 3

# define BREAK 1

// # define insertion_standard 26

typedef enum e_type_a
{
	LARGE,
	SMALL
}							t_size_a;

typedef enum e_operation
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}							t_operation;

typedef struct s_cd_list
{
	int						content;
	int						group_id;
	struct s_cd_list		*prev;
	struct s_cd_list		*next;
}							t_cd_list;

typedef struct s_ints_info
{
	int						*number;
	int						av_num;
}							t_ints_info;

typedef struct s_instruction
{
	char					*operation;
	struct s_instruction	*prev;
	struct s_instruction	*next;
}							t_instruction;

typedef struct s_lists
{
	t_cd_list				*stack_a;
	t_cd_list				*stack_b;
	t_instruction			*instruction;
	int						list_min;
}							t_lists;

typedef struct t_top3number
{
	int						top1;
	int						top2;
	int						top3;
}							t_top3number;

typedef struct s_stack_b
{
	int						min;
	int						max;
	int						min_plusone;
	int						max_minusone;
	int						node_count;
}							t_stack_b_info;

typedef struct s_distance
{
	int						from_top;
	int						from_bottom;
	t_cd_list				*top_position;
	t_cd_list				*bottom_postion;
}							t_distance;

//make list
void						add_back_doubly(t_cd_list **list, t_cd_list *new);
t_cd_list					*new_doubly(void);
t_cd_list					*make_circular_doubly(t_ints_info *info);

//swap top of list and next
void						swap_top_2(t_cd_list **list);
void						ft_sa(t_lists *stack);
void						ft_sb(t_lists *stack);
void						ft_ss(t_lists *satck);

//push top of x to y
//after this func , top of list is next ptr of what used to be
void						push_x2y(t_cd_list **x, t_cd_list **y, int type,
								t_lists *stack);

//shift up.
// top of list is next ptr of current list
// void					ft_ra(t_cd_list **stack_a);
void						ft_ra(t_lists *stack);
void						ft_rb(t_lists *stack);
void						ft_rr(t_lists *stack);

//shift down
void						ft_rra(t_lists *stack);
void						ft_rrb(t_lists *stack);
void						ft_rrr(t_lists *stack);

int							ft_atoi_push_swap(const char *str);
void						display_error(void);
void						display_instruction(t_lists *stack);

//insretion_sort
void						stack_a_insertion_sort(int number_count,
								t_lists *stack);
void						stack_b_insertion_sort(int number_count,
								t_lists *stack);
void						current_minpluseone_next_min(t_lists *stack,
								t_stack_b_info *b_info);
void						current_maxminusone_next_max(t_lists *stack,
								t_stack_b_info *b_info);
void						current_min_or_max_from_top(t_lists *stack,
								t_stack_b_info *b_info);
void						from_bottom(t_lists *stack, t_distance distance,
								t_stack_b_info *b_info);
void						from_top(t_lists *stack, t_distance *distance,
								t_stack_b_info *b_info);
void						set_disatance(t_distance *distance,
								t_stack_b_info *b_info, t_cd_list **stack_b);

//coordinate_compression
void						coordinate_compression(t_ints_info *info);

//
void						check_list_order(t_lists *stack, int av_num);
void						stack_a_sort_3number(t_lists *stack);

//quick_sort
int							get_pivot(int stack_number, t_cd_list **stack_x);
void						quick_sort(int av_num, t_lists *stack);
void						stack_b_quick_sort(int av_num, t_lists *satck,
								int *group_id_max);
void						stack_small_quick_sort(int av_num, t_lists *stack,
								int *group_id_max);
void						stack_large_quick_sort(int av_num, t_lists *stack,
								int *group_id_max);
void						push_next_block(t_lists *stack, int *min,
								int *count_pb);
int							separate_stack_b(int pivot, t_lists *stack,
								int *group_id_max, int *count_above_pivot);
void						handle_stack_number_under_standard(int av_num,
								t_lists *stack);
t_cd_list					*find_min_node(t_cd_list *head);
void						set_next_block2stack_b(t_lists *stack, int group_id,
								int *group_id_max);

//utils
int							check_a(int av_num, t_cd_list **stack_a, int pivot,
								t_size_a size);
int							check_b(int av_num, t_cd_list **stack_b, int pivot);
int							check_instruction(t_lists *stack);

//list utils
void						all_free(t_lists *stack);
void						clear_all_stack(t_lists *stack);
void						delete_instruction_node(t_lists *stack_x);
t_instruction				*new_instruction(void);
void						clear_all_instruction_list(t_lists *stack);
void						pull_out_instruction(t_lists *stack);
void						set_operation(t_instruction *op_node,
								t_operation op);
t_instruction				*add_instruction(t_lists *stack, t_operation op);
void						make_instructin_list(t_lists *stack,
								t_operation op);
void						optimize_push(t_lists *stack);
void						optimize_instruction(t_lists *stack);

#endif