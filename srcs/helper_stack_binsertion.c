/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_stack_binsertion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:38:31 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 02:17:31 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_minpluseone_next_min(t_lists *stack, t_stack_b_info *b_info)
{
	push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
	push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
	ft_ra(stack);
	ft_ra(stack);
	b_info->min += 2;
	b_info->min_plusone += 2;
	b_info->node_count -= 2;
}

void	current_maxminusone_next_max(t_lists *stack, t_stack_b_info *b_info)
{
	ft_sb(stack);
	push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
	push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
	b_info->max -= 2;
	b_info->max_minusone -= 2;
	b_info->node_count -= 2;
}

void	current_min_or_max_from_top(t_lists *stack, t_stack_b_info *b_info)
{
	if (stack->stack_b->content == b_info->min)
	{
		push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
		ft_ra(stack);
		b_info->min++;
		b_info->min_plusone++;
		b_info->node_count--;
	}
	else if (stack->stack_b->content == b_info->max)
	{
		push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
		b_info->max--;
		b_info->node_count--;
	}
}

void	from_bottom(t_lists *stack, t_distance distance, t_stack_b_info *b_info)
{
	while (stack->stack_b != distance.bottom_postion)
		ft_rrb(stack);
	if (stack->stack_b->content == b_info->min)
	{
		push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
		ft_ra(stack);
		b_info->min++;
		b_info->min_plusone++;
		b_info->node_count--;
	}
	else if (stack->stack_b->content == b_info->max)
	{
		push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
		b_info->max--;
		b_info->node_count--;
	}
}

void	from_top(t_lists *stack, t_distance *distance, t_stack_b_info *b_info)
{
	while (stack->stack_b != distance->top_position)
	{
		if (stack->stack_b->content == b_info->min_plusone
			&& stack->stack_b->next->content == b_info->min)
		{
			current_minpluseone_next_min(stack, b_info);
			break ;
		}
		else if (stack->stack_b->content == b_info->max_minusone
			&& stack->stack_b->next->content == b_info->max)
		{
			current_maxminusone_next_max(stack, b_info);
			break ;
		}
		ft_rb(stack);
	}
	current_min_or_max_from_top(stack, b_info);
}
