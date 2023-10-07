/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:07:58 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 17:24:49 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	delete_instruction_node(t_lists *stack_x)
{
	free(stack_x->instruction->operation);
	free(stack_x->instruction);
}

void	clear_all_stack(t_lists *stack)
{
	t_cd_list	*tmp_1;
	t_cd_list	*tmp_2;

	if (stack->stack_a != NULL)
	{
		tmp_1 = stack->stack_a->prev;
		while (stack->stack_a != tmp_1)
		{
			tmp_2 = stack->stack_a->next;
			free(stack->stack_a);
			stack->stack_a = tmp_2;
		}
		free(stack->stack_a);
	}
	if (stack->stack_b != NULL)
	{
		tmp_1 = stack->stack_b->prev;
		while (stack->stack_b != tmp_1)
		{
			tmp_2 = stack->stack_b->next;
			free(stack->stack_b);
			stack->stack_b = tmp_2;
		}
		free(stack->stack_b);
	}
}

void	clear_all_instruction_list(t_lists *stack)
{
	t_instruction	*tmp;

	while (stack->instruction != NULL)
	{
		tmp = stack->instruction->next;
		delete_instruction_node(stack);
		stack->instruction = tmp;
	}
}

void	all_free(t_lists *stack)
{
	clear_all_instruction_list(stack);
	clear_all_stack(stack);
}
