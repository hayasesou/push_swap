/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:03:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/04 22:30:53 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void clear_all_node(t_lists *stack)
{
	t_cd_list *tmp_a1;
	t_cd_list *tmp_a2;
	t_cd_list *tmp_b1;
	t_cd_list *tmp_b2;

	if (stack->stack_a != NULL)
	{
		tmp_a1 = stack->stack_a->prev;
		while (stack->stack_a != tmp_a1)
		{
			tmp_a2 = stack->stack_a->next;
			free(stack->stack_a);
			stack->stack_a = tmp_a2;
		}
		free(stack->stack_a);
	}
	if ( stack->stack_b != NULL)
	{
		tmp_b1 = stack->stack_b->prev;
		while (stack->stack_b != tmp_b1)
		{
			tmp_b2 = stack->stack_b->next;
			free(stack->stack_b);
			stack->stack_b = tmp_b2;
		}
		free(stack->stack_b);
	}
}
