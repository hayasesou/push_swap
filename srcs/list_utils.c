/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:03:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 17:34:17 by hfukushi         ###   ########.fr       */
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



void	make_instructin_list(t_lists *stack, t_operation op)
{
	t_instruction	*op_node;
	t_instruction	*first_op_node;

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
	{
		first_op_node = stack->instruction;
		while (stack->instruction->next != NULL)
			stack->instruction = stack->instruction->next;
		stack->instruction->next = op_node;
		op_node->prev = stack->instruction;
		stack->instruction = first_op_node;
	}
}


void	optimize_pxpb(t_lists *stack)
{
	t_instruction *tmp;
	int 			pb_count;
	int				pa_count;
	int				i;
	int				j;

	i = 0;
	j = -1;
	pb_count = 0;
	pa_count = 0;
	tmp = stack->instruction;
	while(stack->instruction != NULL && ft_strncmp(stack->instruction->operation, "pb\n",3)== 0)
	{
		pb_count++;
		stack->instruction = stack->instruction->next;
	}
	while(stack->instruction != NULL && ft_strncmp(stack->instruction->operation, "pa\n",3) == 0)
	{
		pa_count++;
		if (pa_count == pb_count)
			break;
		stack->instruction =stack->instruction->next;
	}
	stack->instruction = tmp;
	if (pb_count > 0 && pa_count > 0)
	{
		while(i < pb_count - pa_count)
		{
			i++;
			stack->instruction = stack->instruction->next;
		}
		j = 2 * pa_count;
		while( j-- > 0)
		pull_out_instruction(stack);
	}
}

void	optimize_instruction(t_lists *stack)
{
	t_instruction *first;

	first = stack->instruction;
	while(stack->instruction != NULL)
	{
		if (!(stack->instruction->next && stack->instruction->next->next && stack->instruction->next->next->next))
			break;

		optimize_pxpb(stack);

		if (!(stack->instruction->next && stack->instruction->next->next && stack->instruction->next->next->next))
			break;

		if(ft_strncmp(stack->instruction->next->operation, "ra\n", 3) == 0 && ft_strncmp(stack->instruction->next->next->operation ,"rb\n", 3) == 0)
		{
			add_instruction(stack, RR);
			stack->instruction =stack->instruction->next;
			pull_out_instruction(stack);
			pull_out_instruction(stack);
			continue;
		}
		if(ft_strncmp(stack->instruction->next->operation, "rb\n", 3) == 0 && ft_strncmp(stack->instruction->next->next->operation ,"pa\n", 3) == 0 && ft_strncmp(stack->instruction->next->next->next->operation ,"rrb\n", 3) == 0)
		{
			add_instruction(stack, SB);
			add_instruction(stack, PA);
			stack->instruction =stack->instruction->next;
			pull_out_instruction(stack);
			pull_out_instruction(stack);
			pull_out_instruction(stack);
			continue ;
		}
		stack->instruction = stack->instruction->next;
	}
	stack->instruction = first;
}
