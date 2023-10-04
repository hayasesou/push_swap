/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:03:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/05 02:50:23 by hfukushi         ###   ########.fr       */
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
t_instruction *new_instruction(void)
{
	t_instruction *op;

	op = (t_instruction *)malloc(sizeof(t_instruction));
	if (op == NULL)
		return (NULL);
	op->next = NULL;
	return (op);
}

void	clear_all_instruction_list(t_lists *stack)
{
	t_instruction *tmp;

	while(stack->instruction != NULL)
	{
		tmp = stack->instruction->next;
		free(tmp);
		stack->instruction = tmp;
	}
}
void	set_operation(t_instruction *op_node, t_operation op)
{
	if(op == PA)
	op_node->operation = ft_strdup("pa\n");
	else if(op == PB)
	op_node->operation = ft_strdup("pb\n");
	else if(op == SA)
	op_node->operation = ft_strdup("sa\n");
	else if(op == SB)
	op_node->operation = ft_strdup("sb\n");
	else if(op == SS)
	op_node->operation = ft_strdup("ss\n");
	else if(op == RA)
	op_node->operation = ft_strdup("ra\n");
	else if(op == RB)
	op_node->operation = ft_strdup("rb\n");
	else if(op == RR)
	op_node->operation = ft_strdup("rr\n");
	else if(op == RRA)
	op_node->operation = ft_strdup("rra\n");
	else if(op == RRB)
	op_node->operation = ft_strdup("rrb\n");
	else if(op == RRR)
	op_node->operation = ft_strdup("rrr\n");
}


void	make_instructin_list(t_lists *stack, t_operation op)
{
	t_instruction *op_node;
	t_instruction *first_op_node;

	op_node = new_instruction();
	if (op_node == NULL)
	{
		clear_all_instruction_list(stack);
		clear_all_node(stack);
		exit (0);
	}
	set_operation(op_node, op);
	if (stack->instruction == NULL)
		stack->instruction = op_node;
	else
	{
		first_op_node = stack->instruction;
		while (stack->instruction->next != NULL)
			stack->instruction = stack->instruction->next;
		stack->instruction->next = op_node;
		stack->instruction = first_op_node;
	}
}

int main(void)
{
	t_lists stack;

	stack.instruction = NULL;
	make_instructin_list(&stack, PA);
	make_instructin_list(&stack, PB);
	make_instructin_list(&stack, RA);
	make_instructin_list(&stack, RB);
	make_instructin_list(&stack, RR);
	make_instructin_list(&stack, RRA);
	make_instructin_list(&stack, RRB);
	make_instructin_list(&stack, RRR);
	make_instructin_list(&stack, SA);
	make_instructin_list(&stack, SB);
	make_instructin_list(&stack, SS);
	while (stack.instruction != NULL)
	{
		ft_printf("%s",stack.instruction->operation);
		stack.instruction = stack.instruction->next;
	}
}