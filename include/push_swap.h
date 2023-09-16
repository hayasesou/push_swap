/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:50:48 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/16 16:11:50 by hfukushi         ###   ########.fr       */
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


//make list
void    add_front_doubly(t_cd_list **list, t_cd_list *new);
t_cd_list *new_doubly();
t_cd_list	*make_circular_doubly(t_ints_info *info);

//swap top of list and next
void swap_top_2(t_cd_list **list);
void	ft_ss(t_cd_list **x, t_cd_list **y);

//push top of x to y
//afte this func , top of list is next ptr of what used to be
void	push_x2y(t_cd_list **x, t_cd_list **y);

//shift up.
// top of list is next ptr of current list
void	shift_up(t_cd_list **list);
void	ft_rr(t_cd_list **x, t_cd_list **y);

void	shift_down(t_cd_list **list);
void	ft_rrr(t_cd_list **x, t_cd_list **y);

long	ft_atof(const char *str);

#endif