/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:45:17 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/29 21:41:56 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void	stack_b_quick_sort(int av_num, t_cd_list **stack_b, t_cd_list **stack_a, int group_id)
{
	int	pivot;
	int	i;
	int	j;
	int	sum;
	int count_stack_b_node;
	int count_ra;

	j = -1;
	sum = 0;
	if (av_num < 4)
	{
		stack_b_sort_3number(stack_b);
		while ((*stack_b) != NULL)
		{
			push_x2y(stack_b, stack_a, A);
			ft_ra(stack_a);
		}
		return ;
	}
	while (++j < av_num)
	{
		sum += (*stack_b)->content;
		(*stack_b) = (*stack_b)->next;
	}
	while (j-- > 0)
		(*stack_b) = (*stack_b)->prev;
	pivot = sum / av_num;
	i = -1;
	count_stack_b_node = 0;
	while (++i < av_num)
	{
		if (*stack_b == NULL)
			return ;
		if ((*stack_b)->content >= pivot)
		{
			(*stack_b)->group_id = group_id + 1;
			push_x2y(stack_b, stack_a, A);
		}
		else
		{
			ft_rb(stack_b);
			count_stack_b_node++;
		}
	}
	stack_b_quick_sort(count_stack_b_node, stack_b, stack_a, group_id + 1);
	count_ra = 0;
	while ((*stack_a)->group_id == group_id + 1)
	{
		push_x2y(stack_a, stack_b, B);
		count_ra++;
	}
	if ((*stack_b) != NULL)
		stack_b_quick_sort(count_ra, stack_b, stack_a, 10);
}

void	stack_small_quick_sort(int av_num, t_cd_list **stack_a, t_cd_list **stack_b, int group_id)
{
	int	pivot;
	int	i;
	int j;
	int sum;
	int push_count;

	j = -1;
	sum = 0;

	push_count = 0;
	if (av_num < 15)
		return ;
	while (++j < av_num)
	{
		sum += (*stack_a)->content;
		(*stack_a) = (*stack_a)->next;
	}
	while (j-- > 0)
		(*stack_a) = (*stack_a)->prev;
	pivot = sum / av_num;
	i = -1;
	while (++i < av_num)
	{
		if ((*stack_a)->content <= pivot)
		{
			(*stack_a)->group_id = group_id + 1;
			push_x2y(stack_a, stack_b, B);
			push_count++;
		}
		else
		{
			(*stack_a)->group_id = group_id;
			ft_ra(stack_a);
		}
	}
	stack_b_quick_sort(push_count, stack_b, stack_a, group_id + 1);
}

void	stack_large_quick_sort(int av_num, t_cd_list **stack_a, t_cd_list **stack_b, int group_id)
{
	int	pivot;
	int	i;
	int j;
	int sum;
	int push_count;

	j = -1;
	sum = 0;

	push_count = 0;
	if (av_num < 15)
		return ;
	while (++j < av_num)
	{
		sum += (*stack_a)->content;
		(*stack_a) = (*stack_a)->next;
	}
	while (j-- > 0)
		(*stack_a) = (*stack_a)->prev;
	pivot = sum / av_num;
	i = -1;
	while (++i < av_num /2)
	{
		if ((*stack_a)->content > pivot)
		{
			(*stack_a)->group_id = group_id + 1;
			push_x2y(stack_a, stack_b, B);
			push_count++;
		}
		else
		{
			(*stack_a)->group_id = group_id;
			ft_ra(stack_a);
		}
	}
	stack_b_quick_sort(push_count, stack_b, stack_a, group_id + 1);

}


void	quick_sort(int av_num, t_cd_list **stack_a, t_cd_list **stack_b)
{
	stack_small_quick_sort(av_num, stack_a, stack_b, 0);
	stack_large_quick_sort(av_num, stack_a, stack_b, 100);
}