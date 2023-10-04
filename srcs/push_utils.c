/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:32:59 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/03 18:37:06 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	check_a(int av_num, t_cd_list **stack_a, int pivot, t_size_a size)
{
	int	i;
	int ret;
	int count_below_pivot;
	int count_above_pivot;

	count_above_pivot = 0;
	count_below_pivot = 0;
	i = -1;
	while(++i < av_num)
	{
		if((*stack_a)->content <= pivot)
			count_below_pivot++;
		(*stack_a) = (*stack_a)->next;
	}
	i = -1;
	while(++i < av_num)
	{
		if((*stack_a)->content > pivot)
			count_above_pivot++;
		(*stack_a) = (*stack_a)->next;
	}
	if (size == SMALL)
		ret = count_below_pivot;
	else
		ret = count_above_pivot;
	return (ret);
}


int	check_b(int av_num, t_cd_list **stack_b, int pivot)
{
	int	i;
	int count_above_pivot;

	count_above_pivot = 0;
	i = -1;
	while(++i < av_num)
	{
		if((*stack_b)->content >= pivot)
			count_above_pivot++;
		(*stack_b) = (*stack_b)->next;
	}
	return (count_above_pivot);
}