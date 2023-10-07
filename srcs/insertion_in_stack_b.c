/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_in_stack_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:12:47 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 02:17:53 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	set_min_max_plus_minus_one(t_stack_b_info *b_info,
		int number_count, t_lists *stack)
{
	int	i;

	b_info->max = INT_MIN;
	b_info->min = INT_MAX;
	i = -1;
	while (++i < number_count)
	{
		if (stack->stack_b->content < b_info->min)
			b_info->min = stack->stack_b->content;
		if (stack->stack_b->content > b_info->max)
			b_info->max = stack->stack_b->content;
		stack->stack_b = stack->stack_b->next;
	}
	b_info->min_plusone = b_info->min + 1;
	b_info->max_minusone = b_info->max - 1;
	b_info->node_count = number_count;
}

void	stack_b_insertion_sort(int number_count, t_lists *stack)
{
	t_stack_b_info	b_info;
	t_distance		distance;

	set_min_max_plus_minus_one(&b_info, number_count, stack);
	while (stack->stack_b != NULL)
	{
		set_disatance(&distance, &b_info, &(stack->stack_b));
		if (distance.from_top <= distance.from_bottom)
			from_top(stack, &distance, &b_info);
		else
			from_bottom(stack, distance, &b_info);
	}
}
