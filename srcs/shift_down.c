/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:28:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 19:51:02 by hfukushi         ###   ########.fr       */
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
}

void	ft_rrb(t_lists *stack)
{
	shift_down(&(stack->stack_b));
	make_instructin_list(stack, RRB);
}

void	ft_rrr(t_lists *stack)
{
	shift_down(&(stack->stack_a));
	shift_down(&(stack->stack_b));
	make_instructin_list(stack, RRR);
}
