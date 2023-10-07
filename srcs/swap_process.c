/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:24:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 02:28:17 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_lists *stack)
{
	t_cd_list	**stack_a;

	stack_a = &(stack->stack_a);
	if (*stack_a == NULL || (*stack_a)->next == (*stack_a))
		return ;
	swap_top_2(stack_a);
	make_instructin_list(stack, SA);
}

void	ft_sb(t_lists *stack)
{
	t_cd_list	**stack_b;

	stack_b = &(stack->stack_b);
	if (*stack_b == NULL || (*stack_b)->next == (*stack_b))
		return ;
	swap_top_2(stack_b);
	make_instructin_list(stack, SB);
}

void	ft_ss(t_lists *stack)
{
	swap_top_2(&(stack->stack_a));
	swap_top_2(&(stack->stack_b));
	make_instructin_list(stack, SS);
}
