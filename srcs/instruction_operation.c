/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:30:21 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 17:33:19 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pull_out_instruction(t_lists *stack)
{
	t_instruction	*tmp_prev;
	t_instruction	*tmp_next;

	tmp_next = stack->instruction->next;
	tmp_prev = stack->instruction->prev;
	delete_instruction_node(stack);
	if (tmp_prev != NULL)
	{
	stack->instruction = tmp_prev;
	stack->instruction->next = tmp_next;
	}
	if (tmp_next != NULL)
	{
	stack->instruction = tmp_next;
	stack->instruction->prev = tmp_prev;
	}
}

t_instruction	*add_instruction(t_lists *stack, t_operation op)
{
	t_instruction	*add;

	if (stack->instruction == NULL)
		return (NULL);
	add = new_instruction();
	if (add == NULL)
		return (NULL);
	set_operation(add, op);
	add->next = stack->instruction->next;
	add->prev = stack->instruction;
	stack->instruction->next = add;
	stack->instruction = add->next;
	if (stack->instruction != NULL)
	{
	stack->instruction->prev = add;
	}
	stack->instruction = add;
	return (add);
}
