/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:30:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 19:50:53 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_up(t_cd_list **list)
{
	if (*list == NULL)
		return ;
	(*list) = (*list)->next;
}

void	ft_ra(t_lists *stack)
{
	shift_up(&(stack->stack_a));
	make_instructin_list(stack, RA);
}

void	ft_rb(t_lists *stack)
{
	shift_up(&(stack->stack_b));
	make_instructin_list(stack, RB);
}

void	ft_rr(t_lists *stack)
{
	shift_up(&(stack->stack_a));
	shift_up(&(stack->stack_a));
	make_instructin_list(stack, RR);
}
