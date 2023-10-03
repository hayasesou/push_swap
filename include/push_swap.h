/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:50:48 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/03 16:28:38 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <libc.h>

# define NEXT 1
# define PREV 0

# define A 1
# define B 2
# define SAME 3

# define MAX_CASE 1
# define MIN_CASE 2
# define MIDDLE_CASE 3

# define BREAK 1

typedef enum e_type_a
{
	LARGE,
	SMALL
}			t_size_a;

typedef struct s_cd_list
{
	int					content;
	int					group_id;
	struct s_cd_list	*prev;
	struct s_cd_list	*next;
}						t_cd_list;

typedef struct s_ints_info
{
	int					*number;
	int					av_num;
}						t_ints_info;

typedef struct s_lists
{
	t_cd_list			*stack_a;
	t_cd_list			*stack_b;
}						t_lists;

typedef struct t_top3number
{
	int	top1;
	int	top2;
	int	top3;
}						t_top3number;

typedef struct s_stack_b
{
	int min;
	int max;
	int node_count;
}						t_stack_b_info;

typedef struct s_distance
{
	int from_top;
	int	from_bottom;
	t_cd_list *top_position;
	t_cd_list *bottom_postion;
}						t_distance;


//make list
void					add_back_doubly(t_cd_list **list, t_cd_list *new);
t_cd_list				*new_doubly(void);
t_cd_list				*make_circular_doubly(t_ints_info *info);

//swap top of list and next
void					ft_sa(t_cd_list **stack_a);
void					ft_sb(t_cd_list **stack_b);
void					ft_ss(t_cd_list **x, t_cd_list **y);

//push top of x to y
//afte this func , top of list is next ptr of what used to be
void					push_x2y(t_cd_list **x, t_cd_list **y, int type);

//shift up.
// top of list is next ptr of current list
void					ft_ra(t_cd_list **stack_a);
void					ft_rb(t_cd_list **stack_b);
void					ft_rr(t_cd_list **x, t_cd_list **y);

//shift down
void					ft_rra(t_cd_list **stack_a);
void					ft_rrb(t_cd_list **stack_b);
void					ft_rrr(t_cd_list **x, t_cd_list **y);

int						ft_atoi_push_swap(const char *str);
void					display_error(void);

//insretion_sort
void					stack_a_insertion_sort(int number_count,
							t_lists *stack);
//void					stack_b_insertion_sort(int number_count,
							//t_cd_list **stack_b, t_cd_list **stack_a);
void					stack_b_insertion_sort(int number_count,
							t_lists *stack);

//coordinate_compression
void					coordinate_compression(t_ints_info *info);

//
void					check_list_order(t_lists *stack, int av_num);
void					stack_a_sort_3number(t_cd_list **stack_a);
void					stack_b_sort_3number(t_cd_list **stack_b);

//quick_sort
int						get_pivot(int stack_number, t_cd_list **stack_x);
void					quick_sort(int av_num, t_lists *stack);
void					stack_b_quick_sort(int av_num, t_lists *satck, int *group_id_max);
void					stack_small_quick_sort(int av_num, t_lists *stack, int *group_id_max);
void					stack_large_quick_sort(int av_num, t_lists *stack, int *group_id_max);

//utils
int	check_a(int av_num, t_cd_list **stack_a, int pivot, t_size_a size);

#endif