/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_in_stack_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:12:47 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/06 06:25:50 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void set_disatance(t_distance *distance, t_stack_b_info *b_info, t_cd_list **stack_b)
{
	int			i;
	t_cd_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = (*stack_b);
	distance->from_top = 0;
	distance->from_bottom = 0;
	i = 0;

	while (distance->from_top < b_info->node_count)
	{
		if ((*stack_b)->content == b_info->min || (*stack_b)->content == b_info->max)
		{
			distance->top_position = (*stack_b);
				break;
		}
		(*stack_b) = (*stack_b)->next;
		distance->from_top++;
	}
	(*stack_b) = tmp;
	i = 0;
	while (distance->from_bottom < b_info->node_count)
	{
		if ((*stack_b)->content == b_info->min || (*stack_b)->content == b_info->max)
		{
			distance->bottom_postion = (*stack_b);
			break;
		}
		(*stack_b) = (*stack_b)->prev;
		distance->from_bottom++;
	}
	(*stack_b) = tmp;
}

void	stack_b_insertion_sort(int number_count, t_lists *stack)
{
	t_stack_b_info b_info;
	t_distance distance;
	int i;

	b_info.max = INT_MIN;
	b_info.min = INT_MAX;
	i = -1;
	while(++i < number_count)
	{
		if (stack->stack_b->content < b_info.min)
		b_info.min = stack->stack_b->content;
		if (stack->stack_b->content > b_info.max)
		b_info.max = stack->stack_b->content;
		stack->stack_b = stack->stack_b->next;
	}
	b_info.min_plusone = b_info.min + 1;
	b_info.max_minusone = b_info.max - 1;

	b_info.node_count = number_count;
	while(stack->stack_b != NULL)
	{
	// b_info.node_count = number_count;
	set_disatance(&distance, &b_info, &(stack->stack_b));
		if(distance.from_top <= distance.from_bottom)
		{
			//while (stack->stack_b != distance.top_position)
			//{
				//ft_rb(stack);
			//}
			while (stack->stack_b != distance.top_position)
			{
				if (stack->stack_b->content == b_info.min_plusone && stack->stack_b->next->content == b_info.min )
				{
					push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
					push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
					ft_ra(stack);
					ft_ra(stack);
					b_info.min += 2;
					b_info.min_plusone +=2;
					b_info.node_count -= 2;
					break;
				}
				ft_rb(stack);
			}
			if (stack->stack_b->content == b_info.min)
			{
				push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
				ft_ra(stack);
				b_info.min++;
				b_info.min_plusone++;
				b_info.node_count--;
			}
			else if (stack->stack_b->content == b_info.max)
			{
				push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
				b_info.max--;
				b_info.node_count--;
			}
		}
		else
		{
			while (stack->stack_b != distance.bottom_postion)
				ft_rrb(stack);
			if (stack->stack_b->content == b_info.min)
			{
				push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
				ft_ra(stack);
				b_info.min++;
				b_info.min_plusone++;
				b_info.node_count--;
			}
			else
			{
				push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
				b_info.max--;
				b_info.node_count--;
			}
		}
	}
}