/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:16:34 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 01:20:17 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_distancde_from_top(t_distance *distance, t_stack_b_info *b_info,
		t_cd_list **stack_b)
{
	while (distance->from_top < b_info->node_count)
	{
		if ((*stack_b)->content == b_info->min
			|| (*stack_b)->content == b_info->max)
		{
			distance->top_position = (*stack_b);
			break ;
		}
		(*stack_b) = (*stack_b)->next;
		distance->from_top++;
	}
}

static void	get_distancde_from_bottom(t_distance *distance,
		t_stack_b_info *b_info, t_cd_list **stack_b)
{
	while (distance->from_bottom < b_info->node_count)
	{
		if ((*stack_b)->content == b_info->min
			|| (*stack_b)->content == b_info->max)
		{
			distance->bottom_postion = (*stack_b);
			break ;
		}
		(*stack_b) = (*stack_b)->prev;
		distance->from_bottom++;
	}
}

void	set_disatance(t_distance *distance, t_stack_b_info *b_info,
		t_cd_list **stack_b)
{
	t_cd_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = (*stack_b);
	distance->from_top = 0;
	distance->from_bottom = 0;
	get_distancde_from_top(distance, b_info, stack_b);
	(*stack_b) = tmp;
	get_distancde_from_bottom(distance, b_info, stack_b);
	(*stack_b) = tmp;
}
