/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:32:59 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 21:59:30 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_count_below(int av_num, int pivot, t_cd_list **stack_a)
{
	int	i;
	int	count_below_pivot;

	i = -1;
	count_below_pivot = 0;
	while (++i < av_num)
	{
		if ((*stack_a)->content <= pivot)
			count_below_pivot++;
		(*stack_a) = (*stack_a)->next;
	}
	return (count_below_pivot);
}


static int	get_count_above(int av_num, int pivot, t_cd_list **stack_a)
{
	int	i;
	int	count_above_pivot;

	i = -1;
	count_above_pivot = 0;
	while (++i < av_num)
	{
		if ((*stack_a)->content > pivot)
			count_above_pivot++;
		(*stack_a) = (*stack_a)->next;
	}
	return (count_above_pivot);
}

int	check_a(int av_num, t_cd_list **stack_a, int pivot, t_size_a size)
{
	int	ret;
	int	count_below_pivot;
	int	count_above_pivot;

	count_above_pivot = 0;
	count_below_pivot = get_count_below(av_num, pivot, stack_a);
	count_above_pivot = get_count_above(av_num, pivot, stack_a);
	if (size == SMALL)
		ret = count_below_pivot;
	else
		ret = count_above_pivot;
	return (ret);
}

int	check_b(int av_num, t_cd_list **stack_b, int pivot)
{
	int	i;
	int	count_above_pivot;

	count_above_pivot = 0;
	i = -1;
	while (++i < av_num)
	{
		if ((*stack_b)->content >= pivot)
			count_above_pivot++;
		(*stack_b) = (*stack_b)->next;
	}
	return (count_above_pivot);
}
