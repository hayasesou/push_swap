/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_large_quick.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:45:56 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/03 11:23:40 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int get_pivot(int stack_number, t_cd_list ** stack_x)
{
	int	i;
	int min;
	int max;
	int ret;

	i = -1;
	min = INT_MAX;
	max = INT_MIN;
	while(++i < stack_number)
	{
		if((*stack_x)->content < min)
			min = (*stack_x)->content;
		if((*stack_x)->content > max)
			max = (*stack_x)->content;
		(*stack_x) = (*stack_x)->next;
	}
	while(i-- > 0)
		(*stack_x) = (*stack_x)->prev;
	ret = (max + min) / 2;
	return (ret);
}

void	stack_small_quick_sort(int av_num, t_cd_list **stack_a, t_cd_list **stack_b, int *group_id_max)
{
	int	pivot;
	int	i;
	int	push_count;
	int count_below_pivot;

	push_count = 0;
	count_below_pivot = 0;
	pivot = get_pivot(av_num, stack_a);
	i = -1;


	// ft_prntf("[%d]\n",(*stack_a)->content);
	while(++i < av_num)
	{
		if((*stack_a)->content <= pivot)
			count_below_pivot++;
		(*stack_a) = (*stack_a)->next;
	}
	// ft_printf("[%d]\n",(*stack_a)->content);
	// ft_printf("%d\n",count_below_pivot);
	// exit (0);
	i = -1;
	while (++i < av_num)
	{
		if ((*stack_a)->content <= pivot)
		{
			(*stack_a)->group_id = *group_id_max + 1;
			push_x2y(stack_a, stack_b, B);
			push_count++;
			if (push_count == count_below_pivot)
				break ;
		}
		else
		{
			(*stack_a)->group_id = *group_id_max;
			ft_ra(stack_a);
		}
	}
	*group_id_max += 1;
	stack_b_quick_sort(push_count, stack_b, stack_a, group_id_max);
}

void	stack_large_quick_sort(int av_num, t_cd_list **stack_a, t_cd_list **stack_b, int *group_id_max)
{
	int	pivot;
	int	i;
	int push_count;
	int count_upper_pivot;

	push_count = 0;
	count_upper_pivot = 0;
	pivot = get_pivot(av_num, stack_a);
	i = -1;
	while(++i < av_num)
	{
		if((*stack_a)->content > pivot)
			count_upper_pivot++;
		(*stack_a) = (*stack_a)->next;
	}
	i = -1;
	while (++i < av_num /2)
	{
		if ((*stack_a)->content > pivot)
		{
			(*stack_a)->group_id = *group_id_max + 1;
			push_x2y(stack_a, stack_b, B);
			push_count++;
			if (push_count == count_upper_pivot)
				break;
		}
		else
		{
			(*stack_a)->group_id = *group_id_max;
			ft_ra(stack_a);
		}
	}
	*group_id_max += 1;
	stack_b_quick_sort(push_count, stack_b, stack_a, group_id_max);
}

