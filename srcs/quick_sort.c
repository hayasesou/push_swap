/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:45:17 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 01:20:44 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_stack_number_under_standard(int av_num, t_lists *stack)
{
	int	tmp_group_id;

	tmp_group_id = stack->stack_b->group_id;
	stack_b_insertion_sort(av_num, stack);
	while (stack->stack_a->group_id == tmp_group_id)
		ft_ra(stack);
	return ;
}

t_cd_list	*find_min_node(t_cd_list *head)
{
	t_cd_list	*min_node;
	t_cd_list	*current;

	min_node = head;
	current = head->next;
	while (current != head)
	{
		if (current->content < min_node->content)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int	separate_stack_b(int pivot, t_lists *stack, int *group_id_max,
		int *count_above_pivot)
{
	int	count_stack_b_node;

	count_stack_b_node = 0;
	if (stack->stack_b == find_min_node(stack->stack_b))
	{
		push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
		ft_ra(stack);
		count_above_pivot--;
	}
	else if (stack->stack_b->content > pivot)
	{
		stack->stack_b->group_id = *group_id_max + 1;
		push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
		count_above_pivot--;
	}
	else
	{
		ft_rb(stack);
		count_stack_b_node++;
	}
	return (count_stack_b_node);
}

void	set_next_block2stack_b(t_lists *stack, int group_id, int *group_id_max)
{
	int			count_pb;
	int			min;
	t_cd_list	*tmp;

	min = INT_MAX;
	count_pb = 0;
	tmp = stack->stack_a;
	while (stack->stack_a->group_id == group_id + 1)
	{
		if (stack->stack_a->content < min)
			min = stack->stack_a->content;
		stack->stack_a = stack->stack_a->next;
	}
	stack->stack_a = tmp;
	while (stack->stack_a->group_id == group_id + 1)
		push_next_block(stack, &min, &count_pb);
	if (stack->stack_b != NULL)
		stack_b_quick_sort(count_pb, stack, group_id_max);
}

void	quick_sort(int av_num, t_lists *stack)
{
	int	max;

	max = 0;
	if (av_num < 11)
	{
		stack_a_insertion_sort(av_num, stack);
		return ;
	}
	stack_small_quick_sort(av_num, stack, &max);
	stack_large_quick_sort(av_num, stack, &max);
}
