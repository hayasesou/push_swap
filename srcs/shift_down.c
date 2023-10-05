/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:28:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/05 12:36:23 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_down(t_cd_list **list)
{
	if (*list == NULL)
		return ;
	(*list) = (*list)->prev;
}

void	ft_rra(t_lists *stack)
{
	shift_down(&(stack->stack_a));
	make_instructin_list(stack, RRA);
	// ft_printf("rra\n");
}

void	ft_rrb(t_lists *stack)
{
	shift_down(&(stack->stack_b));
	make_instructin_list(stack, RRB);
	// ft_printf("rrb\n");
}

void	ft_rrr(t_lists *stack)
{
	shift_down(&(stack->stack_a));
	shift_down(&(stack->stack_b));
	make_instructin_list(stack, RRR);
	// ft_printf("rrr\n");
}
