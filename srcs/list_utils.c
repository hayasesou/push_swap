/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:03:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 18:33:47 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instruction	*new_instruction(void)
{
	t_instruction	*op;

	op = (t_instruction *)malloc(sizeof(t_instruction));
	if (op == NULL)
		return (NULL);
	op->prev = NULL;
	op->next = NULL;
	return (op);
}

void	set_operation(t_instruction *op_node, t_operation op)
{
	if (op == PA)
	op_node->operation = ft_strdup("pa\n");
	else if (op == PB)
	op_node->operation = ft_strdup("pb\n");
	else if (op == SA)
	op_node->operation = ft_strdup("sa\n");
	else if (op == SB)
	op_node->operation = ft_strdup("sb\n");
	else if (op == SS)
	op_node->operation = ft_strdup("ss\n");
	else if (op == RA)
	op_node->operation = ft_strdup("ra\n");
	else if (op == RB)
	op_node->operation = ft_strdup("rb\n");
	else if (op == RR)
	op_node->operation = ft_strdup("rr\n");
	else if (op == RRA)
	op_node->operation = ft_strdup("rra\n");
	else if (op == RRB)
	op_node->operation = ft_strdup("rrb\n");
	else if (op == RRR)
	op_node->operation = ft_strdup("rrr\n");
}

static void	add_back_instruction(t_instruction *op_node, t_lists *stack)
{
	t_instruction	*first_op_node;

	first_op_node = stack->instruction;
	while (stack->instruction->next != NULL)
		stack->instruction = stack->instruction->next;
	stack->instruction->next = op_node;
	op_node->prev = stack->instruction;
	stack->instruction = first_op_node;
}

void	make_instructin_list(t_lists *stack, t_operation op)
{
	t_instruction	*op_node;

	op_node = new_instruction();
	if (op_node == NULL)
	{
		all_free(stack);
		exit (1);
	}
	set_operation(op_node, op);
	if (op_node->operation == NULL)
	{
		free(op_node);
		all_free(stack);
		exit (1);
	}
	if (stack->instruction == NULL)
		stack->instruction = op_node;
	else
		add_back_instruction(op_node, stack);
}



