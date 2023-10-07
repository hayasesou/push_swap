/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_set_next_block2stack_b.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:02:06 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 20:53:03 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void handle_min(t_lists *stack, int *min)
{
		if(stack->stack_a->content == *min)
		{
			ft_ra(stack);
			(*min) += 1;
		}
}

void	push_next_block(t_lists *stack, int *min, int *count_pb)
{

		if(stack->stack_a->content == *min)
		handle_min(stack, min);
		else
		{
		push_x2y(&(stack->stack_a), &(stack->stack_b), B, stack);
		(*count_pb)++;
		}
}
