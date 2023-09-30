/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_large_quick.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:45:56 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/01 02:43:47 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int get_pivot(int stack_number, t_cd_list ** stack_a)
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
		if((*stack_a)->content < min)
			min = (*stack_a)->content;
		if((*stack_a)->content > max)
			max = (*stack_a)->content;
		(*stack_a) = (*stack_a)->next;
	}
	while(i-- > 0)
		(*stack_a) = (*stack_a)->prev;
	ret = (max + min) / 2;
	return (ret);
}

void	stack_small_quick_sort(int av_num, t_cd_list **stack_a, t_cd_list **stack_b, int *group_id_max)
{
	int	pivot;
	int	i;
	int sum;
	int	push_count;

	sum = 0;
	push_count = 0;

	//j = -1;
//	int j;
	//while (++j < av_num)
	//{
		//sum += (*stack_a)->content;
		//(*stack_a) = (*stack_a)->next;
	//}
	//while (j-- > 0)
		//(*stack_a) = (*stack_a)->prev;
	//pivot = sum / av_num;
	pivot = get_pivot(av_num, stack_a);
	i = -1;
	while (++i < av_num)
	{
		if ((*stack_a)->content <= pivot)
		{
			(*stack_a)->group_id = *group_id_max + 1;
			push_x2y(stack_a, stack_b, B);
			push_count++;
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
	//int j;
	int sum;
	int push_count;

	//j = -1;
	sum = 0;

	push_count = 0;
	//while (++j < av_num)
	//{
		//sum += (*stack_a)->content;
		//(*stack_a) = (*stack_a)->next;
	//}
	//while (j-- > 0)
		//(*stack_a) = (*stack_a)->prev;
	//pivot = sum / av_num;
	pivot = get_pivot(av_num, stack_a);
	i = -1;
	while (++i < av_num /2)
	{
		if ((*stack_a)->content > pivot)
		{
			(*stack_a)->group_id = *group_id_max + 1;
			push_x2y(stack_a, stack_b, B);
			push_count++;
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

