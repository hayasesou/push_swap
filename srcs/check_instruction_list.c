/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:10:47 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 22:01:03 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_instruction(t_lists *stack)
{
	if (!(stack->instruction->next && stack->instruction->next->next
			&& stack->instruction->next->next->next))
		return (0);
	if (ft_strncmp(stack->instruction->next->operation, "ra\n", 3) == 0
		&& ft_strncmp(stack->instruction->next->next->operation, "rb\n",
			3) == 0)
		return (1);
	if (ft_strncmp(stack->instruction->next->operation, "rb\n", 3) == 0
		&& ft_strncmp(stack->instruction->next->next->operation, "pa\n", 3) == 0
		&& ft_strncmp(stack->instruction->next->next->next->operation, "rrb\n",
			3) == 0)
		return (2);
	return (INT_MAX);
}
