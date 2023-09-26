/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:50:48 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/26 09:04:17 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

# define NEXT 1
# define PREV 0

#define A 1
#define B 2
#define SAME 3

#define MAX_CASE 1
#define MIN_CASE 2
#define MIDDLE_CASE 3

typedef struct t_cd_list
{
  int                content;
  struct  t_cd_list  *prev;
  struct  t_cd_list  *next;
}   t_cd_list;

typedef struct t_ints_info
{
  int   *number;
  int   av_num;
} t_ints_info;

typedef struct t_lists
{
  t_cd_list *stack_a;
  t_cd_list *stack_b;
} t_lists;

//make list
void    add_front_doubly(t_cd_list **list, t_cd_list *new);
t_cd_list *new_doubly(void);
t_cd_list	*make_circular_doubly(t_ints_info *info);

//swap top of list and next
void swap_top_2(t_cd_list **list);
void	ft_ss(t_cd_list **x, t_cd_list **y);

//push top of x to y
//afte this func , top of list is next ptr of what used to be
void	push_x2y(t_cd_list **x, t_cd_list **y, int type);

//shift up.
// top of list is next ptr of current list
void	ft_ra(t_cd_list **stack_a);
void	ft_rb(t_cd_list **stack_b);
void	ft_rr(t_cd_list **x, t_cd_list **y);

//shift down
void	ft_rra(t_cd_list **stack_a);
void	ft_rrb(t_cd_list **stack_b);
void	ft_rrr(t_cd_list **x, t_cd_list **y);

int	ft_atoi_push_swap(const char *str);
void	display_error(void);

//insretion_sort
void	insertion_sort(int number_count, t_cd_list **stack_a, t_cd_list **stack_b);

void	implicit_rotate(t_cd_list **list);

#endif