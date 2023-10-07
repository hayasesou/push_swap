/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:02:51 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 18:03:34 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_push(t_lists *stack)
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
	while (stack->instruction != NULL && ft_strncmp(stack->instruction->operation, "pb\n",3)== 0)
	{
		pb_count++;
		stack->instruction = stack->instruction->next;
	}
	while (stack->instruction != NULL && ft_strncmp(stack->instruction->operation, "pa\n",3) == 0)
	{
		pa_count++;
		if (pa_count == pb_count)
			break ;
		stack->instruction =stack->instruction->next;
	}
	stack->instruction = tmp;
	if (pb_count > 0 && pa_count > 0)
	{
		while (i < pb_count - pa_count)
		{
			i++;
			stack->instruction = stack->instruction->next;
		}
		j = 2 * pa_count;
		while(j-- > 0)
			pull_out_instruction(stack);
	}
}