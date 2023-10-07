/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:53:32 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 01:18:29 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_above_pivot_count(t_lists *stack, int av_num,
		int *count_above_pivot)
{
	int	i;
	int	pivot;

	*count_above_pivot = 0;
	pivot = get_pivot(av_num, &(stack->stack_b));
	i = -1;
	while (++i < av_num)
	{
		if (stack->stack_b->content > pivot)
			(*count_above_pivot)++;
		stack->stack_b = stack->stack_b->next;
	}
}

void	stack_b_quick_sort(int av_num, t_lists *stack, int *group_id_max)
{
	int	pivot;
	int	i;
	int	count_stack_b_node;
	int	group_id;
	int	count_above_pivot;

	if (av_num < 27)
	{
		handle_stack_number_under_standard(av_num, stack);
		return ;
	}
	pivot = get_pivot(av_num, &(stack->stack_b));
	count_stack_b_node = 0;
	get_above_pivot_count(stack, av_num, &count_above_pivot);
	i = -1;
	while (++i < av_num)
	{
		count_stack_b_node += separate_stack_b(pivot, stack, group_id_max,
				&count_above_pivot);
		if (count_above_pivot == 0)
			break ;
	}
	group_id = *group_id_max++;
	stack_b_quick_sort(count_stack_b_node, stack, group_id_max);
	set_next_block2stack_b(stack, group_id, group_id_max);
}
