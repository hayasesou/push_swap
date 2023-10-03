/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:45:17 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/03 15:06:02 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static	void	handle_stack_number_under_standard(int av_num, t_cd_list **stack_a, t_cd_list **stack_b)
{
	stack_b_insertion_sort(av_num, stack_b, stack_a);
	if (av_num >3)
	{
		while ((*stack_a)->group_id == (*stack_a)->next->group_id)
			ft_ra(stack_a);
			ft_ra(stack_a);
	}
	while ((*stack_b) != NULL)
	{
		push_x2y(stack_b, stack_a, A);
		ft_ra(stack_a);
	}
	return ;
}

static int separate_stack_b(int pivot, t_cd_list **stack_a, t_cd_list **stack_b, int *group_id_max)
{
	int count_stack_b_node;

	count_stack_b_node = 0;
	if ((*stack_b)->content >= pivot)
	{
		(*stack_b)->group_id = *group_id_max + 1;
		push_x2y(stack_b, stack_a, A);
	}
	else
	{
		ft_rb(stack_b);
		count_stack_b_node++;
	}
	return (count_stack_b_node);
}

static void set_next_block2stack_b(t_cd_list **stack_a, t_cd_list **stack_b, int group_id, int *group_id_max)
{
	int count_pb;
	int min;
	t_cd_list *tmp;

	min = INT_MAX;
	count_pb = 0;
	tmp = (*stack_a);
	while((*stack_a)->group_id == group_id +1)
	{
		if((*stack_a)->content < min)
			min = (*stack_a)->content;
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = tmp;
	while ((*stack_a)->group_id == group_id + 1)
	{
		if ((*stack_a)->content == min)
		{
			ft_ra(stack_a);
			min +=1;
		}
		else if ((*stack_a)->content == min +1 && (*stack_a)->next->content == min)
		{
			ft_sa(stack_a);
			ft_ra(stack_a);
			ft_ra(stack_a);
			min += 2;
		}
		else if((*stack_a)->content == min +1 && (*stack_a)->next->content == min +2 && (*stack_a)->next->next->content == min)
		{
			push_x2y(stack_a, stack_b, B);
			ft_sa(stack_a);
			ft_ra(stack_a);
			push_x2y(stack_b, stack_a, A);
			ft_ra(stack_a);
			ft_ra(stack_a);
			min += 3;
		}
		else if((*stack_a)->content == min + 2 && (*stack_a)->next->content == min && (*stack_a)->next->next->content == min +1)
		{
			push_x2y(stack_a, stack_b , B);
			ft_ra(stack_a);
			ft_ra(stack_a);
			push_x2y(stack_b, stack_a, A);
			ft_ra(stack_a);
			min += 3;
		}
		else if((*stack_a)->content == min + 2 && (*stack_a)->next->content == min +1 && (*stack_a)->next->next->content == min)
		{
			push_x2y(stack_a, stack_b , B);
			ft_sa(stack_a);
			ft_ra(stack_a);
			ft_ra(stack_a);
			push_x2y(stack_b, stack_a, A);
			ft_ra(stack_a);
			min += 3;
		}
		else
		{
		push_x2y(stack_a, stack_b, B);
		count_pb++;
		}
	}
	if ((*stack_b) != NULL)
		stack_b_quick_sort(count_pb, stack_b, stack_a, group_id_max);
}

void	stack_b_quick_sort(int av_num, t_cd_list **stack_b, t_cd_list **stack_a, int *group_id_max)
{
	int	pivot;
	int	i;
	int count_stack_b_node;
	int group_id;

	if (av_num < 26)
	{
		handle_stack_number_under_standard(av_num, stack_a, stack_b);
		return ;
	}
	pivot = get_pivot(av_num, stack_b);
	i = -1;
	count_stack_b_node = 0;
	while (++i < av_num)
		count_stack_b_node += separate_stack_b(pivot, stack_a, stack_b, group_id_max);
	group_id = *group_id_max;
	*group_id_max += 1;
	stack_b_quick_sort(count_stack_b_node, stack_b, stack_a, group_id_max);
	set_next_block2stack_b(stack_a, stack_b, group_id, group_id_max);
}


void	quick_sort(int av_num, t_lists *stack)
{
	int max;
	max = 0;
	if (av_num < 11)
	{
		stack_a_insertion_sort(av_num, stack);
		return ;
	}
	stack_small_quick_sort(av_num, &(stack->stack_a), &(stack->stack_b), &max);
	stack_large_quick_sort(av_num, &(stack->stack_a), &(stack->stack_b), &max);
}