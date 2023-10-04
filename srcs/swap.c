/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:08:46 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/04 23:25:44 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_tmp_lists(t_cd_list *current, t_cd_list *second,
		t_cd_list **list)
{
	current->next = (*list)->next;
	current->prev = (*list)->prev;
	(*list) = (*list)->next;
	second->next = (*list)->next;
	second->prev = (*list)->prev;
	(*list) = (*list)->prev;
}

static void	set_ptr(t_cd_list **list, t_cd_list *place, t_cd_list *ptr,
		int direction)
{
	(*list) = place;
	if (direction == NEXT)
		(*list)->next = ptr;
	else if (direction == PREV)
		(*list)->prev = ptr;
}

void	swap_top_2(t_cd_list **list)
{
	t_cd_list	current;
	t_cd_list	second;

	if (*list == NULL || (*list)->next == (*list))
		return ;
	make_tmp_lists(&current, &second, list);
	set_ptr(list, current.prev, current.next, NEXT);
	set_ptr(list, current.next, second.prev, NEXT);
	set_ptr(list, second.prev, second.next, NEXT);
	set_ptr(list, current.next, current.prev, PREV);
	set_ptr(list, second.prev, current.next, PREV);
	set_ptr(list, second.next, second.prev, PREV);
	(*list) = current.next;
}

//void	ft_sa(t_cd_list **stack_a)
//{
	//if (*stack_a == NULL || (*stack_a)->next == (*stack_a))
		//return ;
	//swap_top_2(stack_a);
	//ft_printf("sa\n");
//}

//void	ft_sb(t_cd_list **stack_b)
//{
	//if (*stack_b == NULL || (*stack_b)->next == (*stack_b))
		//return ;
	//swap_top_2(stack_b);
	//ft_printf("sb\n");
//}

//void	ft_ss(t_cd_list **x, t_cd_list **y)
//{
	//swap_top_2(x);
	//swap_top_2(y);
//}

void	ft_sa(t_cd_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == (*stack_a))
		return ;
	swap_top_2(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_cd_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == (*stack_b))
		return ;
	swap_top_2(stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_cd_list **x, t_cd_list **y)
{
	swap_top_2(x);
	swap_top_2(y);
}
