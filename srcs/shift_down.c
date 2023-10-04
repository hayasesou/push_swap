/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:28:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/04 18:08:25 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_down(t_cd_list **list)
{
	if (*list == NULL)
		return ;
	(*list) = (*list)->prev;
}

void	ft_rra(t_cd_list **stack_a)
{
	shift_down(stack_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_cd_list **stack_b)
{
	shift_down(stack_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_cd_list **a, t_cd_list **b)
{
	shift_down(a);
	shift_down(b);
	ft_printf("rrr\n");
}
