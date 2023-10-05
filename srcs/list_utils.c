/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:03:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/05 20:09:19 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void clear_all_stack(t_lists *stack)
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
	op->prev = NULL;
	op->next = NULL;
	return (op);
}


static void delete_node(t_lists *stack)
{
	free(stack->instruction->operation);
	free(stack->instruction);
}

void	clear_all_instruction_list(t_lists *stack)
{
	t_instruction	*tmp;

	while (stack->instruction->prev != NULL)
		stack->instruction = stack->instruction->prev;
	while (stack->instruction != NULL)
	{
		tmp = stack->instruction->next;
		delete_node(stack);
		stack->instruction = tmp;
	}
}

void	pull_out_instruction(t_lists *stack)
{
	t_instruction *tmp_prev;
	t_instruction *tmp_next;

	tmp_next = stack->instruction->next;
	tmp_prev = stack->instruction->prev;
	delete_node(stack);
	if (tmp_prev != NULL)
	{
	stack->instruction = tmp_prev;
	stack->instruction->next = tmp_next;
	}
	if (tmp_next != NULL)
	{
	stack->instruction = tmp_next;
	stack->instruction->prev =tmp_prev;
	}
}

// void	optimize_instruction(t_lists *stack, int )

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

t_instruction	*add_instruction(t_lists *stack, t_operation op)
{
	t_instruction *add;

	if(stack->instruction == NULL)
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

void	make_instructin_list(t_lists *stack, t_operation op)
{
	t_instruction *op_node;
	t_instruction *first_op_node;

	op_node = new_instruction();
	if (op_node == NULL)
	{
		clear_all_instruction_list(stack);
		clear_all_stack(stack);
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
		op_node->prev = stack->instruction;
		stack->instruction = first_op_node;
	}
}

void	optimize_instruction(t_lists *stack)
{
	t_instruction *first;

	first = stack->instruction;
	// ft_printf("%s",stack->instruction->operation);
	while(stack->instruction != NULL)
	{
		if (stack->instruction->next && stack->instruction->next->next && stack->instruction->next->next->next)
		;
		else
		break;
		if(ft_strncmp(stack->instruction->next->operation, "ra\n", 3) == 0 && ft_strncmp(stack->instruction->next->next->operation ,"rb\n", 3) == 0)
		{
			add_instruction(stack, RR);
			stack->instruction =stack->instruction->next;
			pull_out_instruction(stack);
			pull_out_instruction(stack);
			continue;
		}
		if(ft_strncmp(stack->instruction->operation, "pb\n", 3) == 0 && ft_strncmp(stack->instruction->next->operation ,"pa\n", 3) == 0)
		{
			pull_out_instruction(stack);
			pull_out_instruction(stack);
			continue ;
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

//int main(void)
//{
	//t_lists stack;
	//// t_cd_list stack_a;
	//// t_cd_list stack_b;

	//stack.instruction = NULL;
	//// stack.stack_a = &stack_a;
	//// stack.stack_b = &stack_b;
	//ft_ra(&stack);
	//ft_rb(&stack);
	//ft_rr(&stack);
	//ft_rra(&stack);
	//ft_rrb(&stack);
	//ft_rrr(&stack);
	//ft_sa(&stack);
	//ft_sb(&stack);
	//ft_ss(&stack);

	//t_instruction *first = stack.instruction;
	//// while (stack.instruction->next != NULL)
	////  stack.instruction = stack.instruction->next;
	////for (int k = 0; k < 3; k++)
	////{
		////stack.instruction = stack.instruction->next;
	////}
	////add_instruction(&stack, RA);
	////pull_out_instruction(&stack);
	////add_instruction(&stack, RB);
	////pull_out_instruction(&stack);
	////add_instruction(&stack, RRA);
	////pull_out_instruction(&stack);
	////add_instruction(&stack, SA);
	////add_instruction(&stack, PB);
	//stack.instruction = first;

	//while (stack.instruction->next!= NULL)
	//{
		//ft_printf("%s",stack.instruction->operation);
		//stack.instruction = stack.instruction->next;
	//}
	//ft_printf("%s",stack.instruction->operation);
	//clear_all_instruction_list(&stack);
//}

//__attribute__((destructor))
//static void destructor() {
//system("leaks -q push_swap");
//}