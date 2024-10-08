/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:48:31 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 04:34:51 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	display_instruction(t_lists *stack)
{
	t_instruction	*first_instruction;

	first_instruction = stack->instruction;
	while (stack->instruction != NULL)
	{
		ft_printf("%s", stack->instruction->operation);
		stack->instruction = stack->instruction->next;
	}
	stack->instruction = first_instruction;
}
