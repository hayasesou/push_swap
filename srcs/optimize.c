/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:02:51 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 22:01:40 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ex before:  pb pb pb pb pa pa
//   after :  pb pb
static void	delete_pbpa(int pb_count, int pa_count, t_lists *stack)
{
	int	distance_2_delete_pbpa;
	int	j;

	distance_2_delete_pbpa = 0;
	while (distance_2_delete_pbpa < pb_count - pa_count)
	{
		distance_2_delete_pbpa++;
		stack->instruction = stack->instruction->next;
	}
	j = 2 * pa_count;
	while (j-- > 0)
		pull_out_instruction(stack);
}

void	optimize_push(t_lists *stack)
{
	t_instruction	*tmp;
	int				pb_count;
	int				pa_count;

	pb_count = 0;
	pa_count = 0;
	tmp = stack->instruction;
	while (stack->instruction != NULL
		&& ft_strncmp(stack->instruction->operation, "pb\n", 3) == 0)
	{
		pb_count++;
		stack->instruction = stack->instruction->next;
	}
	while (stack->instruction != NULL
		&& ft_strncmp(stack->instruction->operation, "pa\n", 3) == 0)
	{
		pa_count++;
		if (pa_count == pb_count)
			break ;
		stack->instruction = stack->instruction->next;
	}
	stack->instruction = tmp;
	if (pb_count > 0 && pa_count > 0)
		delete_pbpa(pb_count, pa_count, stack);
}

// rb ra ->rr
static void	optimize_rarb(t_lists *stack)
{
	add_instruction(stack, RR);
	stack->instruction = stack->instruction->next;
	pull_out_instruction(stack);
	pull_out_instruction(stack);
}

//rb pa rrb -> sb pa
static void	optimize_rbparrb(t_lists *stack)
{
	add_instruction(stack, SB);
	add_instruction(stack, PA);
	stack->instruction = stack->instruction->next;
	pull_out_instruction(stack);
	pull_out_instruction(stack);
	pull_out_instruction(stack);
}

void	optimize_instruction(t_lists *stack)
{
	t_instruction	*first;

	first = stack->instruction;
	while (stack->instruction != NULL)
	{
		if (check_instruction(stack) == 0)
			break ;
		optimize_push(stack);
		if (check_instruction(stack) == 0)
			break ;
		if (check_instruction(stack) == 1)
		{
			optimize_rarb(stack);
			continue ;
		}
		if (check_instruction(stack) == 2)
		{
			optimize_rbparrb(stack);
			continue ;
		}
		stack->instruction = stack->instruction->next;
	}
	stack->instruction = first;
}
