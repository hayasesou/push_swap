/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:30:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/05 12:33:05 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void	shift_up(t_cd_list **list)
//{
	//if (*list == NULL)
		//return ;
	//(*list) = (*list)->next;
//}

//void	ft_ra(t_cd_list **stack_a)
//{
	//shift_up(stack_a);
	//ft_printf("ra\n");
//}

//void	ft_rb(t_cd_list **stack_b)
//{
	//shift_up(stack_b);
	//ft_printf("rb\n");
//}

//void	ft_rr(t_cd_list **a, t_cd_list **b)
//{
	//shift_up(a);
	//shift_up(b);
	//ft_printf("rr\n");
//}

static void	shift_up(t_cd_list **list)
{
	if (*list == NULL)
		return ;
	(*list) = (*list)->next;
}

void	ft_ra(t_lists  *stack)
{
	shift_up(&(stack->stack_a));
	make_instructin_list(stack, RA);
	// ft_printf("ra\n");
}

void	ft_rb(t_lists *stack)
{
	shift_up(&(stack->stack_b));
	make_instructin_list(stack, RB);
	// ft_printf("rb\n");
}

void	ft_rr(t_lists *stack)
{
	shift_up(&(stack->stack_a));
	shift_up(&(stack->stack_a));
	make_instructin_list(stack, RR);
	// ft_printf("rr\n");
}
